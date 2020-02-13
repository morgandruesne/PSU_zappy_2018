/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Description.
*/

#include "../include/my.h"

int    slen(char *str)
{
    int i = -1;

    if (!str)
        return (0);
    while (str[++i] != '\0');
    return (i);
}

char    *strcgnl(char *str, char *add, int opt)
{
    int len_str = slen(str);
    int len_add = slen(add);
    int e = 0;
    char *new;

    new = malloc(sizeof(char) * (len_str + len_add +1));
    new[len_str + len_add] = '\0';
    for (int i = 0; i < len_str; i++, e++)
        new[e] = str[i];
    for (int i = 0; i < len_add; i++, e++)
        new[e] = add[i];
    if (opt == 1 && str != NULL)
        free(str);
    return (new);
}

int    backsn(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0') {
        if (str[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}

char    *do_the_res(char *tmp, char (*buf)[READ_SIZE +1], int ind)
{
    char *res = NULL;
    int i = 0;
    int e = 0;
    int f = 0;

    res = malloc(sizeof(char) * (ind +1));
    if (!res)
        return (NULL);
    while (tmp[i] != '\n') {
        res[i] = tmp[i];
        i++;
    }
    res[i] = '\0';
    for (; (*buf)[e] != '\0' && (*buf)[e] != '\n'; e++);
    for (;(*buf)[f + (e +1)] != '\0'; f++)
        (*buf)[f] = (*buf)[f + (e +1)];
    (*buf)[f] = '\0';
    free(tmp);
    return (res);
}

char    *get_next_line(int fd)
{
    static char buf[READ_SIZE +1];
    char *res = NULL;
    char *tmp = NULL;
    int n = 1;
    int indn = -1;

    tmp = strcgnl(tmp, buf, 1);
    while (fd != -1 && n > 0) {
        indn = backsn(tmp);
        if (indn != -1) {
            return ((res = do_the_res(tmp, &buf, indn)));
        }
        n = read(fd, buf, READ_SIZE);
        buf[n] = '\0';
        tmp = strcgnl(tmp, buf, 1);

    }
    if (tmp != NULL)
        free(tmp);
    return (NULL);
}