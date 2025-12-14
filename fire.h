#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Fire
{
  public:
    Sprite sprite;
    Texture texture;
    int x;
    int y;
  
    Fire(string picturePath);
};


