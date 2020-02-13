/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** create inv
*/

#include "../../include/server.h"

void print_inv(inv_t t)
{
    for (int i = 0; i < 7; i++) {
        printf("%s : %d\n", t.objects[i].name, t.objects[i].nb);
    }
}

void display_inv(int fd, inv_t i, int x, int y)
{
    print_inv(i);
    dprintf(fd, "bct %d %d %d %d %d %d %d %d %d\n", x, y, i.objects[0].nb,
    i.objects[1].nb, i.objects[2].nb, i.objects[3].nb, i.objects[4].nb,
    i.objects[5].nb, i.objects[6].nb);
}

int get_inv_byn(char *name)
{
    int e = -1;
    char *tab[] = {"food", "linemate", "deraumere", "sibur", "mendiane",
    "phiras", "thystame"};

    for (int i = 0; i < 7; i++) {
        if (strcmp(name, tab[i]) == 0) {
            e = i;
            return (e);
        }
    }
    return (e);
}

inv_t create_inv_int(int opt)
{
    inv_t t;
    char *tab[] = {"food", "linemate", "deraumere", "sibur", "mendiane",
    "phiras", "thystame"};

    t.objects = malloc(sizeof(ob_t) * 7);
    for (int i = 0; i < 7; i++)
        t.objects[i] = create_ob(tab[i], opt);
    return (t);
}

inv_t create_inv(void)
{
    inv_t t;
    char *tab[] = {"food", "linemate", "deraumere", "sibur", "mendiane",
    "phiras", "thystame"};

    t.objects = malloc(sizeof(ob_t) * 7);
    for (int i = 0; i < 7; i++)
        t.objects[i] = create_ob(tab[i], 1);
    return (t);
}