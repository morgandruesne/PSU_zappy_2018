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

void    InterfaceCore::LevelUpCommand(control_t *control)
{
    size_t i = 0;
    int PosX = 0;
    int PosY = 0;

    if (control->tbl.at(0).compare(0, 3, "pie") == 0) {
        strtok ((char *)control->tbl.at(0).c_str()," ");
        PosX = atoi(strtok (NULL," "));
        PosY = atoi(strtok (NULL," "));
        for (; i < this->players.size(); i++)
            if (this->players.at(i).getStateposx() == PosX
            && this->players.at(i).getStateposy() == PosY) {
                this->players.at(i).AddToQueue(EVOLUTION);
            }
    }
}