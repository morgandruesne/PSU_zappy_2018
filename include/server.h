/*
** EPITECH PROJECT, 2019
** Zappy_Server
** File description:
** server
*/

#ifndef SERVER_H
# define SERVER_H

#include "includes.h"
#include "my.h"

typedef struct lst_s {
    int fd;
    int nb_team;
    int lifes;
    struct lst_s *n;
} lst_t;

typedef struct egg_s {
    int nb_team;
    int nb;
    int time;
    int nbc;
    int x;
    int y;
    struct egg_s *n;
} egg_t;

typedef struct ob_s {
    char *name;
    int nb;
} ob_t;

typedef struct inv_s {
    ob_t *objects;
} inv_t;

typedef struct tile_s {
    inv_t inv;
    int nb_players;
} tile_t;

typedef struct player_s {
    int x;
    int y;
    int level;
    int master;
    int r;
    int nb;
    int lifes;
    inv_t inv;
    int st;
    struct player_s *n;
} player_t;

typedef struct map_s {
    int x;
    int y;
    tile_t **tiles;
    egg_t *eggs;
} map_t;

typedef struct team_s {
    char *name;
    char nb;
    int *clients;
    player_t *players;
} team_t;

typedef struct server_s {
    int _socket;
    struct sockaddr_in _sckk;
    socklen_t _sckk_size;
    int _port;
    int _freq;
    int _graphfd;
    lst_t *_fds;
} server_t;

typedef struct current_s {
    server_t ser;
    map_t map;
    team_t *teams;
    int nbts;
    int nbc;
} current_t;

typedef struct cmd_s {
    char *cmd;
    current_t *(*func)(current_t *l, lst_t *target, char **cmd);
} cmd_t;


/* tmp */
void print_inv(inv_t t);

/* error_handling */
int port_handling(char *opt, char *value);
int width_handling(char *opt, char *value);
int height_handling(char *opt, char *value);
int error_handling(int ac, char **av, current_t **t);
int freq_handling(char *opt, char *value);
int client_handling(char *opt, char *value);
void create_teams(current_t **t, int ac, char **av, char **team_names);
int help_option(void);
char **save_names(int ac, char **av, int optind, char **team_names);
int check_current(current_t *t);

/* my returns */
void exit_p(current_t *t, char *msg, int r, int fd);
int return_p(current_t *t, char *msg, int r, int fd);
int return_m(char *msg, int r, int fd);

/* struct */
map_t create_map(int x, int y);
current_t *create_current(void);
lst_t *create_lst(int fd);
lst_t *push_lst(lst_t *list, lst_t *t);
ob_t create_ob(char *name, int nb);
inv_t create_inv(void);
inv_t create_inv_int(int opt);
player_t *create_player(int fd/*, int ind*/);
player_t *push_player(player_t *list, player_t *t);
egg_t *create_egg(int nbteam);

egg_t *push_egg(egg_t *list, egg_t *t);
void delete_egg(egg_t *list);
egg_t *delete_egg_node(egg_t *list, egg_t *l);

lst_t *get_lst_byfd(lst_t *lst, int fd);
player_t *get_player_byfd(player_t *lst, int fd);
int get_inv_byn(char *name);
char get_player_rby(player_t *t);
player_t *get_player_bynbp(player_t *lst, int fd);

void delete_current(current_t *t);
void delete_team(team_t *t);
void delete_lst(lst_t *list);
lst_t *delete_lst_node(lst_t *list, lst_t *l);
void delete_ob(ob_t ob);
void delete_player(player_t *list);
player_t *delete_player_node(player_t *list, player_t *l);

void print_lst(lst_t *l);

/* server */
int initiation_server(server_t *t);
void fd_set_clients(lst_t *list, fd_set *w);
current_t *try_push_team(current_t *t, lst_t *target, char *str);
current_t *server_cycle(current_t *t);
current_t *check_fd(current_t *t, int i, fd_set *fdread);

