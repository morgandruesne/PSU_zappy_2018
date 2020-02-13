/*
** EPITECH PROJECT, 2018
** NWP_client_ftp
** File description:
** client.c
*/

#include "client.hpp"

void    create_socket(control_t *control, char *ip, char *port)
{

    control->socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    control->addr.sin_family = AF_INET;
    control->addr.sin_port = htons(atoi(port));
    inet_pton(AF_INET, ip, &control->addr.sin_addr);
    control->ip = strdup(ip);
    connect(control->socket_fd, (struct sockaddr *)&control->addr, sizeof(control->addr));
}

int main(int ac, char *av[])
{
    control_t control;
    std::string data;

    if (ac != 3)
        return (84);
    create_socket(&control, av[1], av[2]);
    write(control.socket_fd, "GRAPHIC\n", strlen("GRAPHIC\n"));
    write(control.socket_fd, "msz\n", 4);
    while (1) {
        std::cout << server_read(&control);
    }
    return (0);
}
