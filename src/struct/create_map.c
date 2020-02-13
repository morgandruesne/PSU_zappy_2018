/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** create_map
*/

#include "../../include/server.h"

map_t create_map(int x, int y)
{
    map_t t;

    t.x = x;
    t.y = y;
    t.tiles = malloc(sizeof(tile_t *) * t.x);
    for (int i = 0; i < t.x; i++) {
        t.tiles[i] = malloc(sizeof(tile_t) * t.y);
        for (int j = 0; j < t.y; j++) {
            t.tiles[i][j].inv = create_inv_int(0);
            t.tiles[i][j].nb_players = 0;
        }
    }
    t.eggs = NULL;
    return (t);
}