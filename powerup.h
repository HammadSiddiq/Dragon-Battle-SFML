#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include "addon.h"
using namespace std;
using namespace sf;

class PowerUp : public AddOn
{
  public:
    Lives(string picturePath);
};
