/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** map
*/

#include "map.hpp"

Map::Map(void)
{
    this->init = false;
    this->cols = 0;
    this->rows = 0;
}

Map::Map(int cols, int rows)
{
    this->init = true;
    this->cols = cols;
    this->rows = rows;
    this->tiles = new Tile*[rows];
    for (int i = 0; i < rows; i++)
        this->tiles[i] = new Tile[cols];
}

int     Map::getHeight(void)
{
    return (this->rows);
}

int     Map::getWidth(void)
{
    return (this->cols);
}

bool    Map::isInit(void)
{
    return (this->init);
}

sf::Vector2f    Map::getVectorAt(int x, int y)
{
    return (sf::Vector2f(x * 48, y * 48));
}

Tile::Tile(void)
{
    for (int i = 0; i < 7; ++i)
        this->items[i] = 0;
}

void    Tile::setupTile(int items[7])
{
    for (int i = 0; i < 7; i++)
        this->items[i] = items[i];
}

void    Tile::add(int type, int quantity)
{
    this->items[type] += quantity;
}

void    Tile::remove(int type, int quantity)
{
    this->items[type] -= quantity;
}

void    Tile::set(int type, int quantity)
{
    this->items[type] = quantity;
}