current_t *delete_client(current_t *t, lst_t *target);

/* team */
int *add_client_toteam(int *clients, int fdc, int size);
int get_team_nbp(int *players, int size);
int get_team_byname(current_t *t, char *str);

int *supr_client_toteam(int *clients, int fdc, int size);

/* cmd */
current_t *right(current_t *t, lst_t *target, char **cmd);
current_t *left(current_t *t, lst_t *target, char **cmd);
current_t *take(current_t *t, lst_t *target, char **cmd);
current_t *msz(current_t *t, lst_t *target, char **cmd);
current_t *tna(current_t *t, lst_t *target, char **cmd);
current_t *bct(current_t *t, lst_t *target, char **cmd);
current_t *mct(current_t *t, lst_t *target, char **cmd);
current_t *pin(current_t *t, lst_t *target, char **cmd);
current_t *plv(current_t *t, lst_t *target, char **cmd);
current_t *ppo(current_t *t, lst_t *target, char **cmd);
current_t *set(current_t *t, lst_t *target, char **cmd);
current_t *broadcast(current_t *t, lst_t *target, char **cmd);
current_t *inventory(current_t *t, lst_t *target, char **cmd);
current_t *nbrc(current_t *t, lst_t *target, char **cmd);
current_t *forward(current_t *t, lst_t *target, char **cmd);
current_t *look(current_t *t, lst_t *target, char **cmd);
current_t *incantation(current_t *t, lst_t *target, char **cmd);
current_t *death(current_t *t, lst_t *c, char **cmd);
current_t *byeserver(current_t *t, lst_t *target, char **cmd);
current_t *eject(current_t *t, lst_t *target, char **cmd);
current_t *forkp(current_t *t, lst_t *tar, char **cmd);
player_t *ppo_forward(current_t *t, player_t *p);

/* need */
int get_deraumere(int l);
int get_sibur(int l);
int get_mendiane(int l);
int get_phiras(int l);
int get_thystame(int l);
int get_linemate(int l);
int get_player(int l);
current_t *error_inc(current_t *t, int fd, char **cmd, inv_t *inv);

/* send */
current_t *pnw(current_t *t, lst_t *target);
current_t *pgt(current_t *t, lst_t *target, int e);
current_t *pdr(current_t *t, lst_t *target, int e);
current_t *pbc(current_t *t, lst_t *target, char *str);
current_t *pic(current_t *t, player_t *target);
current_t *pie(current_t *t, player_t *p, int r);
current_t *seg(current_t *t);
current_t *enw(current_t *t, lst_t *tar, egg_t *egg);
current_t *eht(current_t *t, egg_t *egg);
current_t *send_info_to_graphic_connection(current_t *t, lst_t *target);


int classic(player_t *un, player_t *deux);
int reverse_x(player_t *un, player_t *deux);
int reverse_y(player_t *un, player_t *deux);
int reverse_xy(player_t *un, player_t *deux);
int version_one(player_t *un, player_t *deux, map_t *m);
int version_two(player_t *un, player_t *deux, map_t *m);
int version_three(player_t *un, player_t *deux, map_t *m);
int version_four(player_t *un, player_t *deux, map_t *m);

/* tools */
double arx(double x, double y, int r);
double ary(double x, double y, int r);
int ajust_x(int x, int sx);
int ajust_y(int x, int sx);
int know_move(int r);
char *add_case_space(char *str, int i, int j, int nb);
current_t *print_ko(current_t *t, int fd, char **cmd);
current_t *up_all_player_concern(current_t *t, player_t *p);
int check_end(current_t *t);
void generate_item(int fd, map_t *m, clock_t *clgi);
struct timeval create_tv(void);
current_t *error_incd(current_t *t, int fd, char **cmd, inv_t *inv);

/* display */
void display_inv(int fd, inv_t i, int x, int y);

#endif