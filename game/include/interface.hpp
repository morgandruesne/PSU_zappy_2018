/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** interface
*/

#ifndef INTERFACE_HPP_
#define INTERFACE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <vector>
#include "../src/player/player.hpp"
#include "../include/client.hpp"
#include "../src/map/map.hpp"

#define     SPRITE_PLAYER       0
#define     SPRITE_HAND         1
#define     SPRITE_DEATH        2
#define     SPRITE_EVOLUTION    3
#define     SPRITE_PICKUP       4
#define     SPRITE_INDICATOR    5
#define     SPRITE_TALK         6
#define     SPRITE_LOVE         7
#define     SPRITE_SAND         8
#define     SPRITE_FOOD         9
#define     SPRITE_LINEMATE     10
#define     SPRITE_DERAUMERE    11
#define     SPRITE_SIBUR        12
#define     SPRITE_MENDIANE     13
#define     SPRITE_PHIRAS       14
#define     SPRITE_THYSTAME     15

class Player;
class Map;

class InterfaceCore {
    public:
        InterfaceCore(void);
        ~InterfaceCore(void);
        InterfaceCore(const InterfaceCore&);
        void            addSprite(sf::Texture *texture, sf::IntRect rect);
        void            addTexture(std::string path);
        sf::Sprite      getSprite(int position);
        sf::Texture     *getTexture(int position);
        void            exec_action(control_t *control);
        void            new_player_command(control_t *control);
        void            map_size_command(control_t *control);
        void            move_player_command(control_t *control);
        void            EjectPlayerCommand(control_t *control);
        void            LevelUpCommand(control_t *control);
        void            PlayerDeathCommand(control_t *control);
        void            ContentilesCommand(control_t *control);
        void            ColectCommand(control_t *control);
        void            drawPlayer(Player player);
        void            drawMap(void);
        void            drawTile(int x, int y);
        void            drawFood(int x, int y);

        sf::RenderWindow    window;
        sf::Event           event;
        std::vector<Player> players;
        Map                 *map;
        sf::View            mainView;
    private:
        std::vector<sf::Sprite*> sprites;
        std::vector<sf::Texture*> textures;
};

void    create_socket(control_t *control, char *ip, char *port);


#endif /* !INTERFACE_HPP_ */
