#include <SFML/Graphics.hpp>
#include <string.h>
#include "bullet.cpp"
#include "invader.cpp"
#include "addons.cpp"

using namespace sf;
using namespace std;

class Player
{
  public:
    Texture playerTexture;
    Sprite playerSprite;
    
    float speed;
    float x_axis;
    float y_axis;
    int x;
    int y;
    int killCount;
    int score;
    Text scoreText;
    Font scoreFont;
    SoundBuffer buffer;
    Sound hitSound;
    
    SoundBuffer winBuffer;
    Sound winSound;
    
    SoundBuffer loseBuffer;
    Sound loseSound;
    
    SoundBuffer playerHitBuffer;
    Sound playerHit;
    
    SoundBuffer levelUpBuffer;
    Sound levelUp;
    
    SoundBuffer clickBuffer;
    Sound clickSound;
    
    SoundBuffer addOnBuffer;
    Sound addOnSound;
    
    Lives* life1;
    Lives* life2;
    Lives* life3;
    int lifeCount;
    
    Bullet* bullet1;
    Bullet* bullet2;
    Bullet* bullet3;
    Bullet* bullet4;
    
    bool setBullet1;
    bool setBullet2;
    bool setBullet3;
    bool setBullet4;
    
    bool lifeActive;
    bool dangerActive;
    bool fireActive;
    bool lifeCollision;
    bool dangerCollision;
    bool fireCollision;
    bool onFire;
    bool addFifty;
    
    Player(string picturePath);
    void fire(float& bulletTime);
    void move(string s);
    void detectCollision(Invader* invader, Bullet* bullet);
    void detectLifeCollision(AddOn* life);
    void detectDangerCollision(AddOn* danger);
    void detectFireCollision(AddOn* fire);
    void detectBombCollision(Bomb* bomb);
    void detectEnemyCollision(Invader* invader);
    
    bool monsterCollision;
    bool dragonCollision;
};
