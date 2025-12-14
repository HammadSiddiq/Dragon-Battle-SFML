#include<iostream>
#include <SFML/Graphics.hpp>
#include "invader.h"
using namespace sf;
using namespace std;

class Gamma : public Enemy
{
  public:
    Gamma(string picturePath);
};
