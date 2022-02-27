/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amounach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:44:51 by amounach          #+#    #+#             */
/*   Updated: 2022/02/27 17:46:47 by amounach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H



# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(int fd, char *buffer);
char	*get_line(char	*buffer);
char	*ft_rest(char *buffer);
char	*get_next_line(int fd);

#endif
