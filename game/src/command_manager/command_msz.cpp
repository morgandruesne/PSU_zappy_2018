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

void    InterfaceCore::map_size_command(control_t *control)
{
    if (control->tbl.at(0).compare(0, 3, "msz") == 0) {
        strtok ((char *)control->tbl.at(0).c_str()," ");
        this->map = new Map(atoi(strtok(NULL," ")), atoi(strtok(NULL," ")));
        std::cout << "MAP -> Y : " << this->map->getHeight() << " X : " << this->map->getWidth() << std::endl;
        this->mainView.setCenter(sf::Vector2f(
            ((this->map->getWidth() * 48) / 2),
            ((this->map->getHeight() * 48) / 2)
        ));
        this->window.setView(this->mainView);
    }
}