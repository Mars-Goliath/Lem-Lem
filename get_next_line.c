/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlambert <mlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:34:06 by mlambert          #+#    #+#             */
/*   Updated: 2017/07/03 02:52:13 by mlambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static t_list		*ft_fd(t_list **lst, int fd)
{
	t_list *tmp;

	if ((tmp = *lst) != NULL)
	{
		while (tmp->next && (int)tmp->content_size != fd)
			tmp = tmp->next;
		if ((int)tmp->content_size == fd)
			return (tmp);
		if (!(tmp->next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		tmp = tmp->next;
		tmp->content_size = fd;
		tmp->content = NULL;
		tmp->next = NULL;
	}
	else
	{
		if (!(tmp = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		tmp->content_size = fd;
		tmp->content = NULL;
		tmp->next = NULL;
		*lst = tmp;
	}
	return (tmp);
}

static char			*cpy(t_list *tmp, char *buff, char *sub)
{
	long int	n;
	char		*tmp2;
	char		*line;

	line = NULL;
	n = sub - buff;
	if (tmp->content == NULL)
	{
		if (n < BUFF_SIZE)
			tmp->content = ft_strsub(buff, n + 1, BUFF_SIZE - n);
		return (ft_strndup(buff, n));
	}
	if (tmp->content != NULL && (sub = ft_strchr(tmp->content, '\n')))
	{
		n = sub - (char *)tmp->content;
		line = ft_strndup(tmp->content, n);
		tmp2 = tmp->content;
		tmp->content = ft_strsub(tmp2, n + 1, (ft_strlen(tmp2) - 1 - n));
		free(tmp2);
		return (line);
	}
	return (line);
}

static char			*ft_alljob(t_list *tmp, char *buff, char *sub, int ret)
{
	char		*line;
	long int	n;
	char		*tmp2;

	line = NULL;
	buff[ret] = '\0';
	tmp->content = tmp->content == NULL ? ft_strnew(0) : tmp->content;
	if ((sub = ft_strchr(buff, '\n')))
	{
		n = sub - buff;
		tmp2 = ft_strndup(buff, n);
		line = ft_strjoin(tmp->content, tmp2);
		free(tmp2);
		free(tmp->content);
		if (n < BUFF_SIZE)
			tmp->content = ft_strsub(buff, n + 1, BUFF_SIZE - n);
		return (line);
	}
	else
	{
		tmp2 = tmp->content;
		tmp->content = ft_strjoin(tmp->content, buff);
		free(tmp2);
	}
	return (line);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*lst = NULL;
	int				ret;
	t_list			*tmp;
	char			*sub;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || !(tmp = ft_fd(&lst, fd)))
		return (-1);
	if (tmp->content != NULL && (sub = ft_strchr(tmp->content, '\n')))
	{
		*line = cpy(tmp, buff, sub);
		return (1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) && ret > 0)
	{
		*line = ft_alljob(tmp, buff, sub, ret);
		if (*line != NULL)
			return (1);
	}
	if (tmp->content != NULL && (*line = ft_strdup(tmp->content)))
	{
		ft_memdel(&tmp->content);
		return (**line ? 1 : 0);
	}
	return (ret);
}
