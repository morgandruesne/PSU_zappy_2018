/*
** EPITECH PROJECT, 2019
** myFTP
** File description:
** slit
*/

#include "../include/includes.h"

void stab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        printf("[%d] : [%s]\n", i, tab[i]);
}

void ftab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void nbw(char *str, int *nb, char sep)
{
    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (str[i] == sep)
            (*nb)++;
        while (str[i] == sep && str[i + 1] != '\0')
            i++;
    }
}

int ltab(char **tab)
{
    int len = 0;

    for (int i = 0; tab != NULL && tab[i] != NULL; i++)
        len++;
    return (len);
}

char **my_split(char *this, char separator)
{
    char **res;
    int nb = 1;
    int e = 0;
    int i = 0;
    int n = 0;
    int f = 0;

    nbw(this, &nb, separator);
    res = malloc(sizeof(char *) * (nb + 1));
    for (; i < nb; i++, f++) {
        for (;this[f] == separator && this[f] == '\0'; f++);
        for (n = f; this[n] != separator && this[n] != '\0'; n++);
        res[i] = malloc(sizeof(char) * ((n - f) + 1));
        for (; this[f] != separator && this[f] != '\0'; f++, e++)
            res[i][e] = this[f];
        res[i][e] = '\0';
        e = 0;
    }
    res[i] = NULL;
    return (res);
}