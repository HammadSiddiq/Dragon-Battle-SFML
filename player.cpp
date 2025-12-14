#include <iostream>
#include "player.h"

Player::Player(string picturePath)
{
  playerTexture.loadFromFile(picturePath);
  playerSprite.setTexture(playerTexture);
  x = 340;
  y = 700;
  x_axis = 340;
  y_axis = 700;
  speed = 0.1;
  killCount = 0;
  lifeCount = 3;
  dangerCollision = false;
  addFifty = true;
  
  life1 = new Lives("img/life.png");
  life1 -> sprite.setPosition(625, 10);
  life2 = new Lives("img/life.png");
  life2 -> sprite.setPosition(675, 10);
  life3 = new Lives("img/life.png");
  life3 -> sprite.setPosition(725, 10);
  
  playerSprite.setPosition(x,y);
  playerSprite.setScale(0.75,0.75);
  
  if (!buffer.loadFromFile("img/HitSound.ogg"))
  {
    cout << "Error! Background Music not loaded correctly" << endl;
  }
  
  hitSound.setBuffer(buffer);
  hitSound.setVolume(50); // Set the volume to 50% (0 to 100)
  hitSound.setPitch(1.5); // Increase the pitch by 50%
  hitSound.setLoop(false); // Enable looping
  
  bullet1 = new Bullet("img/PNG/Effects/fire18.png");
  bullet2 = new Bullet("img/PNG/Effects/fire18.png");
  bullet3 = new Bullet("img/PNG/Effects/fire18.png");
  bullet4 = new Bullet("img/PNG/Effects/fire18.png");
  
  setBullet1 = true;
  setBullet2 = true;
  setBullet3 = true;
  setBullet4 = true;
  
  if (!scoreFont.loadFromFile("img/spaceshooter_font.ttf"))
  {
    cout << "Error! Score font not loaded correctly" << endl;
  }
  
  score = 0;
  
  scoreText.setFont(scoreFont);
  scoreText.setCharacterSize(30); // Size in pixels
  scoreText.setFillColor(sf::Color::White);
  scoreText.setPosition(725, 50); // Position relative to the window
  scoreText.setString(to_string(score));
  
  lifeActive = false;
  dangerActive = false;
  onFire = false;
  
  fireCollision = false;
  dangerCollision = false;
  lifeCollision = false;
  monsterCollision = false;
  dragonCollision = false;
  

  if (!winBuffer.loadFromFile("img/Win.ogg"))
  {
    cout << "Error! Win Music not loaded correctly" << endl;
  }
  
  if (!loseBuffer.loadFromFile("img/Lose.ogg"))
  {
    cout << "Error! Lose Music not loaded correctly" << endl;
  }
  
  if (!levelUpBuffer.loadFromFile("img/Level Up.ogg"))
  {
    cout << "Error! Level Up Music not loaded correctly" << endl;
  }
  
  if (!clickBuffer.loadFromFile("img/Click.ogg"))
  {
    cout << "Error! Click Music not loaded correctly" << endl;
  }
  
  if (!playerHitBuffer.loadFromFile("img/Player Hit.ogg"))
  {
    cout << "Error! Player Hit Music not loaded correctly" << endl;
  }
  
  if (!addOnBuffer.loadFromFile("img/Collect Addon.ogg"))
  {
    cout << "Error! Addon Music not loaded correctly" << endl;
  }
  
  winSound.setBuffer(winBuffer);
  winSound.setVolume(50); // Set the volume to 50% (0 to 100)
  winSound.setPitch(1); // Increase the pitch by 50%
  winSound.setLoop(false); // Enable looping
  
  addOnSound.setBuffer(addOnBuffer);
  addOnSound.setVolume(50); // Set the volume to 50% (0 to 100)
  addOnSound.setPitch(1); // Increase the pitch by 50%
  addOnSound.setLoop(false); // Enable looping
  
  loseSound.setBuffer(loseBuffer);
  loseSound.setVolume(50); // Set the volume to 50% (0 to 100)
  loseSound.setPitch(1); // Increase the pitch by 50%
  loseSound.setLoop(false); // Enable looping
  
  playerHit.setBuffer(playerHitBuffer);
  playerHit.setVolume(50); // Set the volume to 50% (0 to 100)
  playerHit.setPitch(1); // Increase the pitch by 50%
  playerHit.setLoop(false); // Enable looping
  
  levelUp.setBuffer(levelUpBuffer);
  levelUp.setVolume(50); // Set the volume to 50% (0 to 100)
  levelUp.setPitch(1); // Increase the pitch by 50%
  levelUp.setLoop(false); // Enable looping
  
  clickSound.setBuffer(clickBuffer);
  clickSound.setVolume(50); // Set the volume to 50% (0 to 100)
  clickSound.setPitch(1); // Increase the pitch by 50%
  clickSound.setLoop(false); // Enable looping
  
  
}

