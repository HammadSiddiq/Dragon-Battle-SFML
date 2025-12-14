#include "beta.h"

Beta::Beta(string picturePath)
{
  enemyTexture.loadFromFile(picturePath);
  enemySprite.setTexture(enemyTexture);
  enemyX = -50;
  enemyY = -50;
  enemySprite.setPosition(enemyX, enemyY);
  enemySprite.setScale(0.5, 0.5);
}
