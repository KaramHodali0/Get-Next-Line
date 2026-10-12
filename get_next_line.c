/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 11:22:52 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/12 15:06:18 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_both(char *a, char *b)
{
	free(a);
	free(b);
	return (NULL);
}

static char	*read_to_stash(int fd, char *stash)
{
	char	*new;
	char	*buffer;
	ssize_t	how_many_time_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(stash), NULL);
	stash = init_stash(stash);
	if (!stash)
		return (free(buffer), NULL);
	how_many_time_read = 1;
	while (!ft_strchr(stash, '\n') && how_many_time_read > 0)
	{
		how_many_time_read = read(fd, buffer, BUFFER_SIZE);
		if (how_many_time_read < 0)
			return (free_both(buffer, stash), stash = NULL, NULL);
		buffer[how_many_time_read] = '\0';
		new = ft_strjoin(stash, buffer);
		free(stash);
		stash = new;
		if (!new)
			return (free(buffer), NULL);
	}
	return (free(buffer), stash);
}

static char	*extract_line(char *stash)
{
	char	*str_before_newline;
	int		i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	str_before_newline = malloc(i + 1);
	if (!str_before_newline)
		return (NULL);
	ft_memcpy(str_before_newline, stash, i);
	if (!str_before_newline)
		return (NULL);
	str_before_newline[i] = '\0';
	return (str_before_newline);
}

static char	*update_stash(char *stash)
{
	char	*str_after_newline;
	int		i;
	int		j;
	int		index_letter_after_newline;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), NULL);
	index_letter_after_newline = i + 1;
	j = 0;
	while (stash[index_letter_after_newline + j])
		j++;
	str_after_newline = malloc(j + 1);
	if (!str_after_newline)
		return (free(stash), NULL);
	ft_memcpy(str_after_newline, stash + index_letter_after_newline, j);
	str_after_newline[j] = '\0';
	free(stash);
	return (str_after_newline);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = update_stash(stash);
	return (line);
}
