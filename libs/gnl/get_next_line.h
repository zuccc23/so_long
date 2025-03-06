/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:25:15 by dahmane           #+#    #+#             */
/*   Updated: 2025/03/06 12:54:36 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h> 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strlen_after_line(char *str);
int		ft_strlen_before_line(char *str);
char	*ft_strdup2(char *src);
char	*ft_strjoin(char const *s1, char const *s2);
int		check(char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

char	*get_next_line(int fd);
char	*read_line(char *temp, int fd);

#endif
