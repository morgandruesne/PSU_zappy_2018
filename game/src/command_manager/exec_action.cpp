/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** main
*/

#include "interface.hpp"
#include "client.hpp"

void    InterfaceCore::exec_action(control_t *control)
{
    if (this->map->isInit() == false) {
        std::cout << "J'ai executer la commande : " << control->tbl.at(0);
        this->map_size_command(control);
        control->tbl.erase(control->tbl.begin());
    }
    if (control->tbl.size() > 0 && this->map->isInit() == true) {
        // std::cout << "J'ai executer la commande : " << control->tbl.at(0);
        this->new_player_command(control);
        this->move_player_command(control);
        this->EjectPlayerCommand(control);
        this->LevelUpCommand(control);
        this->PlayerDeathCommand(control);
        this->ContentilesCommand(control);
        control->tbl.erase(control->tbl.begin());
    }
}