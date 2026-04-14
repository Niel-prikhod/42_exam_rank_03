/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dprikhod <dprikhod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:00:31 by dprikhod          #+#    #+#             */
/*   Updated: 2026/02/27 23:28:52 by dprikhod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name   : get_next_line
Expected files    : get_next_line.c get_next_line.h
Allowed functions : read, free, malloc
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

static size_t	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		i = 0;

	len1 = 0;
	len2 = 0;
	if (s1)
		len1 = ft_strlen(s1);
	if (s2)
		len2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (len1 + len2));
	if (!res)
		return (NULL);
	while (i < len1)
	{
		res[i] = s1[i];
		i++;
	}
	while (i - len1 < len2)
	{
		res[i] = s2[i - len1];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*set_buf_for_future(char *buf)
{
	char	*res;
	char	*tmp;

	if (!buf)
		return (NULL);
	tmp = ft_strchr(buf, '\n');
	if (!tmp)
		return (NULL);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*res;
	size_t		size;

	if (fd < 0)
		return (NULL);
	while (!ft_strchr(buf, '\n') && *buf)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
			return (buf = NULL);
		size = read(fd, &buf, BUFFER_SIZE);
		if (!size)
			break ;
	}
	return (res);
}
