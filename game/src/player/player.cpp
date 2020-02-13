/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** player
*/

#include "player.hpp"

PlayerState::PlayerState(void) {
    this->pos = sf::Vector2f(0, 0);
    this->id = IDLE;
    this->progress = 0;
    this->emojiFrame = 0;
}

Player::Player(InterfaceCore *core, int number) {
    sf::Vector2f pos(0, 0);

    this->death =  new sf::Sprite(core->getSprite(SPRITE_DEATH));
    this->evolution =  new sf::Sprite(core->getSprite(SPRITE_EVOLUTION));
    this->pickup =  new sf::Sprite(core->getSprite(SPRITE_PICKUP));
    this->player =  new sf::Sprite(core->getSprite(SPRITE_PLAYER));
    this->player = new sf::Sprite(core->getSprite(SPRITE_PLAYER));
    this->indicator = new sf::Sprite(core->getSprite(SPRITE_INDICATOR));
    this->talk = new sf::Sprite(core->getSprite(SPRITE_TALK));
    this->love = new sf::Sprite(core->getSprite(SPRITE_LOVE));
    this->indicator->setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255, 255));
    this->setPosition(pos);
    this->number = number;
    this->addSound("assets/akhi.ogg");
    this->addSound("assets/uhuh.ogg");
    this->addSound("assets/evolution.ogg");
    this->addSound("assets/viens.ogg");
    this->addSound("assets/laetitia.ogg");
}

void    Player::addSound(std::string path) {
    sf::Sound sound;
    sf::SoundBuffer buffer;

    buffer.loadFromFile(path);
    this->soundBuffers.push_back(new sf::SoundBuffer(buffer));
    sound.setBuffer(*(this->soundBuffers.back()));
    this->sounds.push_back(new sf::Sound(sound));
}

void    Player::ExecQueue(void) {
    if (this->state.id != IDLE || this->state.PlayerQueue.size() == 0)
        return;
    this->state.id = this->state.PlayerQueue.at(0);
    this->state.PlayerQueue.erase(this->state.PlayerQueue.begin());
}

void    Player::AddToQueue(int i) {
    this->state.PlayerQueue.push_back(i);
}

void Player::setStatepos(int x, int y)
{
    this->state.posx = x;
    this->state.posy = y;
}

int Player::getStateposx(void)
{
    return (this->state.posx);
}

int Player::getStateposy(void)
{
    return (this->state.posy);
}

void    Player::playSound(int position) {
    this->sounds[position]->play();
}

void Player::setNumber(int nb) {
    this->number = nb;
}

int Player::getNumber(void) {
    return (this->number);
}

void Player::setRect(sf::IntRect rect) {
    this->player->setTextureRect(rect);
}

sf::Sprite Player::getIndicatorSprite(void) {
    return (*(this->indicator));
}

sf::Sprite  Player::getPlayerSprite(void) {
    return (*(this->player));
}

sf::Sprite  Player::getEvolutionSprite(void) {
    return (*(this->evolution));
}

sf::Sprite  Player::getDeathSprite(void) {
    return (*(this->death));
}

sf::Sprite  Player::getPickupSprite(void) {
    return (*(this->pickup));
}

sf::Sprite  Player::getTalkSprite(void) {
    return (*(this->talk));
}

sf::Sprite  Player::getLoveSprite(void) {
    return (*(this->love));
}

sf::Vector2f &Player::getPosition(void) {
    return (this->state.pos);
}

int &Player::getState(void) {
    return (this->state.id);
}

int &Player::getEmojiFrame(void) {
    return (this->state.emojiFrame);
}

int &Player::getProgress(void) {
    return (this->state.progress);
}

void Player::setPosition(sf::Vector2f pos) {
    this->state.pos = pos;
    this->player->setPosition(pos);
}

void Player::setState(int id) {
    this->state.id = id;
    switch (id) {
        case PICKUP:
            this->playSound(PICKUP_SOUND);
            break;
        case EVOLUTION:
            this->playSound(EVOLUTION_SOUND);
            break;
        case DEATH:
            this->playSound(DEATH_SOUND);
            break;
        case TALK:
            this->playSound(TALK_SOUND);
            break;
        case DROP_EGG:
            this->playSound(DROP_EGG_SOUND);
            break;
    }
}

void Player::setProgress(int progress) {
    this->state.progress = progress;
}

void Player::setEmojiFrame(int emojiFrame) {
    this->state.emojiFrame = emojiFrame;
}