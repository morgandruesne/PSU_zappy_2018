/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** eventManager
*/

#ifndef EVENTMANAGER_HPP_
#define EVENTMANAGER_HPP_

#include "interface.hpp"
#include <iostream>
#include <vector>

class EventManager {
    public:
        EventManager(void);
        void    manageEvents(InterfaceCore *core);
        void    moveCamera(InterfaceCore *core);
    private:
        std::vector<int> eventStack;
};


#endif /* !EVENTMANAGER_HPP_ */
