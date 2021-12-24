/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzirh <zzirh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 04:06:51 by zzirh             #+#    #+#             */
/*   Updated: 2021/12/16 04:15:59 by zzirh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif
//# include<string.h>
size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dest, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char	*src);
char	*ft_strchr(char *s, int c);
char	*readl(int fd, char *stmp);
char	*ft_line(char *stmp);
char	*ft_rest(char *stmp);
char	*get_next_line(int fd);

#endif
