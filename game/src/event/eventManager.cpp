/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** eventManager
*/

#include "interface.hpp"
#include "eventManager.hpp"

EventManager::EventManager(void) {
    (void)0;
}

void    applyCameraChange(InterfaceCore *core, sf::Vector2f vector)
{
    core->mainView.move(vector);
    core->window.setView(core->mainView);
}

void    EventManager::moveCamera(InterfaceCore *core) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        applyCameraChange(core, sf::Vector2f(24, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        applyCameraChange(core, sf::Vector2f(-24, 0));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        applyCameraChange(core, sf::Vector2f(0, 24));
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        applyCameraChange(core, sf::Vector2f(0, -24));
}

void    EventManager::manageEvents(InterfaceCore *core) {
    while (core->window.pollEvent(core->event)) {
        if (core->event.type == sf::Event::Closed)
            core->window.close();
        this->moveCamera(core);
    }
}
