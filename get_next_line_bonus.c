/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 04:06:24 by zzirh             #+#    #+#             */
/*   Updated: 2021/12/24 17:47:00 by zzirh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*readl(int fd, char *stmp)
{
	ssize_t	nb;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nb = 1;
	while (!ft_strchr(stmp, '\n') && nb != 0)
	{
		nb = read(fd, buff, BUFFER_SIZE);
		if (nb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[nb] = '\0';
		stmp = ft_strjoin(stmp, buff);
	}
	free(buff);
	return (stmp);
}

char	*ft_line(char *stmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!stmp[i])
		return (NULL);
	while (stmp[i] && stmp[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stmp[i] && stmp[i] != '\n')
	{
		line[i] = stmp[i];
		i++;
	}
	if (stmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_rest(char *stmp)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (stmp[i] && stmp[i] != '\n')
		i++;
	if (!stmp[i])
	{
		free(stmp);
		return (NULL);
	}
	i++;
	new = (char *)malloc(sizeof(char) * ft_strlen(stmp) - i + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (stmp[i])
	{
		new[j++] = stmp[i++];
	}
	new[j] = '\0';
	free(stmp);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stmp[1024];

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	stmp[fd] = readl(fd, stmp[fd]);
	if (!stmp[fd])
		return (NULL);
	line = ft_line(stmp[fd]);
	stmp[fd] = ft_rest(stmp[fd]);
	return (line);
}
