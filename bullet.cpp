#include "bullet.h"

Bullet::Bullet(){}

Bullet::Bullet(string picturePath)
{
  bulletTexture.loadFromFile(picturePath);
  bulletSprite.setTexture(bulletTexture);
  bulletX = -50;
  bulletY = -50;
  bulletSprite.setPosition(bulletX + 45, bulletY);
  bulletSprite.setScale(0.75, 0.75);
}

void Bullet::moveBullet()
{
  bulletY -= 0.5;
  bulletSprite.setPosition(bulletX, bulletY);
}

void Bullet::setBulletPosition(float xAxis,float yAxis)
{
  bulletX = xAxis;
  bulletY = yAxis;
  bulletSprite.setPosition(xAxis, yAxis);
}
