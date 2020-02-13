/*
** EPITECH PROJECT, 2018
** NWP_client_ftp
** File description:
** client.c
*/

#include "client.hpp"
#include "interface.hpp"

void    create_socket(control_t *control, char *ip, char *port)
{
    control->socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    control->addr.sin_family = AF_INET;
    control->addr.sin_port = htons(atoi(port));
    inet_pton(AF_INET, ip, &control->addr.sin_addr);
    control->ip = strdup(ip);
    connect(control->socket_fd, (struct sockaddr *)&control->addr,
    sizeof(control->addr));
}

int linked_command(control_t *control) {
    std::string responce = "";
    char buffer[1] = {0};
    int ret = 1;

    while (responce.back() != '\n') {
        ret = read(control->socket_fd, buffer, 1);
        responce += buffer;
        if (ret <= 0) {
            write(2, "Error\n", 6);
            return (1);
        }
    }
    if (responce == "BYE\n")
        return (1);
    control->tbl.push_back(responce);
    return (0);
}

void *server_read(control_t *control)
{
    for (;linked_command(control) == 0;);
    return (NULL);
}
