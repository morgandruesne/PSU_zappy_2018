/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** error_handling
*/

#include "../../include/server.h"

int help_option(void)
{
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1");
    printf(" name2 ... -c clientsNb -f freq\n");
    printf("\tport\t\tis the port number\n");
    printf("\twidth\t\tis the width of the world\n");
    printf("\theight\t\tis the height of the world\n");
    printf("\tnameX\t\tis the name of the team X\n");
    printf("\tclientsNb\tis the number of authorized clients per team\n");
    printf("\tfreq\t\tis the reciprocal of time unit for execution");
    printf(" of actions\n");
    return (1);
}

void create_teams(current_t **t, int ac, char **av, char **team_names)
{
    team_names = save_names(ac, av, optind, team_names);
    (*t)->teams = malloc(sizeof(team_t) * ltab(team_names));
    (*t)->nbts = ltab(team_names);
    for (int i = 0; team_names[i] != NULL; i++) {
        (*t)->teams[i].name = strdup(team_names[i]);
        (*t)->teams[i].nb = (*t)->nbc;
        (*t)->teams[i].players = NULL;
        (*t)->teams[i].clients = malloc(sizeof(int) * (*t)->teams[i].nb);
        for (int e = 0; e < (*t)->teams[i].nb; e++)
            (*t)->teams[i].clients[e] = -1;
    }
}