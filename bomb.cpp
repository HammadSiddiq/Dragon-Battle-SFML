#include "bomb.h"

Bomb::Bomb(){}

Bomb::Bomb(string picturePath)
{
  bombTexture.loadFromFile(picturePath);
  bombSprite.setTexture(bombTexture);
  bombX = -50;
  bombY = -50;
  bombSprite.setPosition(bombX, bombY);
  bombSprite.setScale(1, 1);
}

void Bomb::moveBomb()
{
  bombY += 0.1;
  bombSprite.setPosition(bombX, bombY);
}

void Bomb::setBombPosition(float xAxis,float yAxis)
{
  bombX = xAxis;
  bombY = yAxis;
  bombSprite.setPosition(xAxis, yAxis);
}
