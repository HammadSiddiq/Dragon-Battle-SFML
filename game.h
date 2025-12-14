#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include "gaints.cpp"


const char title[] = "OOP-Project, Spring-2023";

using namespace sf;
using namespace std;

class Game
{
  public:
    Sprite background;
    Texture bg_texture;
    
    Sprite resumeBackground;
    Texture resumeTexture;
    
    Sprite helpBackground;
    Texture helpTexture;
    
    Sprite scoresBackground;
    Texture scoresTexture;
    
    Player* p;
    
    bool gamePaused;
    
    Sprite firstBadge;
    Sprite secondBadge;
    Sprite thirdBadge;
    Texture firstBadgeTexture;
    Texture secondBadgeTexture;
    Texture thirdBadgeTexture;
    
    Font scoreFont;
    Text scoreWritten;
    Text levelWritten;
    Text levelText;
    int levelCount;
    
    Text helpText;
    
    SoundBuffer buffer;
    Sound backgroundMusic;

    AddOn* collectLife1;
    AddOn* collectDanger1;
    AddOn* collectFire1;
    
    //Monster* monster;
    Enemy* dragon;
    Enemy* monster;
    
    Text firstScoreWritten;
    Text secondScoreWritten;
    Text thirdScoreWritten;
    
    Text firstScore;
    Text secondScore;
    Text thirdScore;
    
    Text scoresWritten;
    Text helpWritten;
    
    bool fileExists;
    bool fileCreated;

    Invader* invader1;
    Invader* invader2;
    Invader* invader3;
    Invader* invader4;
    Invader* invader5;
    Invader* invader6;
    Invader* invader7;
    Invader* invader8;
    Invader* invader9;
    Invader* invader10;
    Invader* invader11;
    Invader* invader12;
    Invader* invader13;
    Invader* invader14;
    Invader* invader15;
    Invader* invader16;
    Invader* invader17;
    Invader* invader18;

    Invader* invader19;
    Invader* invader20;
    Invader* invader21;
    Invader* invader22;
    Invader* invader23;
    Invader* invader24;
    Invader* invader25;
    Invader* invader26;
    Invader* invader27;
    
    // Level 2 Enemies
    Invader* invader28;
    Invader* invader29;
    Invader* invader30;
    Invader* invader31;
    Invader* invader32;
    Invader* invader33;
    Invader* invader34;
    Invader* invader35;
    Invader* invader36;
    Invader* invader37;
    Invader* invader38;
    Invader* invader39;
    Invader* invader40;
    Invader* invader41;
    Invader* invader42;
    Invader* invader43;
    Invader* invader44;
    Invader* invader45;
    
    Invader* invader46;
    Invader* invader47;
    Invader* invader48;
    Invader* invader49;
    Invader* invader50;
    Invader* invader51;
    Invader* invader52;
    Invader* invader53;
    Invader* invader54;
    Invader* invader55;
    Invader* invader56;
    Invader* invader57;

    Game();
    void start_game();
    float bulletTime;
    float laserTime;
    float bombTimeAlpha;
    float bombTimeBeta;
    float bombTimeGamma;
    bool monsterActive;
    bool dragonActive;
    int scoreOne;
    int scoreTwo;
    int scoreThree;
    
    void displayScores();
    void displayHelp();
    
    void losingGame();
    void winningGame();
    
    bool gameOver;
    bool gameWon;
    
    Text gameOverText;
    Text gameWonText;
    Text playAgainButton;
    Text scoresButton;
    Text quitButton;
    Text pauseButton;
    Text resumeButton;
    
    int temp;
    float timeHolder;
    bool timeChecker;
    
    bool oneSet;
    bool twoSet;
    bool threeSet;

};
