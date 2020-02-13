/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** main
*/

#include "interface.hpp"
#include "../event/eventManager.hpp"
#include "../player/player.hpp"
#include "client.hpp"

void    InterfaceCore::ContentilesCommand(control_t *control)
{
    size_t i = 0;
    int PosX = 0;
    int PosY = 0;
    int items[7];

    if (control->tbl.at(0).compare(0, 3, "bct") == 0) {
        strtok ((char *)control->tbl.at(0).c_str()," ");
        PosX = atoi(strtok (NULL," "));
        PosY = atoi(strtok (NULL," "));
        items[0] = atoi(strtok (NULL," "));
        items[1] = atoi(strtok (NULL," "));
        items[2] = atoi(strtok (NULL," "));
        items[3] = atoi(strtok (NULL," "));
        items[4] = atoi(strtok (NULL," "));
        items[5] = atoi(strtok (NULL," "));
        items[6] = atoi(strtok (NULL," "));
        this->map->tiles[PosX][PosY].setupTile(items);
    }
}