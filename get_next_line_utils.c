/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:02:43 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/11 01:49:01 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (unsigned char)c)
            return ((char *)s);
        s++;
    }
    if (c == '\0')
        return ((char *)s);
    return (NULL);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *result;
    size_t i;
    size_t n;
    size_t p;

    n = ft_strlen(s1) + ft_strlen(s2) + 1;
    i = 0;
    result = malloc(n);
    if (!result)
        return (NULL);
    while (i < n && s1[i] != '\0')
    {
        result[i] = s1[i];
        i++;
    }
    p = 0;
    while (i + p < n - 1)
    {
        result[i + p] = s2[p];
        p++;
    }
    result[i + p] = '\0';
    return (result);
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char *ptr_to_dest;
    const unsigned char *ptr_to_src;
    size_t i;

    i = 0;
    ptr_to_dest = (unsigned char *)dest;
    ptr_to_src = (const unsigned char *)src;
    while (i < n)
    {
        ptr_to_dest[i] = ptr_to_src[i];
        i++;
    }
    return (dest);
}
