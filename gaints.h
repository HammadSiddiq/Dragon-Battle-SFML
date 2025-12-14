#include <SFML/Graphics.hpp>
#include <iostream>
#include "enemy.cpp"

using namespace std;
using namespace sf;

class Monster : public Enemy
{
  public:
    Monster(string picturePath);
    void detectCollision(Player* player, float& timer);
    void moveMonster();
    bool movingLeft;
    bool movingRight;
    void fireLaser(float& laserTime);
    bool setLaser;
    Monster();
    void laserCollision(Player* player, float& timer);

};

class Dragon : public Enemy
{
  public:
    Dragon(string picturePath);
    void detectCollision(Player* player, float& timer);
    void fireLaser(float& laserTime);
    Dragon();
    void laserCollision(Player* player, float& timer);
    bool setLaser;
    void moveMonster();
};
