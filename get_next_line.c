/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhouda <kalhouda@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 01:26:23 by kalhouda          #+#    #+#             */
/*   Updated: 2026/10/11 02:02:13 by kalhouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *Read_Add_To_Stash(int fd, char *stash)
{
    char *buffer;
    ssize_t bytes_read;

    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
    {
        free(stash);
        return (NULL);
    }
    while (!(ft_strchr(stash, '\n')))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
            return (free(buffer), free(stash), NULL);
        if (bytes_read == 0)
            break;
        buffer[bytes_read] = '\0';
        stash = ft_strjoin(stash, buffer);
    }
    free(buffer);
    return (stash);
}

static char *extract_line(char *stash)
{
    char *res;
    int i;

    i = 0;
    if (!stash)
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    i += (stash[i] == '\n');
    res = malloc(i + 1);
    if (!res)
    {
        free(stash);
        return (NULL);
    }
    ft_memcpy(res, stash, i);
    res[i] = '\0';
    return (res);
}

char *update_stash(char *stash)
{
    size_t i;
    size_t j;
    size_t index_first_newline;
    char *new_stash;

    index_first_newline = 0;
    i = 0;
    j = 0;
    while (stash[i] != '\n' && stash[i])
        i++;
    if (stash[i] == '\n')
        i++;
    index_first_newline = i;
    if (stash[i] == '\0')
        return (free(stash), NULL);
    while (stash[i] != '\n' && stash[i] != '\0')
    {
        i++;
        j++;
    }
    new_stash = malloc(j + 1);
    if (!new_stash)
        return (free(stash), NULL);

    ft_memcpy(new_stash, stash + index_first_newline, j);
    new_stash[j] = '\0';
    free(stash);
    return (new_stash);
}

char *has_newline(char *stash)
{
    char *str_after_newline;
    size_t i;
    size_t j;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] != '\n' || stash[i + 1] == '\0')
        return (NULL);
    i++;
    while (stash[i + j])
        j++;
    str_after_newline = malloc(j + 1);
    if (!str_after_newline)
        return (NULL);
    ft_memcpy(str_after_newline, stash + i, j);
    str_after_newline[j] = '\0';
    return (str_after_newline);
}

char *get_next_line(int fd)
{
    static char *buffer;

    static char *stash; /* تحتوي على البيانات التي قرأتها ولم تُرجعها بعد

    // ... rest of the function

buffer
المكان الذي تضع فيه البيانات التي قرأتها للتو باستخدام read().

saved أو stash
البيانات التي تحتفظ بها بين الاستدعاءات، حتى لا تفقد أي bytes لم تُرجعها بعد.


line
الـ string التي ستُرجعها الدالة للمستخدم في هذا الاستدعاء.

    */
}

/*
1. has_newline(): انتبه إلى أنها تُرجع NULL إذا لم يوجد محتوى بعد \n، وكذلك إذا لم يوجد \n أصلًا. هاتان حالتان مختلفتان منطقيًا، رغم أنهما تعيدان القيمة نفسها.
2. get_next_line(): الدالة غير مكتملة حاليًا، لذلك لا يمكنني الحكم على ترتيب استدعاء الدوال أو إدارة الـ stash بين الاستدعاءات.
ملاحظة مهمة: لديك أيضًا static char *buffer; وstatic char *stash;، لكن buffer داخل Read_Add_To_Stash() متغير محلي منفصل. لا تحتاج إلى جعل buffer داخل get_next_line() متغيرًا static إذا كنت ستستخدمه فقط لتخزين البيانات المقروءة مؤقتًا.
*/