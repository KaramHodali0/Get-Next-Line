/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 18:10:54 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/11 01:49:26 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <stddef.h>

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

#if BUFFER_SIZE < 0
#undef BUFFER_SIZE
#define BUFFER_SIZE 0
#endif

#include <stdlib.h>
#include <unistd.h>

char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *s, int c);
char *get_next_line(int fd);
void *ft_memcpy(void *dest, const void *src, size_t n);
#endif