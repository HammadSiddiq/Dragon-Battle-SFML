#include <iostream>
#include <SFML/Graphics.hpp>
#include "invader.h"
using namespace sf;
using namespace std;

class Alpha : public Enemy
{
  public:
    Alpha(string picturePath);
};
