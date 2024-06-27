/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 23:57:27 by aadamik           #+#    #+#             */
/*   Updated: 2024/05/09 18:07:44 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../printf/libft/libft.h"

char	*get_line1(char *str, int i);
char	*get_str(char *str, int fd);
char	*update_str(char *str);
char	*get_next_line(int fd);
// int		ft_strlen(char *s);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strchr(char *s, int c);
// void	*ft_calloc(int n, int size);

#endif