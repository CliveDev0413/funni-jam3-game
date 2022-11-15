#include "../include/raylib.h"

int main()
{
    InitWindow(800, 600, "Hello World");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(WHITE);
            DrawText("Hello, world!", 100, 100, 50, LIGHTGRAY);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}