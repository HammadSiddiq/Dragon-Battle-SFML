#include "invader.h"

/*
Invader::Invader(string picturePath)
{
  enemyTexture.loadFromFile(picturePath);
  enemySprite.setTexture(enemyTexture);
  enemyX = -50;
  enemyY = -50;
  enemySprite.setPosition(enemyX, enemyY);
  enemySprite.setScale(0.5, 0.5);
  setAlphaBomb = false;
  setBetaBomb = false;
  setGammaBomb = false;
  bomb1 = new Bomb("img/enemy_laser.png");
  bomb2 = new Bomb("img/enemy_laser.png");
  bomb3 = new Bomb("img/enemy_laser.png");
  hitNum = 0;
  secondHit = false;
  
}
*/

Alpha::Alpha(string picturePath)
{
  enemyTexture.loadFromFile(picturePath);
  enemySprite.setTexture(enemyTexture);
  enemyX = -50;
  enemyY = -50;
  enemySprite.setPosition(enemyX, enemyY);
  enemySprite.setScale(0.5, 0.5);
  setAlphaBomb = false;
  setBetaBomb = false;
  setGammaBomb = false;
  bomb1 = new Bomb("img/enemy_laser.png");
  bomb2 = new Bomb("img/enemy_laser.png");
  bomb3 = new Bomb("img/enemy_laser.png");
  hitNum = 0;
  secondHit = false;
  
}

Beta::Beta(string picturePath)
{
  enemyTexture.loadFromFile(picturePath);
  enemySprite.setTexture(enemyTexture);
  enemyX = -50;
  enemyY = -50;
  enemySprite.setPosition(enemyX, enemyY);
  enemySprite.setScale(0.5, 0.5);
  setAlphaBomb = false;
  setBetaBomb = false;
  setGammaBomb = false;
  bomb1 = new Bomb("img/enemy_laser.png");
  bomb2 = new Bomb("img/enemy_laser.png");
  bomb3 = new Bomb("img/enemy_laser.png");
  hitNum = 0;
  secondHit = false;
  
}

Gamma::Gamma(string picturePath)
{
  enemyTexture.loadFromFile(picturePath);
  enemySprite.setTexture(enemyTexture);
  enemyX = -50;
  enemyY = -50;
  enemySprite.setPosition(enemyX, enemyY);
  enemySprite.setScale(0.5, 0.5);
  setAlphaBomb = false;
  setBetaBomb = false;
  setGammaBomb = false;
  bomb1 = new Bomb("img/enemy_laser.png");
  bomb2 = new Bomb("img/enemy_laser.png");
  bomb3 = new Bomb("img/enemy_laser.png");
  hitNum = 0;
  secondHit = false;
  
}

/*
void Invader::dropBomb(float& bombTimeAlpha, float& bombTimeBeta, float& bombTimeGamma)
{
  
  if (type == 1)
  {
    if(bombTimeAlpha >= 5)
    {
      setAlphaBomb = true;
    }
    if(bombTimeAlpha >= 0 && setAlphaBomb == true)
    {
      bomb1 -> setBombPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
      setAlphaBomb = false;
    }
    bomb1 -> moveBomb();
    bomb2 -> bombSprite.setPosition(-100, -100);
    bomb3 -> bombSprite.setPosition(-100, -100);
  }

  if (type == 2)
  {
    if(bombTimeBeta >= 3)
    {
      setBetaBomb = true;
    }
    if(bombTimeBeta >= 0 && setBetaBomb == true)
    {
      bomb2 -> setBombPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
      setBetaBomb = false;
    }
    
    bomb2 -> moveBomb();
    bomb1 -> bombSprite.setPosition(-100, -100);
    bomb3 -> bombSprite.setPosition(-100, -100);
  }
  
  if (type == 3)
  {
    if(bombTimeGamma >= 2)
    {
      setGammaBomb = true;
    }
    if(bombTimeGamma >= 0 && setGammaBomb == true)
    {
      bomb3 -> setBombPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
      setGammaBomb = false;
    }
    
    bomb3 -> moveBomb();
    bomb1 -> bombSprite.setPosition(-100, -100);
    bomb2 -> bombSprite.setPosition(-100, -100);
  }
}
*/

void Alpha::dropBomb(float& bombTimeAlpha, float& bombTimeBeta, float& bombTimeGamma)
{
  
  if (type == 1)
  {
    if(bombTimeAlpha >= 5)
    {
      setAlphaBomb = true;
    }
    if(bombTimeAlpha >= 0 && setAlphaBomb == true)
    {
      bomb1 -> setBombPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
      setAlphaBomb = false;
    }
    bomb1 -> moveBomb();
    bomb2 -> bombSprite.setPosition(-100, -100);
    bomb3 -> bombSprite.setPosition(-100, -100);
  }
}

void Beta::dropBomb(float& bombTimeAlpha, float& bombTimeBeta, float& bombTimeGamma)
{

  if (type == 2)
  {
    if(bombTimeBeta >= 3)
    {
      setBetaBomb = true;
    }
    if(bombTimeBeta >= 0 && setBetaBomb == true)
    {
      bomb2 -> setBombPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
      setBetaBomb = false;
    }
    
    bomb2 -> moveBomb();
    bomb1 -> bombSprite.setPosition(-100, -100);
    bomb3 -> bombSprite.setPosition(-100, -100);
  }
}

void Gamma::dropBomb(float& bombTimeAlpha, float& bombTimeBeta, float& bombTimeGamma)
{ 
  if (type == 3)
  {
    if(bombTimeGamma >= 2)
    {
      setGammaBomb = true;
    }
    if(bombTimeGamma >= 0 && setGammaBomb == true)
    {
      bomb3 -> setBombPosition(enemySprite.getPosition().x, enemySprite.getPosition().y);
      setGammaBomb = false;
    }
    
    bomb3 -> moveBomb();
    bomb1 -> bombSprite.setPosition(-100, -100);
    bomb2 -> bombSprite.setPosition(-100, -100);
  }
}
