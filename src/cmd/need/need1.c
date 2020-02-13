/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** incantation cmd
*/

#include "../../../include/server.h"

int get_deraumere(int l)
{
    if (l == 2 || l == 4)
        return (0);
    if (l == 3 || l == 5)
        return (1);
    return (2);
}

int get_sibur(int l)
{
    if (l == 2)
        return (0);
    if (l == 3 || l == 4 || l == 6)
        return (1);
    if (l == 5 || l == 8)
        return (2);
    return (3);
}

int get_mendiane(int l)
{
    if (l == 6)
        return (3);
    if (l == 8)
        return (2);
    return (0);
}

int get_phiras(int l)
{
    if (l == 4 || l == 8)
        return (2);
    if (l == 5 || l == 7)
        return (1);
    return (0);
}

int get_thystame(int l)
{
    if (l == 8)
        return (1);
    return (0);
}