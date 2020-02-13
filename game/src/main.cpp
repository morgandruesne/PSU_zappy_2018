/*
** EPITECH PROJECT, 2019
** zappy
** File description:
** main
*/

#include "interface.hpp"
#include "event/eventManager.hpp"
#include "player/player.hpp"
#include "client.hpp"

struct thread_info {
    pthread_t   thread_id;
    int         thread_num;
    char        *argv_string;
};

void game(control_t *control, InterfaceCore *core)
{
    EventManager    *event = new EventManager();

    srand(time(NULL));
    while (core->window.isOpen()) {
        event->manageEvents(core);
        core->window.clear();
        if (core->map->isInit() == true)
            core->drawMap();
        for (size_t i = 0; i < core->players.size(); i++)
            core->players.at(i).ExecQueue();
        for (size_t i = 0; i < core->players.size(); i++)
            core->players.at(i).anime();
        for (size_t i = 0; i < core->players.size(); i++)
            core->drawPlayer(core->players.at(i));
        if (rand() % 10000 + 1 < 5)
            write(control->socket_fd, "mct\n", strlen("mct\n"));
        core->window.display();
        core->exec_action(control);
    }
    write(control->socket_fd, "GOODBYE\n", strlen("GOODBYE\n"));
}

int main(int ac, char *av[])
{
    InterfaceCore   *core = new InterfaceCore();
    control_t control;
    std::string data;

    create_socket(&control, av[1], av[2]);
    write(control.socket_fd, "GRAPHIC\n", strlen("GRAPHIC\n"));
    std::thread t1(server_read, &control);
    std::thread t2(game, &control, core);
    t1.join();
    t2.join();
    return (0);
}