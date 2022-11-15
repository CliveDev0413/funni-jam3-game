#include "../include/game.h"


class Player
{        
    public:
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
        void Draw()
        {
            DrawRectangle(Position.x, Position.y, Scale.x, Scale.y, RED);
        }
};

Player player(50, 50);

//Runs at the start of the game. Initialize anything that's needed.
void Start()
{
    
}

//Runs every frame.
void Update()
{
    if(IsKeyDown(KEY_A))
    {
        player.Position.x -= player.MoveSpeed * GetFrameTime(); 
    }
    if(IsKeyDown(KEY_D))
    {
        player.Position.x += player.MoveSpeed * GetFrameTime(); 
    }
    if(IsKeyDown(KEY_W))
    {
        player.Position.y -= player.MoveSpeed * GetFrameTime(); 
    }
    if(IsKeyDown(KEY_S))
    {
        player.Position.y += player.MoveSpeed * GetFrameTime(); 
    }
}

//Draws the graphics.
void Draw()
{
    BeginDrawing();
        DrawFPS(10, 10);
        ClearBackground(WHITE);
        DrawText("Hello World", 100, 100, 50, LIGHTGRAY);
        player.Draw();          
    EndDrawing();
}

//Unload everything that was loaded to prevent memory leaks.
void End()
{

}