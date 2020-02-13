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

void    InterfaceCore::PlayerDeathCommand(control_t *control)
{
    size_t i = 0;
    int PlayerNb = 0;

    if (control->tbl.at(0).compare(0, 3, "pdi") == 0) {
        strtok ((char *)control->tbl.at(0).c_str()," ");
        PlayerNb = atoi(strtok (NULL," "));
        for (; i < this->players.size(); i++)
            if (this->players.at(i).getNumber() == PlayerNb)
                break;
        this->players.at(i).AddToQueue(DEATH);
    }
}