#include "../include/game.h"
#include "../include/player.h"

Rectangle window;

enum GAME_STATE
{
    menu,
    game,
    end
};

Player player(50, 466, 300, 4, 4);

Texture2D sky;
Texture2D ground;
Texture2D city;
Texture2D city2;

//Runs at the start of the game. Initialize anything that's needed.
void Start()
{
    window = {0, 0, 800, 600};

    player.Load((char*)"../assets/player/Tony.png");
    player.Sprite.width = player.Sprite.width * player.Scale.x;
    player.Sprite.height = player.Sprite.height * player.Scale.y;

    sky = LoadTexture("../assets/environment/Sky.png");
    city = LoadTexture("../assets/environment/CityBG.png");
    city2 = LoadTexture("../assets/environment/CityBG.png");
    ground = LoadTexture("../assets/environment/Ground.png");

    player.SetState(RUNNING);
}

//Runs every frame.
void Update()
{
    player.Animate(0.09f);
}

//Draws the graphics.
void Draw()
{
    BeginDrawing();

        ClearBackground(WHITE);
        DrawTexture(sky, 0, 0, WHITE);
        DrawTexture(city, 0, 0, WHITE);
        DrawTexture(city2, city.width, 0, WHITE);
        DrawTexture(ground, 0, 0, WHITE);
        player.Draw();
        DrawFPS(10, 10);
        
    EndDrawing();
}

//Unload everything that was loaded to prevent memory leaks.
void End()
{
    player.Unload();
    UnloadTexture(sky);
    UnloadTexture(city);
    UnloadTexture(city2);
    UnloadTexture(ground);
}