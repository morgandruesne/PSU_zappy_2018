/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** lib
*/

#ifndef LIB_H
# define LIB_H

#include "includes.h"
# define READ_SIZE (5)

int my_strisnum(char *av);
char    *get_next_line(int fd);

char **my_split(char *this, char separator);
int ltab(char **tab);
void ftab(char **tab);
void stab(char **tab);
char *mstrconcat(char *dest, char *src, int f);
int my_intl(int e);

#endif