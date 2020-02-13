/*
** EPITECH PROJECT, 2019
** PSU_zappy_2018
** File description:
** player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "interface.hpp"

#define IDLE            0
#define WALK_RIGHT      1
#define WALK_LEFT       2
#define WALK_UP         3
#define WALK_DOWN       4
#define PICKUP          5
#define DEATH           6
#define EVOLUTION       7
#define DROP            5
#define TALK            8
#define DROP_EGG        9
#define EGG_STATE       10

#define PICKUP_SOUND    0
#define DEATH_SOUND     1
#define EVOLUTION_SOUND 2
#define TALK_SOUND      3
#define DROP_EGG_SOUND  4

class InterfaceCore;

class PlayerState {
    public:
        PlayerState(void);
        sf::Vector2f pos;
        int id;
        int posx;
        int posy;
        int progress;
        std::vector<int> PlayerQueue;
        int emojiFrame;
};

class Player {
    public:
        Player(InterfaceCore *core, int number);
        void            addSound(std::string path);
        void            playSound(int sound);
        sf::Sprite      getPlayerSprite(void);
        sf::Sprite      getIndicatorSprite(void);
        sf::Sprite      getEvolutionSprite(void);
        sf::Sprite      getDeathSprite(void);
        sf::Sprite      getPickupSprite(void);
        sf::Sprite      getTalkSprite(void);
        sf::Sprite      getLoveSprite(void);
        sf::Vector2f    &getPosition(void);
        int             &getState(void);
        int             &getProgress(void);
        int             &getEmojiFrame(void);
        void            setPosition(sf::Vector2f pos);
        void            setState(int id);
        void            setStatepos(int x, int y);
        int             getStateposx(void);
        int             getStateposy(void);
        void            setProgress(int progress);
        void            setRect(sf::IntRect);
        void            setEmojiFrame(int emojiFrame);
        void            anime(void);
        void            toIdle(bool lookRight);
        void            walkRight(void);
        void            walkLeft(void);
        void            walkUp(void);
        void            walkDown(void);
        void            evolveAnimation(void);
        void            pickupAnimation(void);
        void            deathAnimation(void);
        void            talkAnimation(void);
        void            dropEggAnimation(void);
        void            eggStateAnimation(void);
        void            emoji(void);
        void            emojiAnimation(sf::Sprite *emojiSprite);
        void            setNumber(int nb);
        int             getNumber(void);
        void            AddToQueue(int i);
        void            ExecQueue(void);
    private:
        sf::Sprite  *player;
        sf::Sprite  *death;
        sf::Sprite  *pickup;
        sf::Sprite  *evolution;
        sf::Sprite  *indicator;
        sf::Sprite  *talk;
        sf::Sprite  *love;
        int         number;
        PlayerState state;
        sf::Clock   clock;
        sf::Clock   clockEmoji;
        std::vector<sf::Sound*> sounds;
        std::vector<sf::SoundBuffer*> soundBuffers;
};

#endif /* !PLAYER_HPP_ */
