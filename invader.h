#include <iostream>
#include <SFML/Graphics.hpp>
//#include "enemy.h"
#include "bomb.cpp"
using namespace sf;
using namespace std;

class Invader
{
  public:
    Sprite enemySprite;
    Texture enemyTexture;
    int enemyX;
    int enemyY;
    int type;
    Bomb* bomb1;
    Bomb* bomb2;
    Bomb* bomb3;
    bool setAlphaBomb;
    bool setBetaBomb;
    bool setGammaBomb;
    int hitNum;
    bool secondHit;
    
    //Invader();
    //Invader(string picturePath);
    
    virtual void dropBomb(float& bombTimeAlpha, float& bombTimeBeta, float& bombTimeGamma) = 0;
};

class Alpha : public Invader
{
  public:
    Alpha(string picturePath);
    void dropBomb(float& bombTimeAlpha, float& bombTimeBeta, float& bombTimeGamma);
};

class Beta : public Invader
{
  public:
    Beta(string picturePath);
    void dropBomb(float& bombTimeAlpha, float& bombTimeBeta, float& bombTimeGamma);
};

class Gamma : public Invader
{
  public:
    Gamma(string picturePath);
    void dropBomb(float& bombTimeAlpha, float& bombTimeBeta, float& bombTimeGamma);
};
