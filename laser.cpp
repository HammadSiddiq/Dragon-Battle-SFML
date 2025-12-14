#include "laser.h"

Laser::Laser(){}

Laser::Laser(string picturePath)
{
  laserTexture.loadFromFile(picturePath);
  laserSprite.setTexture(laserTexture);
  laserX = -1500;
  laserY = -1500;
  laserSprite.setPosition(laserX, laserY);
  laserSprite.setScale(6, 16);
}

void Laser::moveLaser(float xAxis,float yAxis)
{
   laserY -= 0.5;
   laserSprite.setPosition(laserX, laserY); 
}

void Laser::setLaserPosition(float xAxis,float yAxis)
{
  laserX = xAxis;
  laserY = yAxis;
  laserSprite.setPosition(xAxis, yAxis);
  
}

void Laser::setPosition(float x, float y)
{
  laserX = x;
  laserY = y;
  laserSprite.setPosition(x, y);
}
