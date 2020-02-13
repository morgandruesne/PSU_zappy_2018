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

void    InterfaceCore::EjectPlayerCommand(control_t *control)
{
    size_t i = 0;
    int PlayerNumber = 0;

    if (control->tbl.at(0).compare(0, 3, "pex") == 0) {
        strtok ((char *)control->tbl.at(0).c_str()," ");
        PlayerNumber = atoi(strtok (NULL," "));
        for (; i < this->players.size(); i++)
            if (this->players.at(i).getNumber() == PlayerNumber) {
                break;
            }
        this->players.erase(this->players.begin() + i);
    }
}