#include <iostream>
#include <SFML/Graphics.hpp>
#include "enemy.h"
using namespace sf;
using namespace std;

class Dragon : public Enemy
{
  public:
    Dragon(string picturePath);
};
