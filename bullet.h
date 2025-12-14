#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Bullet
{
  public:
    float bulletX;
    float bulletY;
    Sprite bulletSprite;
    Texture bulletTexture;
    
    Bullet();
    Bullet(string picturePath);

    void moveBullet();
    void setBulletPosition(float xAxis,float yAxis);
};
