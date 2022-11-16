#include "../include/raylib.h"
#include "../include/game.h"

int main()
{
    InitWindow(800, 600, "Funni Game");
    SetWindowState(FLAG_VSYNC_HINT);

    Start();
    
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }
    
    End();
    CloseWindow();

    return 0;
}