/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** interface
*/

#include "interface.hpp"

InterfaceCore::InterfaceCore(void) {
    this->window.create(sf::VideoMode(1024, 768), "Zappy");
    this->textures.reserve(32);
    this->addTexture("assets/player.png");
    this->addTexture("assets/hand.png");
    this->addTexture("assets/death.png");
    this->addTexture("assets/evolution.png");
    this->addTexture("assets/pickup.png");
    this->addTexture("assets/indicator.png");
    this->addTexture("assets/talk.png");
    this->addTexture("assets/love.png");
    this->addTexture("assets/map/sand.png");
    this->addTexture("assets/map/melon.png");
    this->addTexture("assets/map/linemate.png");
    this->addTexture("assets/map/deraumere.png");
    this->addTexture("assets/map/sibur.png");
    this->addTexture("assets/map/mendiane.png");
    this->addTexture("assets/map/phiras.png");
    this->addTexture("assets/map/thystame.png");
    this->addSprite(this->getTexture(SPRITE_PLAYER), sf::IntRect(0, 0, 48, 48));
    this->addSprite(this->getTexture(SPRITE_HAND), sf::IntRect(0, 0, 16, 16));
    this->addSprite(this->getTexture(SPRITE_DEATH), sf::IntRect(0, 0, 32, 32));
    this->addSprite(this->getTexture(SPRITE_EVOLUTION),sf::IntRect(0, 0, 32, 32));
    this->addSprite(this->getTexture(SPRITE_PICKUP), sf::IntRect(0, 0, 32, 32));
    this->addSprite(this->getTexture(SPRITE_INDICATOR), sf::IntRect(0, 0, 32, 32));
    this->addSprite(this->getTexture(SPRITE_TALK), sf::IntRect(0, 0, 32, 32));
    this->addSprite(this->getTexture(SPRITE_LOVE), sf::IntRect(0, 0, 32, 32));
    this->addSprite(this->getTexture(SPRITE_SAND), sf::IntRect(0, 0, 16, 16));
    this->addSprite(this->getTexture(SPRITE_FOOD), sf::IntRect(0, 0, 16, 16));
    this->addSprite(this->getTexture(SPRITE_LINEMATE), sf::IntRect(0, 0, 16, 16));
    this->addSprite(this->getTexture(SPRITE_DERAUMERE), sf::IntRect(0, 0, 16, 16));
    this->addSprite(this->getTexture(SPRITE_SIBUR), sf::IntRect(0, 0, 16, 16));
    this->addSprite(this->getTexture(SPRITE_MENDIANE), sf::IntRect(0, 0, 16, 16));
    this->addSprite(this->getTexture(SPRITE_PHIRAS), sf::IntRect(0, 0, 16, 16));
    this->addSprite(this->getTexture(SPRITE_THYSTAME), sf::IntRect(0, 0, 16, 16));
    this->map = new Map;
    this->mainView = sf::View(sf::Vector2f(1, 1), sf::Vector2f(1024, 768));
    this->window.setView(this->mainView);
}

InterfaceCore::~InterfaceCore(void) {}

InterfaceCore::InterfaceCore(const InterfaceCore&) {}

void    InterfaceCore::addTexture(std::string path) {
    sf::Texture texture;

    texture.loadFromFile(path);
    this->textures.push_back(new sf::Texture(texture));
}

void    InterfaceCore::addSprite(sf::Texture *texture, sf::IntRect rect) {
    sf::Sprite sprite;

    sprite.setTexture(*texture);
    sprite.setTextureRect(rect);
    sprite.setPosition(sf::Vector2f(0, 0));
    this->sprites.push_back(new sf::Sprite(sprite));
}

sf::Sprite    InterfaceCore::getSprite(int position) {
    return (*(this->sprites[position]));
}

sf::Texture     *InterfaceCore::getTexture(int position) {
    return (this->textures[position]);
}

void    InterfaceCore::drawPlayer(Player player)
{
    switch (player.getState()) {
        case IDLE:
        case WALK_DOWN:
        case WALK_UP:
        case WALK_RIGHT:
        case WALK_LEFT:
            this->window.draw(player.getIndicatorSprite());
            break;
        case PICKUP:
            this->window.draw(player.getPickupSprite());
            break;
        case EVOLUTION:
            this->window.draw(player.getEvolutionSprite());
            break;
        case DEATH:
            this->window.draw(player.getDeathSprite());
            break;
        case TALK:
            this->window.draw(player.getTalkSprite());
            break;
        case DROP_EGG:
            this->window.draw(player.getLoveSprite());
            break;
        case EGG_STATE:
            this->window.draw(player.getTalkSprite());
    }
    this->window.draw(player.getPlayerSprite());
}

void    InterfaceCore::drawTile(int x, int y)
{
    for (int i = 0; i <= 32; i += 16) {
        for (int j = 0; j <= 32; j += 16) {
            this->sprites[SPRITE_SAND]->setPosition(x * 48 + j, y * 48 + i);
            this->window.draw(this->getSprite(SPRITE_SAND));
        }
    }
}

void    InterfaceCore::drawFood(int x, int y)
{
    for (int i = 0; i < 7; i++) {
        if (this->map->tiles[x][y].items[i] > 0)
            this->sprites[i + 9]->setPosition(x * 48 + 7 + i * 3, y * 48 + 16);
            this->window.draw(this->getSprite(i + 9));
    }
}

void    InterfaceCore::drawMap(void)
{
    int height = this->map->getHeight();
    int width = this->map->getWidth();

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            this->drawTile(j, i);
            this->drawFood(j, i);
        }
}