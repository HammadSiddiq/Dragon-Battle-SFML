#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Laser
{
  public:
    float laserX;
    float laserY;
    Sprite laserSprite;
    Texture laserTexture;
    
    Laser();
    Laser(string picturePath);

    void moveLaser(float xAxis,float yAxis);
    void setLaserPosition(float xAxis,float yAxis);
    void setPosition(float x, float y);
};
