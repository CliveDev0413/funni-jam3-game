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
        bool restartFrame;
        
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
        void Load(char spritePath[])
        {
            Sprite = LoadTexture(spritePath);
            playerState = IDLE;
        }
        void Animate(float animSpeed = 0.15f)
        {
            timer += GetFrameTime();

            if(timer >= animSpeed)
            {
                timer = 0.0f;
                frame += 1;
            }

            switch(playerState)
            {
                case IDLE:
                    startFrame = 0;
                    endFrame = 6;
                    break;
                case RUNNING:
                    startFrame = 6;
                    endFrame = 9;
                    break;
                case JUMPING:
                    startFrame = 9;
                    endFrame = 10;
                    break;
            }

            if(frame >= endFrame)
            {
                frame = startFrame;
            }

            std::cout << frame % endFrame << std::endl;
        }
        void SetState(PlayerStates state)
        {
            playerState = state;
        }
        void Draw()
        {
            frameWidth = (float)(Sprite.width / 10);

            DrawTextureRec(
                Sprite,
                Rectangle{frameWidth * frame, 0, frameWidth, (float)Sprite.height},
                Position,
                WHITE
            );
        }
        void Unload()
        {
            UnloadTexture(Sprite);
        }
};

#endif