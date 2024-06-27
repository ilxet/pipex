/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadamik <aadamik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:01:20 by aadamik           #+#    #+#             */
/*   Updated: 2024/04/06 14:41:17 by aadamik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_str(char *str, int fd)
{
	int		bytes_read;
	char	*buf;
	char	*tmp;

	bytes_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(str), NULL);
	while (bytes_read > 0 && !ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(str), free(buf), NULL);
		buf[bytes_read] = '\0';
		tmp = ft_strjoin(str, buf);
		if (!tmp)
			return (free(str), free(buf), NULL);
		free(str);
		str = tmp;
	}
	return (free(buf), str);
}

char	*get_line1(char *str, int i)
{
	char	*line;

	if (!str[i])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_str(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
		return (free(str), NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
	{
		new_str[j] = str[i];
		i++;
		j++;
	}
	new_str[j] = '\0';
	return (free(str), new_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!str)
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
	}
	tmp = get_str(str, fd);
	if (!tmp)
		return (str = NULL, NULL);
	str = tmp;
	line = get_line1(str, 0);
	if (!line)
		return (free(str), str = NULL, NULL);
	tmp = update_str(str);
	if (!tmp)
		str = NULL;
	str = tmp;
	return (line);
}

// int main()
// {
// 	int fd;
// 	char *line;
// 	int i;

// 	i = 0;
// 	fd = open("test.ber", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("%d->%s\n", i, line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }