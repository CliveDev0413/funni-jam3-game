#include "../include/raylib.h"
#include "../include/game.h"

int main()
{
    InitWindow(800, 600, "Hello World");

    Start();
    
    while (!WindowShouldClose())
    {
        Update();

        BeginDrawing();
            DrawFPS(10, 10);
            Draw();
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}