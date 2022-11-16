#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include <iostream>

enum PlayerStates
{
    IDLE,
    RUNNING,
    JUMPING
};

class Player
{   
    private:
        //Player anim vars
        float frameWidth;
        float timer = 0.0f;
        int frame;
        int startFrame;
        int endFrame;
        PlayerStates playerState;
        
    public:
        Texture2D Sprite;
        Vector2 Position;
        Vector2 Scale;
        float MoveSpeed;
        
        Player(float posX, float posY, float speed = 300, float ScaleX = 50, float ScaleY = 50)
        {
            Position.x = posX;
            Position.y = posY;
            Scale.x = ScaleX;
            Scale.y = ScaleY;
            MoveSpeed = speed;
        }
        void Load(char spritePath[]);
        void Animate(float animSpeed);
        void SetState(PlayerStates state);
        void Draw();
        void Unload();
};

#endif