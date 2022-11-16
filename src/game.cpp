#include "../include/game.h"
#include "../include/player.h"

enum GAME_STATE
{
    menu,
    game,
    end
};

Player player(50, 50, 300, 5, 5);

//Runs at the start of the game. Initialize anything that's needed.
void Start()
{
    player.Load((char*)"../assets/player/Tony.png");
    player.Sprite.width = player.Sprite.width * player.Scale.x;
    player.Sprite.height = player.Sprite.height * player.Scale.y;
}

//Runs every frame.
void Update()
{
    player.Animate();

    player.SetState(IDLE);

    if(IsKeyDown(KEY_A))
    {
        player.Position.x -= player.MoveSpeed * GetFrameTime(); 
        player.SetState(RUNNING);
    }
    if(IsKeyDown(KEY_D))
    {
        player.Position.x += player.MoveSpeed * GetFrameTime();
        player.SetState(RUNNING);
    }
    if(IsKeyDown(KEY_W))
    {
        player.Position.y -= player.MoveSpeed * GetFrameTime();
        player.SetState(RUNNING);
    }
    if(IsKeyDown(KEY_S))
    {
        player.Position.y += player.MoveSpeed * GetFrameTime();
        player.SetState(RUNNING);
    }
}

//Draws the graphics.
void Draw()
{
    BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(WHITE);
        player.Draw();
    EndDrawing();
}

//Unload everything that was loaded to prevent memory leaks.
void End()
{
    player.Unload();
}