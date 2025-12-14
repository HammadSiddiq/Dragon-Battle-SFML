#include "danger.h"

Danger::Danger(string picturePath)
{
  texture.loadFromFile(picturePath);
  sprite.setTexture(texture);
  x = -50;
  y = -50;
  sprite.setPosition(x, y);
  sprite.setScale(0.15, 0.15);
}

void Danger::moveDanger()
{
  y += 0.3;
  sprite.setPosition(sprite.getPosition().x, y);
}
