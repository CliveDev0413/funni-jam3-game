#include "../include/player.h"

void Player::Load(char spritePath[])
{
    Sprite = LoadTexture(spritePath);
    playerState = IDLE;
}

void Player::Animate(float animSpeed = 0.15f)
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
}

void Player::SetState(PlayerStates state)
{
    playerState = state;
}

void Player::Draw()
{
    frameWidth = (float)(Sprite.width / 10);

    DrawTextureRec(
        Sprite,
        Rectangle{frameWidth * frame, 0, frameWidth, (float)Sprite.height},
        Position,
        WHITE
    );
}

void Player::Unload()
{
    UnloadTexture(Sprite);
}