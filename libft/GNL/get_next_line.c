/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckenaip <ckenaip@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:58:57 by ckenaip           #+#    #+#             */
/*   Updated: 2024/01/17 10:50:32 by ckenaip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Cette fonction doit lire ligne par ligne
 * Return la ligne lu
 * Return Null si 
 * 	plus de ligne a lire
 * 	une erreur apparait
 * Et continu de ligne en ligne apres indication, jusqu'a la fin
 */

/* READ (ssize_t read(int fd, void *buf, size_t count);)
 * renvoie -1 s'il echoue, sinon le nombre d'octects lu
 */

ssize_t	ft_strlen_gnl(char *str)
{
	ssize_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// Verifie la presence de \n in slash ET si bytes_read == 0
// 74 = \n

int	found_newline(char *tab, ssize_t bytes_read)
{
	int	i;

	i = 0;
	if (bytes_read <= 0)
		return (1);
	if (!tab)
		return (0);
	while (tab[i])
	{
		if (tab[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// Transfere tout le buffer dans stash

char	*buf_to_stash(char *buf, char *stash, ssize_t bytes_read)
{
	ssize_t	i;
	ssize_t	y;

	i = 0;
	y = 0;
	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * (bytes_read + 1));
		if (!stash)
			return (NULL);
		stash[bytes_read] = '\0';
	}
	else
	{
		y = ft_strlen(stash);
		stash = ft_realloc(stash, bytes_read + y + 1);
	}
	while (i < bytes_read)
	{
		stash[y + i] = buf[i];
		i++;
	}
	stash[y + i] = '\0';
	return (stash);
}

// Clear stash, malloc line, return line

char	*ft_line(char *line, char *stash)
{
	ssize_t	i;
	ssize_t	y;
	ssize_t	len;

	if (!stash || ft_strlen(stash) == 0)
		return (NULL);
	i = 0;
	len = ft_nstrlen(stash);
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	y = 0;
	while (stash[i + y])
	{
		stash[y] = stash[i + y];
		y++;
	}
	stash[y] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static void	*buffer[BUFFER_SIZE];
	char		*line;
	ssize_t		bytes_read;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	line = NULL;
	bytes_read = 1;
	while (!found_newline(stash, bytes_read))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read)
			stash = buf_to_stash((char *)buffer, stash, bytes_read);
	}
	line = ft_line(line, stash);
	if (!line)
		free(stash);
	return (line);
}
/*
int	main(void)
{
	//int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	//fd = open("justeN", O_RDWR);
	//fd = open("alter_line_nl", O_RDWR);
	//fd = open("big_with_nl", O_RDWR);
	//fd = open("with_no_nl", O_RDWR);
	//fd = open("text.log", O_RDWR);
	while (1)
	{
		line = get_next_line(0);
		printf("line = %s", line); //PRINT
		i++;
		if (line == NULL)
		{
			free(line);
			break ;
		}
		free(line);
	}
	//close(fd);
	return (0);
}*/
