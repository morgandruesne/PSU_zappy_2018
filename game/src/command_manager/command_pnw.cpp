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

void    InterfaceCore::new_player_command(control_t *control)
{
    Player player(this, 0);
    int PosX = 0;
    int PosY = 0;

    if (control->tbl.at(0).compare(0, 3, "pnw") == 0) {
        strtok ((char *)control->tbl.at(0).c_str()," ");
        player.setNumber(atoi(strtok (NULL," ")));
        PosX = atoi(strtok (NULL," ")); 
        PosY = atoi(strtok (NULL," "));
        player.setStatepos(PosX, PosY);
        player.setPosition(this->map->getVectorAt(PosX, PosY));
        this->players.push_back(player);
    }
}