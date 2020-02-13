/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** port_handling
*/

#include "../include/includes.h"

int my_strisnum(char *av)
{
    if (av == NULL)
        return (-1);
    for (int i = 0; av[i] != '\0'; i++) {
        if (!(av[i] >= '0' && av[i] <= '9'))
            return (-1);
    }
    return (0);
}