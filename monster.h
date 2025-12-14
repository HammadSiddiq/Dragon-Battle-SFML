#include <iostream>
#include <SFML/Graphics.hpp>
#include "enemy.h"
using namespace sf;
using namespace std;

class Monster : public Enemy
{
  public:
    Monster(string picturePath);
};
