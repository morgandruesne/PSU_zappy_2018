/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** playerAnimation
*/

#include "player.hpp"

void Player::toIdle(bool lookRight) {
    this->setState(IDLE);
    this->setProgress(0);
    if (lookRight == true) {
        this->setRect(sf::IntRect(0, 48, 48, 48));
    } else {
        this->setRect(sf::IntRect(0, 0, 48, 48));
    }
}

void    Player::emojiAnimation(sf::Sprite *emojiSprite)
{
    sf::Vector2f pos = this->getPosition();

    emojiSprite->setPosition(sf::Vector2f(pos.x + 8, pos.y - 32));
    if (this->clockEmoji.getElapsedTime().asMilliseconds() < 150)
        return;
    if (this->getEmojiFrame() == 3)
        this->setEmojiFrame(0);
    this->setEmojiFrame(this->getEmojiFrame() + 1);
    switch (this->getEmojiFrame()) {
        case 1:
            emojiSprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
            break;
        case 2:
            emojiSprite->setTextureRect(sf::IntRect(32, 0, 32, 32));
            break;
        case 3:
            emojiSprite->setTextureRect(sf::IntRect(64, 0, 32, 32));
            break;
    }
    this->clockEmoji.restart();
}

void    Player::emoji(void) {
    switch (this->state.id) {
        case IDLE:
        case WALK_DOWN:
        case WALK_UP:
        case WALK_RIGHT:
        case WALK_LEFT:
            this->emojiAnimation(this->indicator);
            break;
        case PICKUP:
            this->emojiAnimation(this->pickup);
            break;
        case EVOLUTION:
            this->emojiAnimation(this->evolution);
            break;
        case DEATH:
            this->emojiAnimation(this->death);
            break;
        case TALK:
            this->emojiAnimation(this->talk);
            break;
        case DROP_EGG:
            this->emojiAnimation(this->love);
            break;
        case EGG_STATE:
            this->emojiAnimation(this->talk);
            break;
    }
}

void Player::anime(void) {
    this->emoji();
    switch (this->state.id) {
        case IDLE:
            if (rand() % 10000 + 1 < 5) {
                // this->setState(rand() % 9 + 1);
                // this->setState(EGG_STATE);
            }
            return;
        case WALK_DOWN:
            this->walkDown();
            break;
        case WALK_UP:
            this->walkUp();
            break;
        case WALK_RIGHT:
            this->walkRight();
            break;
        case WALK_LEFT:
            this->walkLeft();
            break;
        case PICKUP:
            this->pickupAnimation();
            break;
        case EVOLUTION:
            this->evolveAnimation();
            break;
        case DEATH:
            this->deathAnimation();
            break;
        case TALK:
            this->talkAnimation();
            break;
        case DROP_EGG:
            this->dropEggAnimation();
            break;
        case EGG_STATE:
            this->eggStateAnimation();
            break;
    }
}