void Player::fire(float & bulletTime)
{
  if(bulletTime >= 0.5)
  {
    setBullet1 = true;
  }
  if(bulletTime >= 0 && setBullet1 == true)
  {
    bullet1 -> setBulletPosition(x_axis + 30, y_axis);
    setBullet1 = false;
  } 
  bullet1 -> moveBullet();
  hitSound.play();
 
  if(bulletTime >= 1)
  {
   setBullet2 = true;
  }
  if(bulletTime >= 0 && setBullet2 == true)
  {
    bullet2 -> setBulletPosition(x_axis + 30, y_axis);
    setBullet2 = false;
  } 
  bullet2 -> moveBullet();
  hitSound.play();
 
  if(bulletTime >= 1.5)
  {
    setBullet3 = true;
  }
  if(bulletTime >= 0 && setBullet3 == true)
  {
    bullet3 -> setBulletPosition(x_axis + 30, y_axis);
    setBullet3 = false;
  } 
  bullet3 -> moveBullet();
  hitSound.play();
 
  if(bulletTime >= 2)
  {
    setBullet4 = true;
  }
  if(bulletTime >= 0 && setBullet4 == true)
  {
    bullet4 -> setBulletPosition(x_axis + 30, y_axis);
    setBullet4 = false;
  }  
  bullet4 -> moveBullet();
  hitSound.play();
}

void Player::move(string s)
{
  float delta_x = 0, delta_y = 0;
  
  if(s == "l")
  {
    delta_x = -1;
    x_axis-=speed;
  }
	
  else if(s == "r")
  {
    delta_x = 1;
    x_axis+=speed;
  }
	
  if(s == "u")
  {
    delta_y = -1;
    y_axis-=speed;
  }
	
  else if(s == "d")
  {
    delta_y = 1;
    y_axis+=speed;
  }

  delta_x *= speed;
  delta_y *= speed;
  
  playerSprite.move(delta_x, delta_y);
  
  if ((playerSprite.getPosition().x <= 0))
  {
    x_axis = 780;
    playerSprite.setPosition(x_axis, playerSprite.getPosition().y);

  }
  
  if (x_axis > 780)
  {
    x_axis = 0;
    playerSprite.setPosition(x_axis, playerSprite.getPosition().y);
  }
  
  if (playerSprite.getPosition().y <= 0)
  {
    y_axis = 780;
    playerSprite.setPosition(playerSprite.getPosition().x, y_axis);
  }
  
  if (y_axis > 780)
  {
    y_axis = 0;
    playerSprite.setPosition(playerSprite.getPosition().x, y_axis);
  }
}

void Player::detectCollision(Invader* invader, Bullet* bullet)
{
  FloatRect enemyRange = invader -> enemySprite.getGlobalBounds();
  FloatRect bulletRange = bullet -> bulletSprite.getGlobalBounds();

  if (enemyRange.intersects(bulletRange))
  {
    playerHit.play();
    invader -> enemySprite.setPosition(-1000, -1000);
    
    if (invader -> hitNum == 1)
    {
      invader -> secondHit = true;
    }
    
    invader -> hitNum = 1;
    
    if (onFire == false)
    {
      bullet -> setBulletPosition(-100, -100);
    }
    killCount++;
    //cout << killCount << endl;
    
    if (invader -> type == 1)
    {
      score += 10;
    }
    if (invader -> type == 2)
    {
      score += 20;
    }
    if (invader -> type == 3)
    {
      score += 30;
    }
    scoreText.setString(to_string(score));
  }
}

void Player::detectLifeCollision(AddOn* life)
{
  FloatRect lifeRange = life -> sprite.getGlobalBounds();
  FloatRect playerRange = playerSprite.getGlobalBounds();
  
  if (lifeRange.intersects(playerRange))
  {
    addOnSound.play();
    lifeCollision = true;
  
    if (lifeCount == 3)
    {
      return;
    }
  
    if (lifeCount == 1)
    {
      life2 -> sprite.setPosition(675, 10);
      lifeCount++;
      //lifeCollision = false;
      return;
    }
  
    if (lifeCount == 2)
    {
      life1 -> sprite.setPosition(625, 10);
      lifeCount++;
      //lifeCollision = false;
      return;
    }
  
    if (lifeCount == 0)
    {
      life3 -> sprite.setPosition(725, 10);
      lifeCount++;
      //lifeCollision = false;
      return;
    }
  }
}

