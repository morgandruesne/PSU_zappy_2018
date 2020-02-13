/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** playerInteractions
*/

#include "player.hpp"

void Player::evolveAnimation(void)
{
    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress() % 4) {
        case 1:
            this->setRect(sf::IntRect(288, 96, 48, 48));
            break;
        case 2:
            this->setRect(sf::IntRect(288, 144, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(384, 96, 48, 48));
            break;
        case 0:
            this->setRect(sf::IntRect(384, 144, 48, 48));
            break;
    }
    if (this->getProgress() == 50)
        this->toIdle(true);
    this->clock.restart();
}

void Player::pickupAnimation(void)
{
    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress()) {
        case 1:
            this->setRect(sf::IntRect(240, 192, 48, 48));
            break;
        case 2:
            this->setRect(sf::IntRect(240, 240, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(240, 288, 48, 48));
            break;
        case 4:
            this->setRect(sf::IntRect(240, 336, 48, 48));
            break;
        case 5:
            this->setRect(sf::IntRect(480, 240, 48, 48));
            break;
    }
    if (this->getProgress() == 8)
        this->toIdle(true);
    this->clock.restart();
}

void Player::deathAnimation(void)
{
    int alpha = (this->getProgress() > 20) ? 0 : 255 - this->getProgress() * 10;

    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress() % 12) {
        case 1:
            this->setRect(sf::IntRect(528, 288, 48, 48));
            break;
        case 2:
            this->setRect(sf::IntRect(528, 336, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(528, 384, 48, 48));
            break;
        case 4:
            this->setRect(sf::IntRect(528, 432, 48, 48));
            break;
        case 5:
            this->setRect(sf::IntRect(528, 480, 48, 48));
            break;
        case 6:
            this->setRect(sf::IntRect(528, 528, 48, 48));
            break;
        case 7:
            this->setRect(sf::IntRect(384, 624, 48, 48));
            break;
        case 8:
            this->setRect(sf::IntRect(432, 624, 48, 48));
            break;
        case 9:
            this->setRect(sf::IntRect(480, 624, 48, 48));
            break;
    }
    this->player->setColor(sf::Color(255, 255, 255, alpha));
    this->death->setColor(sf::Color(255, 255, 255, alpha));
    this->clock.restart();
}

void    Player::talkAnimation(void)
{
    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress()) {
        case 1:
            this->setRect(sf::IntRect(384, 432, 48, 48));
            break;
        case 2:
            this->setRect(sf::IntRect(384, 528, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(384, 480, 48, 48));
            break;
        case 4:
            this->setRect(sf::IntRect(384, 576, 48, 48));
            break;
    }
    if (this->getProgress() == 5)
        this->toIdle(true);
    this->clock.restart();
}

void    Player::dropEggAnimation(void)
{
    if (this->clock.getElapsedTime().asMilliseconds() < 100)
        return;
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress()) {
        case 1:
            this->setRect(sf::IntRect(240, 48, 48, 48));
            break;
        case 2:
            this->setRect(sf::IntRect(288, 48, 48, 48));
            break;
        case 3:
            this->setRect(sf::IntRect(336, 96, 48, 48));
            break;
        case 4:
            this->setRect(sf::IntRect(336, 144, 48, 48));
            break;
        case 5:
            this->setRect(sf::IntRect(384, 624, 48, 48));
            break;
        case 6:
            this->setRect(sf::IntRect(432, 624, 48, 48));
            break;
        case 7:
            this->setRect(sf::IntRect(480, 624, 48, 48));
            break;
    }
    if (this->getProgress() == 9)
        this->toIdle(true);
    this->clock.restart();
}

void    Player::eggStateAnimation(void)
{
    if (this->clock.getElapsedTime().asMilliseconds() < 150)
        return;
    this->setProgress(this->getProgress() + 1);
    switch (this->getProgress() % 3) {
        case 1:
            this->setRect(sf::IntRect(384, 672, 48, 48));
            break;
        case 2:
            this->setRect(sf::IntRect(432, 672, 48, 48));
            break;
        case 0:
            this->setRect(sf::IntRect(480, 672, 48, 48));
            break;
    }
    this->clock.restart();
}