/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <SFML/Graphics.hpp>

#define     FOOD        0
#define     LINEMATE    1
#define     DERAUMERE   2
#define     SIBUR       3
#define     MENDIANE    4
#define     PHIRAS      5
#define     THYSTAME    6

#define     Q0          0
#define     Q1          1
#define     Q2          2
#define     Q3          3
#define     Q4          4
#define     Q5          5
#define     Q6          6

class Tile {
    public:
        Tile();
        void    setupTile(int items[7]);
        void    add(int type, int quantity);
        void    remove(int type, int quantity);
        void    set(int type, int quantity);

        int     items[7];
    private:
};

class Map {
    public:
        Map();
        Map(int cols, int rows);
        int             getHeight(void);
        int             getWidth(void);
        bool            isInit(void);
        sf::Vector2f    getVectorAt(int x, int y);
        Tile    **tiles;

    private:
        bool     init;
        int     rows;
        int     cols;
};

#endif /* !MAP_HPP_ */