void Player::detectDangerCollision(AddOn* danger)
{
 
  FloatRect dangerRange = danger -> sprite.getGlobalBounds();
  FloatRect playerRange = playerSprite.getGlobalBounds();
  
  if (dangerRange.intersects(playerRange))
  {
    addOnSound.play();
    if (lifeCount == 3)
    {
      life1 -> sprite.setPosition(-100, -100);
      lifeCount--;
      dangerCollision = true;
      dangerActive = false;
      danger -> sprite.setPosition(-100, -100);
      return;
    }
  
    else if (lifeCount == 1)
    {
      life3 -> sprite.setPosition(-100, -100);
      lifeCount--;
      dangerCollision = true;
      dangerActive = false;
      danger -> sprite.setPosition(-100, -100);
      return;
    }
  
    else if (lifeCount == 2)
    {
      life2 -> sprite.setPosition(-100, -100);
      lifeCount--;
      dangerCollision = true;
      dangerActive = false;
      danger -> sprite.setPosition(-100, -100);
      return;
    }
  
    else if (lifeCount == 0)
    {
      danger -> sprite.setPosition(-100, -100);
      lifeCount--;
      return;
    }
  }
}

void Player::detectFireCollision(AddOn* fire)
{
  FloatRect fireRange = fire -> sprite.getGlobalBounds();
  FloatRect playerRange = playerSprite.getGlobalBounds();
  
  if (fireRange.intersects(playerRange))
  {
    addOnSound.play();
    onFire = true;
    fireCollision = true;
  
    bullet1 -> bulletTexture.loadFromFile("img/PNG/Lasers/laserGreen14.png");
    bullet1 -> bulletSprite.setTexture(bullet1 -> bulletTexture);
    
    bullet2 -> bulletTexture.loadFromFile("img/PNG/Lasers/laserGreen14.png");
    bullet2 -> bulletSprite.setTexture(bullet2 -> bulletTexture);
    
    bullet3 -> bulletTexture.loadFromFile("img/PNG/Lasers/laserGreen14.png");
    bullet3 -> bulletSprite.setTexture(bullet3 -> bulletTexture);
    
    bullet4 -> bulletTexture.loadFromFile("img/PNG/Lasers/laserGreen14.png");
    bullet4 -> bulletSprite.setTexture(bullet4 -> bulletTexture);
  }
}

void Player::detectBombCollision(Bomb* bomb)
{
  FloatRect bombRange = bomb -> bombSprite.getGlobalBounds();
  FloatRect playerRange = playerSprite.getGlobalBounds();
  
  if (bombRange.intersects(playerRange))
  {
    playerHit.play();
    if (lifeCount == 3)
    {
      life1 -> sprite.setPosition(-100, -100);
      lifeCount--;
      bomb -> setBombPosition(-100, -100);
      return;
    }
  
    else if (lifeCount == 1)
    {
      life3 -> sprite.setPosition(-100, -100);
      lifeCount--;
      bomb -> setBombPosition(-100, -100);
      return;
    }
  
    else if (lifeCount == 2)
    {
      life2 -> sprite.setPosition(-100, -100);
      lifeCount--;
      bomb -> setBombPosition(-100, -100);
      return;
    }
  
    else if (lifeCount == 0)
    {
      bomb -> setBombPosition(-100, -100);
      lifeCount--;
      return;
    }
  }
}

void Player::detectEnemyCollision(Invader* invader)
{
  FloatRect invaderRange = invader -> enemySprite.getGlobalBounds();
  FloatRect playerRange = playerSprite.getGlobalBounds();
  
  if (invaderRange.intersects(playerRange))
  {
    
    if (lifeCount == 3)
    {
      life1 -> sprite.setPosition(-100, -100);
      lifeCount--;
      return;
    }
  
    else if (lifeCount == 1)
    {
      life3 -> sprite.setPosition(-100, -100);
      lifeCount--;
      return;
    }
  
    else if (lifeCount == 2)
    {
      life2 -> sprite.setPosition(-100, -100);
      lifeCount--;
      return;
    }
  
    else if (lifeCount == 0)
    {
      lifeCount--;
      
    }
  }
}

