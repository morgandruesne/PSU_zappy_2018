/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** look tool
*/

#include "../../include/server.h"
#include <math.h>

double arx(double x, double y, int r)
{
    double nr = (double)r;
    nr = (nr / 30) * 90;
    nr = nr * M_PI / 180.0;
    nr *= -1;

    return ((x * cos(nr)) - (y * sin(nr)));
}

double ary(double x, double y, int r)
{
    double nr = (double)r;
    nr = (nr / 30) * 90;
    nr = nr * M_PI / 180.0;
    nr *= -1;

    return ((x * sin(nr)) + (y * cos(nr)));
}

char *add_case_space(char *str, int i, int j, int nb)
{
    if (!(i == 6 && (nb != 0 && j == nb - 1)))
        str = mstrconcat(str, " ", 1);
    return (str);
}