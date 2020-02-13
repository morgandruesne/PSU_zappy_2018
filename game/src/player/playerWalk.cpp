/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** playerWalk
*/

#include "player.hpp"

void Player::walkRight(void)
{
    sf::Vector2f pos = this->getPosition();

    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setPosition(sf::Vector2f(pos.x + 8, pos.y));
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress()) {
        case 1:
        case 5:
            this->setRect(sf::IntRect(48, 48, 48, 48));
            break;
        case 2:
        case 4:
            this->setRect(sf::IntRect(96, 48, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(144, 48, 48, 48));
            break;
    }
    if (this->getProgress() == 6)
        this->toIdle(true);
    this->clock.restart();
}

void Player::walkLeft(void)
{
    sf::Vector2f pos = this->getPosition();

    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setPosition(sf::Vector2f(pos.x - 8, pos.y));
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress()) {
        case 1:
        case 5:
            this->setRect(sf::IntRect(48, 0, 48, 48));
            break;
        case 2:
        case 4:
            this->setRect(sf::IntRect(96, 0, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(144, 0, 48, 48));
            break;
    }
    if (this->getProgress() == 6)
        this->toIdle(false);
    this->clock.restart();
}

void Player::walkUp(void)
{
    sf::Vector2f pos = this->getPosition();

    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setPosition(sf::Vector2f(pos.x, pos.y - 8));
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress()) {
        case 1:
        case 5:
            this->setRect(sf::IntRect(48, 0, 48, 48));
            break;
        case 2:
        case 4:
            this->setRect(sf::IntRect(96, 0, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(144, 0, 48, 48));
            break;
    }
    if (this->getProgress() == 6)
        this->toIdle(false);
    this->clock.restart();
}

void Player::walkDown(void)
{
    sf::Vector2f pos = this->getPosition();

    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setPosition(sf::Vector2f(pos.x, pos.y + 8));
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress()) {
        case 1:
        case 5:
            this->setRect(sf::IntRect(48, 48, 48, 48));
            break;
        case 2:
        case 4:
            this->setRect(sf::IntRect(96, 48, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(144, 48, 48, 48));
            break;
    }
    if (this->getProgress() == 6)
        this->toIdle(true);
    this->clock.restart();
}