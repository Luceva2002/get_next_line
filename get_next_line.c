/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luevange <luevange@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:24:05 by luevange          #+#    #+#             */
/*   Updated: 2025/03/06 13:08:43 by luevange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* funzione che legge BUFFER_SIZE */

/* funzione che cerca \n e va alla prossima riga */

/* gnl: controlla buffer,decide s leggere nuovi dati, estrarre la linea e
// returno line;

aggiorna il buffer */

// controllo se buffer esiste *
// controllo newline se c'e fai questo:
// salvo la stringa con extract line;
// aggiorno i buffer;
// returno;
// se non c'e newline;
// while (non c'e newline nel buffer)
// {
// leggo i prossimi byte;
// strjoin con i nuovi byte ed il buffer
// }
// salvo la stringa con extract line;
// aggiorno i buffer;

void	update_line(char *stash)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	while (stash[i] != '\0')
	{
		stash[j] = stash[i];
		j++;
		i++;
	}
	while (stash[j])
	{
		stash[j] = '\0';
		j++;
	}
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, stash, i + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*line;
	static char	stash[BUFFER_SIZE + 1];
	int			bytes_read;

	line = NULL;
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (ft_strchar(stash, '\n'))
		{
			str = extract_line(stash);
			line = ft_strjoin(line, str);
			free(str);
			update_line(stash);
			return (line);
		}
		line = ft_strjoin(line, stash);
		update_line(stash);
		bytes_read = read(fd, stash, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (ft_strlen(line) == 0)
				return (NULL);
			return (line);
		}
		if (bytes_read < 0)
			return (NULL);
	}
}

/* int	main(void)
{
	int fd;
	int i = 15;
	char *line;
	fd = open("test.txt", O_RDONLY);
	while (i)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i--;
	}
} */