/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** lib strcocat
*/

#include "../include/my.h"

int strl(char *str)
{
    int i = 0;

    if (str == NULL)
        return (i);
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *mstrconcat(char *dest, char *src, int f)
{
    char *r = NULL;
    int e = 0;

    r = malloc(sizeof(char) * (strl(dest) + strl(src) + 1));
    if (r == NULL)
        return (NULL);
    for (int i = 0; dest != NULL && dest[i] != '\0'; i++, e++)
        r[e] = dest[i];
    for (int i = 0; src != NULL && src[i] != '\0'; i++, e++)
        r[e] = src[i];
    r[e] = '\0';
    if (f == 0) {
        free(dest);
        free(src);
    }
    if (f == 1)
        free(dest);
    if (f == 2)
        free(src);
    return (r);
}