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

void InterfaceCore::move_player_command(control_t *control)
{
    int player_number = 0;
    size_t i = 0;
    int newposx = 0;
    int newposy = 0;

    if (control->tbl.at(0).compare(0, 3, "ppo") == 0) {
        strtok ((char *)control->tbl.at(0).c_str()," ");
        player_number = atoi(strtok (NULL," "));
        newposx = atoi(strtok (NULL," "));
        newposy = atoi(strtok (NULL," "));
        for (; i < this->players.size(); i++)
            if (this->players.at(i).getNumber() == player_number) {
                break;
            }
        if (((this->players.at(i).getStateposy() - newposy)) > 1
        || ((this->players.at(i).getStateposy() - newposy)) < -1
        || ((this->players.at(i).getStateposx() - newposx)) > 1
        || ((this->players.at(i).getStateposx() - newposx)) < -1) {
            this->players.at(i).setPosition(this->map->getVectorAt(newposx, newposy));
        }
        else {
            if (this->players.at(i).getStateposy() < newposy)
                this->players.at(i).AddToQueue(WALK_DOWN);
            if (this->players.at(i).getStateposy() > newposy)
                this->players.at(i).AddToQueue(WALK_UP);
            if (this->players.at(i).getStateposx() < newposx)
                this->players.at(i).AddToQueue(WALK_RIGHT);
            if (this->players.at(i).getStateposx() > newposx)
                this->players.at(i).AddToQueue(WALK_LEFT);
        }
        this->players.at(i).setStatepos(newposx, newposy);
    }
}