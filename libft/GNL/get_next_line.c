/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:58:57 by ckenaip           #+#    #+#             */
/*   Updated: 2025/02/19 14:02:15 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_save(char *line)
{
	char	*saved;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
	{
		free(line);
		return (NULL);
	}
	saved = ft_substr(line, i + 1, ft_strlen(line) - i);
	free(line);
	return (saved);
}

static char	*ft_line(int fd, char *buffer, char *save)
{
	int		byte_read;
	char	*temp;

	byte_read = 1;
	while (byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (NULL);
		else if (byte_read == 0)
			break ;
		buffer[byte_read] = '\0';
		if (!save)
			save = ft_strdup("");
		if (!save)
			return (NULL);
		temp = ft_strjoin(save, buffer);
		if (!temp)
			return (free(save), NULL);
		free(save);
		save = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*buffer;
	char		*line;
	char		*new_save;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(save), save = NULL, NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_line(fd, buffer, save);
	free(buffer);
	if (!line)
		return (NULL);
	new_save = ft_save(line);
	save = new_save;
	return (line);
}
