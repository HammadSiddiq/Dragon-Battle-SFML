#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Bomb
{
  public:
    float bombX;
    float bombY;
    Sprite bombSprite;
    Texture bombTexture;
    
    Bomb();
    Bomb(string picturePath);

    void moveBomb();
    void setBombPosition(float xAxis, float yAxis);
};
