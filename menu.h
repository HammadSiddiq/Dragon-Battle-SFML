#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.cpp"

using namespace std;
using namespace sf;

class Menu
{
  public:
    Font buttonFont;
    Text gameText;
    Text playText;
    Text helpText;
    Text scoresText;
    Text exitText;
    Sprite backgroundSprite;
    Texture backgroundTexture;
    SoundBuffer clickBuffer;
    Sound clickSound;
    SoundBuffer buffer;
    Sound backgroundMusic;

    
    Menu();
    void display_menu();
};
