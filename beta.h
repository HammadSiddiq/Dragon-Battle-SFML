#include<iostream>
#include <SFML/Graphics.hpp>
#include "invader.h"
using namespace sf;
using namespace std;

class Beta : public Enemy
{
  public:
    Beta(string picturePath);
};
