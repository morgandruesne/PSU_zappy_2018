/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** main
*/

#include "../../include/server.h"

cmd_t cmds[21] = {
    {"Forward", &forward},
    {"Right", &right},
    {"Left", &left},
    {"Take", &take},
    {"Set", &set},
    {"Broadcast", &broadcast},
    {"Inventory", &inventory},
    {"Connect_nbr", &nbrc},
    {"Look", &look},
    {"msz", &msz},
    {"tna", &tna},
    {"bct", &bct},
    {"mct", &mct},
    {"pin", &pin},
    {"plv", &plv},
    {"ppo", &ppo},
    {"Incantation", &incantation},
    {"GOODBYE", byeserver},
    {"suicide", &death},
    {"Eject", &eject},
    {"Fork", &forkp},
};

current_t *try_exec_input(current_t *t, lst_t *target, char *str)
{
    char **tab = NULL;

    if ((tab = my_split(str, ' ')) == NULL) {
        ftab(tab);
        free(str);
        return (t);
    }
    for (int i = 0; i < 21; i++) {
        if (strcmp(tab[0], cmds[i].cmd) == 0) {
            t = cmds[i].func(t, target, tab);
            free(str);
            return (t);
        }
    }
    ftab(tab);
    free(str);
    dprintf(target->fd, "ko\n");
    return (t);
}

current_t *check_input(current_t *t, int fd, char *str)
{
    lst_t *target;

    target = get_lst_byfd(t->ser._fds, fd);
    if (str == NULL)
        return (delete_client(t, target));
    if (strcmp(str, "GRAPHIC") == 0) {
        if (t->ser._graphfd != -1) {
            dprintf(target->fd, "graphic already connected\n");
            return (t);
        } else {
            target->nb_team = -2;
            t->ser._graphfd = target->fd;
            return (send_info_to_graphic_connection(t, target));
        }
    }
    if (target->nb_team == -1)
        return (try_push_team(t, target, str));
    return (try_exec_input(t, target, str));
}

current_t *check_fd(current_t *t, int i, fd_set *fdread)
{
    int fd = 0;
    char *r = NULL;
    struct sockaddr_in tmp;
    socklen_t size_tmp = sizeof(tmp);

    if (FD_ISSET(i, fdread)) {
        if (i == t->ser._socket) {
            fd = accept(t->ser._socket, (struct sockaddr *)&tmp, &size_tmp);
            t->ser._fds = push_lst(t->ser._fds, create_lst(fd));
            dprintf(fd, "WELCOME\n");
        } else {
            r = get_next_line(i);
            t = check_input(t, i, r);
        }
    }
    return (t);
}