/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** broadcast cmd
*/

#include "../../../include/server.h"

int classic(player_t *un, player_t *deux)
{
    int x = un->x - deux->x;
    int y = un->y - deux->y;

    if (x > 0 && y > 0)
        return (4);
    if (x > 0 && y < 0)
        return (6);
    if (x < 0 && y > 0)
        return (2);
    if (x < 0 && y < 0)
        return (8);
    if (x > 0 && y == 0)
        return (5);
    if (x == 0 && y < 0)
        return (7);
    if (x < 0 && y == 0)
        return (1);
    if (x == 0 && y > 0)
        return (3);
    return (0);
}

int reverse_x(player_t *un, player_t *deux)
{
    int x = un->x - deux->x;
    int y = un->y - deux->y;

    if (x > 0 && y > 0)
        return (2);
    if (x > 0 && y < 0)
        return (8);
    if (x < 0 && y > 0)
        return (4);
    if (x < 0 && y < 0)
        return (6);
    if (x > 0 && y == 0)
        return (1);
    if (x == 0 && y < 0)
        return (7);
    if (x < 0 && y == 0)
        return (5);
    if (x == 0 && y > 0)
        return (3);
    return (0);
}

int reverse_y(player_t *un, player_t *deux)
{
    int x = un->x - deux->x;
    int y = un->y - deux->y;

    if (x > 0 && y > 0)
        return (6);
    if (x > 0 && y < 0)
        return (4);
    if (x < 0 && y > 0)
        return (8);
    if (x < 0 && y < 0)
        return (2);
    if (x > 0 && y == 0)
        return (5);
    if (x == 0 && y < 0)
        return (3);
    if (x < 0 && y == 0)
        return (1);
    if (x == 0 && y > 0)
        return (7);
    return (0);
}

int reverse_xy(player_t *un, player_t *deux)
{
    int x = un->x - deux->x;
    int y = un->y - deux->y;

    if (x > 0 && y > 0)
        return (8);
    if (x > 0 && y < 0)
        return (2);
    if (x < 0 && y > 0)
        return (6);
    if (x < 0 && y < 0)
        return (4);
    if (x > 0 && y == 0)
        return (1);
    if (x == 0 && y < 0)
        return (3);
    if (x < 0 && y == 0)
        return (5);
    if (x == 0 && y > 0)
        return (7);
    return (0);
}