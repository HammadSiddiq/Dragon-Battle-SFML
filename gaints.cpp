#include "gaints.h"

Monster::Monster(string picturePath)
{
  enemyTexture.loadFromFile(picturePath);
  enemySprite.setTexture(enemyTexture);
  enemyX = 200;
  enemyY = 0;
  enemySprite.setPosition(enemyX, enemyY);
  enemySprite.setScale(0.25, 0.25);
  movingLeft = true;
  movingRight = false;
  timeChecker = false;
  
  laser = new Laser("img/PNG/Lasers/laserRed03.png");
}

Dragon::Dragon(string picturePath)
{
  enemyTexture.loadFromFile(picturePath);
  enemySprite.setTexture(enemyTexture);
  enemyX = -50;
  enemyY = -50;
  enemySprite.setPosition(enemyX, enemyY);
  enemySprite.setScale(1.4, 1.4);
  timeChecker = false;
  
  laser = new Laser("img/PNG/Effects/fire16.png");
}

Dragon::Dragon() {}

Monster::Monster() {}

void Monster::moveMonster()
{
  //enemyX -= 0.05;
  //enemySprite.setPosition(enemyX, enemyY);
  
  if (enemySprite.getPosition().x > 0 && enemySprite.getPosition().x < 700)
  {
    if (movingLeft)
    {
      enemyX -= 0.05;
      enemySprite.setPosition(enemyX, enemyY);
    }
    else if (movingRight)
    {
      enemyX += 0.05;
      enemySprite.setPosition(enemyX, enemyY);
    }
  }
  
  if (enemySprite.getPosition().x <= 0)
  {
    movingRight = true;
    movingLeft = false;
      enemyX += 5;
      enemySprite.setPosition(enemyX, enemyY);
  }
  
  if (enemySprite.getPosition().x >= 450)
  {
    movingRight = false;
    movingLeft = true; 
      enemyX -= 5;
      enemySprite.setPosition(enemyX, enemyY);
  }  
}

void Monster::fireLaser(float& laserTime)
{
  if(laserTime >= 0 && laserTime < 2)
  {
    setLaser = false;
    //laser -> setLaserPosition(enemyX + 150, enemyY + 150);
  }
  
  if(laserTime >= 2 && laserTime <= 4)
  {
    //laser -> setLaserPosition(enemyX + 150, enemyY + 150);
    setLaser = true;
  }
  
  if (setLaser == false)
  {
    laser -> setLaserPosition(-2000, -2000);
  }
  
  if(setLaser)
  {
    laser -> setLaserPosition(enemyX + 150, enemyY + 125);
  }

}

void Monster::detectCollision(Player* player, float& timer)
{
  FloatRect playerRange = player -> playerSprite.getGlobalBounds();
  FloatRect enemyRange = enemySprite.getGlobalBounds();
  
  if (enemyRange.intersects(playerRange))
  {
    if (player -> lifeCount == 3)
    {
      player -> life1 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      return;
    }
  
    else if (player -> lifeCount == 1)
    {
      player -> life3 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      return;
    }
  
    else if (player -> lifeCount == 2)
    {
      player -> life2 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      return;
    }
  
    else if (player -> lifeCount == 0)
    {
      player -> lifeCount--;
      return;
    }
  }
}

void Dragon::detectCollision(Player* player, float& timer)
{
  FloatRect playerRange = player -> playerSprite.getGlobalBounds();
  FloatRect enemyRange = enemySprite.getGlobalBounds();
  
  if (enemyRange.intersects(playerRange))
  {
    if (player -> lifeCount == 3)
    {
      player -> life1 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      return;
    }
  
    else if (player -> lifeCount == 1)
    {
      player -> life3 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      return;
    }
  
    else if (player -> lifeCount == 2)
    {
      player -> life2 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      return;
    }
  
    else if (player -> lifeCount == 0)
    {
      player -> lifeCount--;
      return;
    }
  }
}

void Dragon::fireLaser(float& laserTime)
{
  if(laserTime >= 0 && laserTime < 2)
  {
    setLaser = false;
    //laser -> setLaserPosition(enemyX + 150, enemyY + 150);
  }
  
  if(laserTime >= 2 && laserTime <= 4)
  {
    //laser -> setLaserPosition(enemyX + 150, enemyY + 150);
    setLaser = true;
  }
  
  if (setLaser == false)
  {
    laser -> setLaserPosition(-2000, -2000);
  }
  
  if(setLaser)
  {
    laser -> setLaserPosition(enemyX + 375, enemyY + 300);
  }
}

void Monster::laserCollision(Player* player, float& timer)
{
  FloatRect laserRange = player -> playerSprite.getGlobalBounds();
  FloatRect enemyRange = laser -> laserSprite.getGlobalBounds();
  
  if (enemyRange.intersects(laserRange))
  {
    player -> monsterCollision = true;
  
    if (!timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
  
    if (player -> lifeCount == 3 && timer >= timeHolder + 0.5)
    {
      player -> life1 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      timeChecker = false;
      return;
    }
  
    else if (player -> lifeCount == 1 && timer >= timeHolder + 1.5)
    {
      player -> life3 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      timeChecker = false;
      return;
    }
  
    else if (player -> lifeCount == 2 && timer >= timeHolder + 1)
    {
      player -> life2 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      timeChecker = false;
      return;
    }
  
    else if (player -> lifeCount == 0 && timer >= timeHolder + 1.75)
    {
      player -> lifeCount--;
      timeChecker = false;
      return;
    }
  }
}

void Dragon::laserCollision(Player* player, float& timer)
{
  FloatRect laserRange = player -> playerSprite.getGlobalBounds();
  FloatRect enemyRange = laser -> laserSprite.getGlobalBounds();
  
  if (enemyRange.intersects(laserRange))
  {
    player -> dragonCollision = true;
  
    if (!timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
  
    if (player -> lifeCount == 3 && timer >= timeHolder + 0.5)
    {
      player -> life1 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      timeChecker = false;
      return;
    }
  
    else if (player -> lifeCount == 1 && timer >= timeHolder + 1.5)
    {
      player -> life3 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      timeChecker = false;
      return;
    }
  
    else if (player -> lifeCount == 2 && timer >= timeHolder + 1)
    {
      player -> life2 -> sprite.setPosition(-100, -100);
      player -> lifeCount--;
      timeChecker = false;
      return;
    }
  
    else if (player -> lifeCount == 0 && timer >= timeHolder + 1.75)
    {
      player -> lifeCount--;
      timeChecker = false;
      return;
    }
  }
}

void Dragon::moveMonster() {}

