/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:39:51 by aadamik           #+#    #+#             */
/*   Updated: 2024/04/05 19:02:18 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	int		j;
// 	char	*s1s2;

// 	s1s2 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (s1s2 == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		s1s2[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 	{
// 		s1s2[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	s1s2[i] = '\0';
// 	return (s1s2);
// }

// char	*ft_strchr(char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0' && s[i] != (char)c)
// 	{
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 	{
// 		return (&s[i]);
// 	}
// 	return (NULL);
// }

// void	*ft_calloc(int n, int size)
// {
// 	void	*ptr;
// 	int		i;

// 	ptr = NULL;
// 	ptr = malloc(n * size);
// 	if (!ptr)
// 		return (NULL);
// 	i = 0;
// 	while (i < (n * size))
// 	{
// 		((char *)ptr)[i] = '\0';
// 		i++;
// 	}
// 	return (ptr);
// }
