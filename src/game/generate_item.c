/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** generate item
*/

#include "../../include/server.h"

void generate_item(int fd, map_t *m, clock_t *clgi)
{
    int x = rand() % m->x;
    int y = rand() % m->y;
    int nb_item = rand() % 7;

    m->tiles[x][y].inv.objects[nb_item].nb += 1;
    if (fd != -1)
        dprintf(fd, "gen %d %d %d\n", x, y, nb_item);
    printf("%d %d : %s += 1\n", x, y, m->tiles[x][y].inv.objects[nb_item].name);
    (*clgi) = clock();
}