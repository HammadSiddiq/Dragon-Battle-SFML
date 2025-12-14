#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Lives
{
  public:
    Sprite sprite;
    Texture texture;
    int x;
    int y;
  
    Lives(string picturePath);
    
};
