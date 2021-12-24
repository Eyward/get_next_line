/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 04:07:11 by zzirh             #+#    #+#             */
/*   Updated: 2021/12/16 04:07:27 by zzirh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	unsigned int	srcsize;
	unsigned int	i;

	srcsize = 0;
	i = 0;
	while (src[srcsize])
		srcsize++;
	if (size == 0)
	{
		return (srcsize);
	}
	else
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (srcsize);
	}	
}	

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	lns;
	unsigned int	lnd;
	unsigned int	sret;

	i = 0;
	lns = 0;
	lnd = 0;
	sret = 0;
	while (src[lns] != '\0')
		lns++;
	while (dest[lnd] != '\0')
		lnd++;
	if (size < lnd)
		sret = lns + size;
	else
		sret = lns + lnd;
	while ((src[i] != '\0') && (lnd + 1) < size)
	{
		dest[lnd] = src[i];
		lnd++;
		i++;
	}
	dest[lnd] = '\0';
	return (sret);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*resu;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	else if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	resu = (char *)malloc(sizeof(char) * len + 1);
	if (!resu)
		return (NULL);
	if (s1)
		ft_strlcpy(resu, s1, len + 1);
	ft_strlcat(resu, s2, len + 1);
	free(s1);
	return (resu);
}

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	if (s[i] == (char)c)
		return (s + i);
	return (NULL);
}
