#include<iostream>
#include<string>
#include<SFML/Graphics.hpp>
#include "addon.cpp"
using namespace std;
using namespace sf;

class Fire : public AddOn
{
  public:
    Fire(string picturePath);
};

class Lives : public AddOn
{
  public:
    Lives(string picturePath);
    
};

class Danger : public AddOn
{
  public:
    Danger(string picturePath);
    void moveDanger();
};
