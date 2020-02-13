/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** error_handling
*/

#include "../../include/server.h"

char **save_names(int ac, char **av, int optind, char **team_names)
{
    int team_index = 1;

    if (optind < ac) {
        while (optind < ac)
            team_names[team_index++] = strdup(av[optind++]);
        team_names[team_index] = NULL;
    }
    return (team_names);
}

int opt_switch(int c, int *f, char **team_names, current_t **t)
{
    switch (c) {
    case 'p':
        (*t)->ser._port = atoi(optarg);
        break;
    case 'x':
        (*t)->map.x = atoi(optarg);
        break;
    case 'y':
        (*t)->map.y = atoi(optarg);
        break;
    case 'n':
        team_names[(*f)] = strdup(optarg);
        team_names[++(*f)] = NULL;
        break;
    case 'c':
        (*t)->nbc = atoi(optarg);
        break;
    case 'f':
        (*t)->ser._freq = atoi(optarg);
        break;
    case '?':
        return (help_option());
    }
    return (0);
}

static struct option long_options[] =
{
    {"port", required_argument, 0, 'p'},
    {"width", required_argument, 0, 'x'},
    {"height", required_argument, 0, 'y'},
    {"name", required_argument, 0, 'n'},
    {"clientNb", required_argument, 0, 'c'},
    {"freq", required_argument, 0, 'f'},
    {0, 0, 0, 0}
};

int args_handeling(int ac, char **av, current_t **t)
{
    int c;
    int d = 0;
    int option_index = 0;
    char **team_names = malloc(sizeof(char *) * ac);

    while (1) {
        c = getopt_long(ac, av, "p:x:y:n:c:f:", long_options, &option_index);
        if (c == -1)
            break;
        if (opt_switch(c, &d, team_names, t) == 1)
            return (1);
    }
    create_teams(t, ac, av, team_names);
    return (0);
}

int error_handling(int ac, char **av, current_t **t)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return (help_option());
    return (args_handeling(ac, av, t));
}