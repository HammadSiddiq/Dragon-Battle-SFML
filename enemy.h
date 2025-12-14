#include<iostream>
#include <SFML/Graphics.hpp>
#include "laser.cpp"
#include "player.cpp"
using namespace std;
using namespace sf;

class Enemy
{
  public:
    Sprite enemySprite;
    Texture enemyTexture;
    float enemyX;
    float enemyY;
    Laser* laser;
    float timeHolder;
    bool timeChecker;
    virtual void detectCollision(Player* player, float& timer) = 0;
    virtual void fireLaser(float& laserTime) = 0;
    virtual void moveMonster() = 0;
    virtual void laserCollision(Player* player, float& timer) = 0;
};
