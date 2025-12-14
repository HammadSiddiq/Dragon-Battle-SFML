#include "game.h"

Game::Game()
{
  fileCreated = false;
  fileExists = false;

  ///// START OF CREATING TEXT & MUSIC /////

  if (!scoreFont.loadFromFile("img/spaceshooter_font.ttf"))
  {
    cout << "Error! Score font not loaded correctly" << endl;
  }
  
  if (!buffer.loadFromFile("img/music.ogg"))
  {
    cout << "Error! Background Music not loaded correctly" << endl;
  }
  
  /*if (!(ifstream infile("scores.txt")))
  {
    ofstream outfile("scores.txt");
    fileCreated = true;
  }
  else
  {
    ifstream infile("scores.txt");
    fileExists = true;
  }*/
  
  
  gamePaused = false;
  gameOver = false;
  gameWon = false;
  temp = 0;
  oneSet = false;
  twoSet = false;
  threeSet = false;
  timeChecker = false;
  
  firstBadgeTexture.loadFromFile("img/first.png");
  firstBadge.setTexture(firstBadgeTexture);
  firstBadge.setScale(0.3, 0.3);
  firstBadge.setPosition(200, 180);
  
  secondBadgeTexture.loadFromFile("img/second.png");
  secondBadge.setTexture(secondBadgeTexture);
  secondBadge.setScale(0.3, 0.3);
  secondBadge.setPosition(200, 280);
  
  thirdBadgeTexture.loadFromFile("img/third.png");
  thirdBadge.setTexture(thirdBadgeTexture);
  thirdBadge.setScale(0.3, 0.3);
  thirdBadge.setPosition(200, 380);
  
  gameOverText.setFont(scoreFont);
  gameOverText.setCharacterSize(70); // Size in pixels
  gameOverText.setFillColor(sf::Color::Red);
  gameOverText.setPosition(-100, -100); // Position relative to the window
  gameOverText.setString("GAME OVER!");
  
  gameWonText.setFont(scoreFont);
  gameWonText.setCharacterSize(70); // Size in pixels
  gameWonText.setFillColor(sf::Color::Green);
  gameWonText.setPosition(-100, -100); // Position relative to the window
  gameWonText.setString("YOU WIN!");
  
  playAgainButton.setFont(scoreFont);
  playAgainButton.setCharacterSize(30); // Size in pixels
  playAgainButton.setFillColor(sf::Color::White);
  playAgainButton.setPosition(-100, -100); // Position relative to the window
  playAgainButton.setString("[PLAY AGAIN]");

  scoresButton.setFont(scoreFont);
  scoresButton.setCharacterSize(30); // Size in pixels
  scoresButton.setFillColor(sf::Color::White);
  scoresButton.setPosition(-100, -100); // Position relative to the window
  scoresButton.setString("[SCORES]");

  quitButton.setFont(scoreFont);
  quitButton.setCharacterSize(30); // Size in pixels
  quitButton.setFillColor(sf::Color::White);
  quitButton.setPosition(-100, -100); // Position relative to the window
  quitButton.setString("[QUIT]");
  
  //pauseButton.setFont(scoreFont);
  //pauseButton.setCharacterSize(30); // Size in pixels
  //pauseButton.setFillColor(sf::Color::White);
  //pauseButton.setPosition(-100, -100); // Position relative to the window
  //pauseButton.setString("[PAUSE]");
  
  resumeButton.setFont(scoreFont);
  resumeButton.setCharacterSize(40); // Size in pixels
  resumeButton.setFillColor(sf::Color::Black);
  resumeButton.setPosition(-100, -100); // Position relative to the window
  resumeButton.setString("[RESUME]");
  
  scoreOne = 0;
  scoreTwo = 0;
  scoreThree = 0;
  
  helpTexture.loadFromFile("img/background1.jpg");
  helpBackground.setTexture(helpTexture);
  helpBackground.setScale(2, 1.5);
  
  scoresTexture.loadFromFile("img/background2.jpg");
  scoresBackground.setTexture(scoresTexture);
  scoresBackground.setScale(2, 3);
  
  resumeTexture.loadFromFile("img/popup.jpeg"); /////////////////////////////////////
  resumeBackground.setTexture(resumeTexture);
  resumeBackground.setScale(1, 1);
  resumeBackground.setPosition(-1000, -1000);
  
  levelCount = 1;
  
  helpText.setFont(scoreFont);
  helpText.setCharacterSize(20);
  helpText.setFillColor(sf::Color::White);
  helpText.setPosition(25, 25);
  helpText.setString("Welcome to Space Shooter Game.\n\n\n The goal of the game is to kill enemies and dodge monster and dragon.\n\n\n Collect addons such as lives and fire to facilitate your adventure. Also, look out for the \n danger which takes away one of your lives.\n\n\n Use arrow keys to navigate through the screen and move across it.\n\n\n The game has 3 levels and gets difficult as you proceed.\n\n\n The dragon and monster are dangerous. Watch out for them. The score for dodging the \n monster as well as the dragon is 50. The score to dodge the danger is also 50. \n\n\n Have fun!");
  
  backgroundMusic.setBuffer(buffer);
  backgroundMusic.setVolume(50); // Set the volume to 50% (0 to 100)
  backgroundMusic.setPitch(1.5); // Increase the pitch by 50%
  backgroundMusic.setLoop(true); // Enable looping
  
  scoreWritten.setFont(scoreFont);
  scoreWritten.setCharacterSize(30); // Size in pixels
  scoreWritten.setFillColor(sf::Color::White);
  scoreWritten.setPosition(650, 50); // Position relative to the window
  scoreWritten.setString("Score:");
  
  levelWritten.setFont(scoreFont);
  levelWritten.setCharacterSize(30); // Size in pixels
  levelWritten.setFillColor(sf::Color::White);
  levelWritten.setPosition(10, 10); // Position relative to the window
  levelWritten.setString("Level: ");
  
  levelText.setFont(scoreFont);
  levelText.setCharacterSize(30); // Size in pixels
  levelText.setFillColor(sf::Color::White);
  levelText.setPosition(100, 10); // Position relative to the window
  levelText.setString(to_string(levelCount));
  
  ///// CREATING TOP SCORES /////
  firstScoreWritten.setFont(scoreFont);
  firstScoreWritten.setCharacterSize(30);
  firstScoreWritten.setFillColor(sf::Color::White);
  firstScoreWritten.setPosition(300, 200);
  firstScoreWritten.setString("1st Place: ");
  
  secondScoreWritten.setFont(scoreFont);
  secondScoreWritten.setCharacterSize(30);
  secondScoreWritten.setFillColor(sf::Color::White);
  secondScoreWritten.setPosition(300, 300);
  secondScoreWritten.setString("2nd Place: ");
  
  thirdScoreWritten.setFont(scoreFont);
  thirdScoreWritten.setCharacterSize(30);
  thirdScoreWritten.setFillColor(sf::Color::White);
  thirdScoreWritten.setPosition(300, 400);
  thirdScoreWritten.setString("3rd Place: ");
  
  firstScore.setFont(scoreFont);
  firstScore.setCharacterSize(30);
  firstScore.setFillColor(sf::Color::White);
  firstScore.setPosition(450, 200);
  firstScore.setString(to_string(scoreOne));
  
  secondScore.setFont(scoreFont);
  secondScore.setCharacterSize(30);
  secondScore.setFillColor(sf::Color::White);
  secondScore.setPosition(450, 300);
  secondScore.setString(to_string(scoreTwo));
  
  thirdScore.setFont(scoreFont);
  thirdScore.setCharacterSize(30);
  thirdScore.setFillColor(sf::Color::White);
  thirdScore.setPosition(450, 400);
  thirdScore.setString(to_string(scoreThree));

  ///// END OF CREATING TEXT & MUSIC /////

  p = new Player("img/player_ship.png");
  
  ///// START OF CREATING ENEMIES /////
  
  invader1 = new Beta("img/enemy_2.png");
  invader1 -> enemySprite.setPosition(225, 150);
  invader1 -> type = 2;
  
  invader2 = new Beta("img/enemy_2.png");
  invader2 -> enemySprite.setPosition(125, 150);
  invader2 -> type = 2;
  
  invader3 = new Beta("img/enemy_2.png");
  invader3 -> enemySprite.setPosition(25, 150);
  invader3 -> type = 2;
  
  invader4 = new Alpha("img/enemy_1.png");
  invader4 -> enemySprite.setPosition(225, 75);
  invader4 -> type = 1;
  
  invader5 = new Alpha("img/enemy_1.png");
  invader5 -> enemySprite.setPosition(125, 75);
  invader5 -> type = 1;
  
  invader6 = new Alpha("img/enemy_1.png");
  invader6 -> enemySprite.setPosition(25, 75);
  invader6 -> type = 1;
  
  invader7 = new Alpha("img/enemy_1.png");
  invader7 -> enemySprite.setPosition(225, 275);
  invader7 -> type = 1;
  
  invader8 = new Alpha("img/enemy_1.png");
  invader8 -> enemySprite.setPosition(125, 275);
  invader8 -> type = 1;
  
  invader9 = new Alpha("img/enemy_1.png");
  invader9 -> enemySprite.setPosition(25, 275);
  invader9 -> type = 1;
  
  invader10 = new Beta("img/enemy_2.png");
  invader10 -> enemySprite.setPosition(525, 75);
  invader10 -> type = 2;
  
  invader11 = new Alpha("img/enemy_1.png");
  invader11 -> enemySprite.setPosition(525, 175);
  invader11 -> type = 1;
  
  invader12 = new Alpha("img/enemy_1.png");
  invader12 -> enemySprite.setPosition(450, 175);
  invader12 -> type = 1;
  
  invader13 = new Alpha("img/enemy_1.png");
  invader13 -> enemySprite.setPosition(600, 175);
  invader13 -> type = 1;
  
  invader14 = new Beta("img/enemy_2.png");
  invader14 -> enemySprite.setPosition(525, 250);
  invader14 -> type = 2;
  
  invader15 = new Beta("img/enemy_2.png");
  invader15 -> enemySprite.setPosition(600, 250);
  invader15 -> type = 2;
  
  invader16 = new Beta("img/enemy_2.png");
  invader16 -> enemySprite.setPosition(450, 250);
  invader16 -> type = 2;
  
  invader17 = new Beta("img/enemy_2.png");
  invader17 -> enemySprite.setPosition(675, 250);
  invader17 -> type = 2;
  
  invader18 = new Beta("img/enemy_2.png");
  invader18 -> enemySprite.setPosition(375, 250);
  invader18 -> type = 2;
  
  invader19 = new Gamma("img/enemy_3.png");
  invader19 -> enemySprite.setPosition(50, 50);
  invader19 -> type = 3;
  invader19 -> enemySprite.setScale(0.35, 0.35);
  
  invader20 = new Gamma("img/enemy_3.png");
  invader20 -> enemySprite.setPosition(500, 50);
  invader20 -> type = 3;
  invader20 -> enemySprite.setScale(0.35, 0.35);
  
  invader21 = new Gamma("img/enemy_3.png");
  invader21 -> enemySprite.setPosition(400, 100);
  invader21 -> type = 3;
  invader21 -> enemySprite.setScale(0.35, 0.35);
  
  invader22 = new Gamma("img/enemy_3.png");
  invader22 -> enemySprite.setPosition(150, 100);
  invader22 -> type = 3;
  invader22 -> enemySprite.setScale(0.35, 0.35);
  
  invader23 = new Gamma("img/enemy_3.png");
  invader23 -> enemySprite.setPosition(275, 200);
  invader23 -> type = 3;
  invader23 -> enemySprite.setScale(0.35, 0.35);
  
  invader24 = new Gamma("img/enemy_3.png");
  invader24 -> enemySprite.setPosition(50, 350);
  invader24 -> type = 3;
  invader24 -> enemySprite.setScale(0.35, 0.35);
  
  invader25 = new Gamma("img/enemy_3.png");
  invader25 -> enemySprite.setPosition(500, 350);
  invader25 -> type = 3;
  invader25 -> enemySprite.setScale(0.35, 0.35);
  
  invader26 = new Gamma("img/enemy_3.png");
  invader26 -> enemySprite.setPosition(400, 250);
  invader26 -> type = 3;
  invader26 -> enemySprite.setScale(0.35, 0.35);
  
  invader27 = new Gamma("img/enemy_3.png");
  invader27 -> enemySprite.setPosition(150, 250);
  invader27 -> type = 3;
  invader27 -> enemySprite.setScale(0.35, 0.35);
  
  /////// Level 2 Enemies ///////
  
  /// Creating a circle ///
  invader28 = new Alpha("img/enemy_1.png");
  invader28 -> enemySprite.setPosition(200, 75);
  invader28 -> type = 1;
  
  invader29 = new Alpha("img/enemy_1.png");
  invader29 -> enemySprite.setPosition(100, 75);
  invader29 -> type = 1;
  
  invader30 = new Beta("img/enemy_2.png");
  invader30 -> enemySprite.setPosition(40, 140);
  invader30 -> type = 2;
  
  invader31 = new Beta("img/enemy_2.png");
  invader31 -> enemySprite.setPosition(40, 225);
  invader31 -> type = 2;
  
  invader32 = new Alpha("img/enemy_1.png");
  invader32 -> enemySprite.setPosition(100, 300);
  invader32 -> type = 1;
  
  invader33 = new Alpha("img/enemy_1.png");
  invader33 -> enemySprite.setPosition(200, 300);
  invader33 -> type = 1;
  
  invader34 = new Gamma("img/enemy_3.png");
  invader34 -> enemySprite.setPosition(250, 150);
  invader34 -> type = 3;
  invader34 -> enemySprite.setScale(0.35, 0.35);
  
  invader35 = new Gamma("img/enemy_3.png");
  invader35 -> enemySprite.setPosition(250, 225);
  invader35 -> type = 3;
  invader35 -> enemySprite.setScale(0.35, 0.35);
  
  /// Creating a heart ///
  invader36 = new Alpha("img/enemy_1.png");
  invader36 -> enemySprite.setPosition(700, 150);
  invader36 -> type = 1;
  
  invader37 = new Alpha("img/enemy_3.png");
  invader37 -> enemySprite.setPosition(475, 100);
  invader37 -> type = 3;
  invader37 -> enemySprite.setScale(0.35, 0.35);
  
  invader38 = new Alpha("img/enemy_1.png");
  invader38 -> enemySprite.setPosition(400, 150);
  invader38 -> type = 1;
  
  invader39 = new Gamma("img/enemy_3.png");
  invader39 -> enemySprite.setPosition(450, 225);
  invader39 -> type = 3;
  invader39 -> enemySprite.setScale(0.35, 0.35);
  
  invader40 = new Alpha("img/enemy_1.png");
  invader40 -> enemySprite.setPosition(500, 300);
  invader40 -> type = 1;
  
  invader41 = new Gamma("img/enemy_3.png");
  invader41 -> enemySprite.setPosition(550, 375);
  invader41 -> type = 3;
  invader41 -> enemySprite.setScale(0.35, 0.35);
  
  invader42 = new Gamma("img/enemy_3.png");
  invader42 -> enemySprite.setPosition(650, 225);
  invader42 -> type = 3;
  invader42 -> enemySprite.setScale(0.35, 0.35);
  
  invader43 = new Alpha("img/enemy_1.png");
  invader43 -> enemySprite.setPosition(600, 300);
  invader43 -> type = 1;

  invader44 = new Gamma("img/enemy_3.png");
  invader44 -> enemySprite.setPosition(625, 100);
  invader44 -> type = 3;
  invader44 -> enemySprite.setScale(0.35, 0.35);
  
  invader45 = new Alpha("img/enemy_1.png");
  invader45 -> enemySprite.setPosition(550, 150);
  invader45 -> type = 1;

  /// Creating a diamond ///
  
  invader46 = new Beta("img/enemy_2.png");
  invader46 -> enemySprite.setPosition(170, 100); // 1
  invader46 -> type = 1;
  
  invader47 = new Beta("img/enemy_2.png");
  invader47 -> enemySprite.setPosition(245, 100); // 2
  invader47 -> type = 2;
  
  invader48 = new Beta("img/enemy_2.png");
  invader48 -> enemySprite.setPosition(100, 150); // 3
  invader48 -> type = 2;
  
  invader49 = new Beta("img/enemy_2.png");
  invader49 -> enemySprite.setPosition(175, 225); // 4
  invader49 -> type = 2;
  
  invader50 = new Beta("img/enemy_2.png");
  invader50 -> enemySprite.setPosition(250, 300); // 5
  invader50 -> type = 2;
  
  invader51 = new Beta("img/enemy_2.png");
  invader51 -> enemySprite.setPosition(325, 375); // 6
  invader51 -> type = 2;
  
  invader52 = new Beta("img/enemy_2.png");
  invader52 -> enemySprite.setPosition(400, 300); // 7
  invader52 -> type = 2;
  
  invader53 = new Beta("img/enemy_2.png");
  invader53 -> enemySprite.setPosition(475, 225); // 8
  invader53 -> type = 2;

  invader54 = new Beta("img/enemy_2.png");
  invader54 -> enemySprite.setPosition(550, 150); // 9
  invader54 -> type = 2;

  invader55 = new Beta("img/enemy_2.png");
  invader55 -> enemySprite.setPosition(320, 100); // 10
  invader55 -> type = 2;
  
  invader56 = new Beta("img/enemy_2.png");
  invader56 -> enemySprite.setPosition(395, 100); // 11
  invader56 -> type = 2;
  
  invader57 = new Beta("img/enemy_2.png");
  invader57 -> enemySprite.setPosition(470, 100); // 12
  invader57 -> type = 2;
  
  ///// END OF CREATING ENEMIES /////
  
  ///// START OF CREATING ADDONS & BACKGROUND /////
  
  collectLife1 = new Lives("img/life.png"); 
  collectLife1 -> sprite.setPosition(-100, -100);
  
  collectDanger1 = new Danger("img/danger.png");
  collectDanger1 -> sprite.setPosition(-100, -100);
  
  collectFire1 = new Fire("img/fire.png"); 
  collectFire1 -> sprite.setPosition(-100, -100);
  
  bg_texture.loadFromFile("img/background.jpg");
  background.setTexture(bg_texture);
  background.setScale(2, 1.5);
  bulletTime = 0;
  bombTimeAlpha = 0;
  bombTimeBeta = 0;
  bombTimeGamma = 0;
  
  monsterActive = false;
  dragonActive = false;
  
  monster = new Monster("img/monster.png");
  monster -> enemySprite.setPosition(200, 0);
  
  dragon = new Dragon("img/dragon.png");
  dragon -> enemySprite.setPosition(200, 0);
  
  ///// END OF CREATING ADDONS & BACKGROUND /////
}

void Game::losingGame()
{
  gameOverText.setPosition(250, 250);
  playAgainButton.setPosition(325, 350);
  scoresButton.setPosition(325, 400);
  quitButton.setPosition(325, 450);
}

void Game::winningGame()
{
  gameWonText.setPosition(250, 250);
  playAgainButton.setPosition(325, 350);
  scoresButton.setPosition(325, 400);
  quitButton.setPosition(325, 450);
}

void Game::displayScores()
{
  srand(time(0));
  RenderWindow window(VideoMode(780, 780), title);
  Clock clock;
  float timer = 0;

  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asSeconds(); 
    clock.restart();
    timer += time;
    
    Event event;
    while (window.pollEvent(event))
    {  
      if (event.type == Event::Closed) // If cross/close is clicked/pressed
      {
        window.close(); // Close the Game
        //outfile.close();
      }
    }
    
    window.clear(Color::Black); // Clears the screen
    
    window.draw(scoresBackground);
    window.draw(firstScoreWritten);
    window.draw(secondScoreWritten);
    window.draw(thirdScoreWritten);
    window.draw(firstScore);
    window.draw(secondScore);
    window.draw(thirdScore);
    window.draw(firstBadge);
    window.draw(secondBadge);
    window.draw(thirdBadge);
    
    
    window.display(); // Displaying all the sprites
  }
}

void Game::displayHelp()
{
  srand(time(0));
  RenderWindow window(VideoMode(780, 780), title);
  Clock clock;
  float timer = 0;

  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asSeconds(); 
    clock.restart();
    timer += time;
    
    Event event;
    while (window.pollEvent(event))
    {  
      if (event.type == Event::Closed) // If cross/close is clicked/pressed
      {
        window.close(); // Close the Game
        //outfile.close();
      }
    }
    
    window.clear(Color::Black); // Clears the screen
    
    window.draw(helpBackground);  // Seting background
    window.draw(helpText);
    
    window.display(); // Displaying all the sprites
  }
}

void Game::start_game()
{
  srand(time(0));
  RenderWindow window(VideoMode(780, 780), title);
  Clock clock;
  float timer = 0;
  backgroundMusic.play();
  backgroundMusic.setLoop(true);
  int hit = 0;
  ofstream outfile("scores.txt");

  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asSeconds(); 
    clock.restart();
    
    if (!gamePaused)
    timer += time;
    
    float mouseX;
    float mouseY;
    
    //if (!monsterActive)
    //{
      bulletTime += time;
      bombTimeAlpha += time;
      bombTimeBeta += time;
      bombTimeGamma += time;
    //}
    
    //cout << timer << endl;
    
    Event e;
    while (window.pollEvent(e))
    {  
      if (e.type == Event::Closed) // If cross/close is clicked/pressed
      {
        window.close(); // Close the Game
      }
      
      if (e.key.code == Keyboard::Escape)
      {
        gamePaused = true;
        resumeButton.setPosition(340, 340);
        resumeBackground.setPosition(200, 200);
      }
      
      else if (e.type == Event::MouseButtonPressed)
      {
        mouseX = Mouse::getPosition(window).x;
        mouseY = Mouse::getPosition(window).y;
        
        if ((mouseX >= 325 && mouseX <= 425) && (mouseY >= 400 && mouseY <= 450))
        {
          p -> clickSound.play();
          displayScores();
        }
        
        if ((mouseX >= 325 && mouseX <= 425) && (mouseY >= 450 && mouseY <= 500))
        {
          p -> clickSound.play();
          outfile.close();
          window.close();
        }
        
        if ((mouseX >= 340 && mouseX <= 440) && (mouseY >= 340 && mouseY <= 390))
        {
          if (gamePaused)
          {
            gamePaused = false;
            resumeButton.setPosition(-250, -250);
            resumeBackground.setPosition(-500, -500);
            
          }
        }
        
        if ((mouseX >= 325 && mouseX <= 425) && (mouseY >= 350 && mouseY <= 400))
        {
     
        if (gameOver)
        {
          gameOver = false;
          gameWon = false;
          monsterActive = false;
          dragonActive = false;
          p -> onFire = false;
          
          //window.close();
          timer = 0;
          
          //p -> playerSprite.setPosition(340, 650);
          
          p -> killCount = 0;
          p -> lifeCount = 3;
          
          p -> score = 0;
          p -> scoreText.setString(to_string(p -> score));
          
          p -> life1 -> sprite.setPosition(625, 10);
          p -> life2 -> sprite.setPosition(675, 10);
          p -> life3 -> sprite.setPosition(725, 10);

          invader1 -> enemySprite.setPosition(225, 150);
          //invader2 -> enemySprite.setPosition(125, 150);
          invader3 -> enemySprite.setPosition(25, 150);
          invader4 -> enemySprite.setPosition(225, 75);
          invader5 -> enemySprite.setPosition(125, 75);
          invader6 -> enemySprite.setPosition(25, 75);
          invader7 -> enemySprite.setPosition(225, 275);
          invader8 -> enemySprite.setPosition(125, 275);
          invader9 -> enemySprite.setPosition(25, 275);
          invader10 -> enemySprite.setPosition(525, 75);
          //invader11 -> enemySprite.setPosition(525, 175);
          invader12 -> enemySprite.setPosition(450, 175);
          invader13 -> enemySprite.setPosition(600, 175);
          invader14 -> enemySprite.setPosition(525, 250);
          invader15 -> enemySprite.setPosition(600, 250);
          invader16 -> enemySprite.setPosition(450, 250);
          invader17 -> enemySprite.setPosition(675, 250);
          invader18 -> enemySprite.setPosition(375, 250);
          
          collectFire1 -> sprite.setPosition(-600, -600);
          collectLife1 -> sprite.setPosition(-600, -600);
          collectDanger1 -> sprite.setPosition(-600, -600);
          
          invader1 -> hitNum = 0;
          invader1 -> secondHit = false;
          
          //invader2 -> hitNum = 0;
          //invader2 -> secondHit = false;
          
          invader3 -> hitNum = 0;
          invader3 -> secondHit = false;
          
          invader4 -> hitNum = 0;
          invader4 -> secondHit = false;
          
          invader5 -> hitNum = 0;
          invader5 -> secondHit = false;
          
          invader6 -> hitNum = 0;
          invader6 -> secondHit = false;
          
          invader7 -> hitNum = 0;
          invader7 -> secondHit = false;
          
          invader8 -> hitNum = 0;
          invader8 -> secondHit = false;
          
          invader9 -> hitNum = 0;
          invader9 -> secondHit = false;
          
          invader10 -> hitNum = 0;
          invader10 -> secondHit = false;
          
          //invader11 -> hitNum = 0;
          //invader11 -> secondHit = false;
          
          invader12 -> hitNum = 0;
          invader12 -> secondHit = false;
          
          invader13 -> hitNum = 0;
          invader13 -> secondHit = false;
          
          invader14 -> hitNum = 0;
          invader14 -> secondHit = false;
          
          invader15 -> hitNum = 0;
          invader15 -> secondHit = false;
          
          invader16 -> hitNum = 0;
          invader16 -> secondHit = false;
          
          invader17 -> hitNum = 0;
          invader17 -> secondHit = false;
          
          invader18 -> hitNum = 0;
          invader18 -> secondHit = false;
          
          invader19 -> hitNum = 0;
          invader19 -> secondHit = false;
          
          invader20 -> hitNum = 0;
          invader20 -> secondHit = false;
          
          invader21 -> hitNum = 0;
          invader21 -> secondHit = false;
          
          invader22 -> hitNum = 0;
          invader22 -> secondHit = false;
          
          invader23 -> hitNum = 0;
          invader23 -> secondHit = false;
          
          invader24 -> hitNum = 0;
          invader24 -> secondHit = false;
          
          invader25 -> hitNum = 0;
          invader25 -> secondHit = false;
          
          invader26 -> hitNum = 0;
          invader26 -> secondHit = false;
          
          invader27 -> hitNum = 0;
          invader27 -> secondHit = false;
          
          invader28 -> hitNum = 0;
          invader28 -> secondHit = false;
          
          invader29 -> hitNum = 0;
          invader29 -> secondHit = false;
          
          invader30 -> hitNum = 0;
          invader30 -> secondHit = false;
          
          invader31 -> hitNum = 0;
          invader31 -> secondHit = false;
          
          invader32 -> hitNum = 0;
          invader32 -> secondHit = false;
          
          invader33 -> hitNum = 0;
          invader33 -> secondHit = false;
          
          invader34 -> hitNum = 0;
          invader34 -> secondHit = false;
          
          invader35 -> hitNum = 0;
          invader35 -> secondHit = false;
          
          invader36 -> hitNum = 0;
          invader36 -> secondHit = false;
          
          invader37 -> hitNum = 0;
          invader37 -> secondHit = false;
          
          invader38 -> hitNum = 0;
          invader38 -> secondHit = false;
          
          invader39 -> hitNum = 0;
          invader39 -> secondHit = false;
          
          invader40 -> hitNum = 0;
          invader40 -> secondHit = false;
          
          invader41 -> hitNum = 0;
          invader41 -> secondHit = false;
          
          invader42 -> hitNum = 0;
          invader42 -> secondHit = false;
          
          invader43 -> hitNum = 0;
          invader43 -> secondHit = false;
          
          invader44 -> hitNum = 0;
          invader44 -> secondHit = false;
          
          invader45 -> hitNum = 0;
          invader45 -> secondHit = false;
          
          invader46 -> hitNum = 0;
          invader46 -> secondHit = false;
          
          invader47 -> hitNum = 0;
          invader47 -> secondHit = false;
          
          invader48 -> hitNum = 0;
          invader48 -> secondHit = false;
          
          invader49 -> hitNum = 0;
          invader49 -> secondHit = false;
          
          invader50 -> hitNum = 0;
          invader50 -> secondHit = false;
          
          invader51 -> hitNum = 0;
          invader51 -> secondHit = false;
          
          invader52 -> hitNum = 0;
          invader52 -> secondHit = false;
          
          invader53 -> hitNum = 0;
          invader53 -> secondHit = false;
          
          invader54 -> hitNum = 0;
          invader54 -> secondHit = false;
          
          invader55 -> hitNum = 0;
          invader55 -> secondHit = false;
          
          invader56 -> hitNum = 0;
          invader56 -> secondHit = false;
          
          invader57 -> hitNum = 0;
          invader57 -> secondHit = false;
          
          oneSet = false;
          twoSet = false;
          
          p -> playerSprite.setPosition(340, 700);
          p -> x_axis = 340;
          p -> y_axis = 700;
          p -> bullet1 -> setBulletPosition(p -> playerSprite.getPosition().x + 30, p -> playerSprite.getPosition().y);
          p -> bullet2 -> setBulletPosition(p -> playerSprite.getPosition().x + 30, p -> playerSprite.getPosition().y);
          p -> bullet3 -> setBulletPosition(p -> playerSprite.getPosition().x + 30, p -> playerSprite.getPosition().y);
          p -> bullet4 -> setBulletPosition(p -> playerSprite.getPosition().x + 30, p -> playerSprite.getPosition().y);

          gameOverText.setPosition(-100, -100);
          playAgainButton.setPosition(-100, -100);
          quitButton.setPosition(-100, -100);
          scoresButton.setPosition(-100, -100);
          
          window.close();
          start_game();
        }   

          
        }
      }
    }
    
    if (p -> lifeCount < 0)
    {
      gameOver = true;
    }
    
    if (p -> killCount >= 110)
    {
      gameWon = true;
    }
    
    if (gameOver)
    {
      p -> loseSound.play(); 
      p -> playerSprite.setPosition(-100, -100);
      
      if (p -> score > scoreOne)
      {
        scoreOne = p -> score;
        firstScore.setString(to_string(scoreOne));
        oneSet = true;
        
        if (outfile.is_open())
        outfile << scoreOne << endl;

        
      }
      else if (p -> score > scoreTwo && !oneSet)
      {
        scoreTwo = p -> score;
        secondScore.setString(to_string(scoreTwo));
        twoSet = true;
        
        if (outfile.is_open())
        outfile << scoreOne << endl;
        
      }
      else if (p -> score > scoreThree && !twoSet && !oneSet)
      {
        scoreThree = p -> score;
        thirdScore.setString(to_string(scoreThree));
        
        if (outfile.is_open())
        outfile << scoreOne << endl;
        
      }
    
      losingGame(); 
    }
    
    if (gameWon)
    {
      p -> winSound.play();
      winningGame();
    }
    
    ///// START OF CODING PLAYER MOVEMENT /////
    
    if (!gameOver && !gameWon && !gamePaused)
    {
      if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
      {
        p -> move("l"); // Player will move to the left
      }
    
      if (Keyboard::isKeyPressed(Keyboard::Right)) //If left key is pressed
      {
        p -> move("r"); // Player will move to the right
      }
    
      if (Keyboard::isKeyPressed(Keyboard::Up)) //If left key is pressed
      {
        p -> move("u"); // Player will move up
      }
    
      if (Keyboard::isKeyPressed(Keyboard::Down)) // If left key is pressed
      {
        p -> move("d"); // Player will move down
      }
    }
    

    
    ///// END OF CREATING PLAYER MOVEMENT /////
    
    ///// START OF CODING MONSTER & DRAGON /////
    
  if (!gamePaused)
  {
    //// D1 ////
    
    if (timer >= 25 && timer <= 26)
    {
      dragonActive = true;
    }
    
    if ((timer >= 25 && timer <= 30) && dragonActive == true)
    {
      laserTime += time;
      dragon -> fireLaser(laserTime);
      //dragon -> movedragon();
      dragon -> detectCollision(p, timer);
      dragon -> laserCollision(p, timer);
      
      if(laserTime >= 4)
      {
        laserTime = 0;
      }
    }
    
    if (timer >= 30 && timer <= 31)
    {
      dragonActive = false;
       
      if (p -> dragonCollision == false && p -> addFifty)
      {
        p -> score += 50;
        p -> scoreText.setString(to_string(p -> score));
        p -> addFifty = false;
      }
      else if (p -> dragonCollision == true)
      {
        p -> dragonCollision = false;
      }
    }
    
    if (timer >= 31 && timer <= 32)
    {
      p -> addFifty = true;
    }
    
    //// D2 ////
    
    if (timer >= 50 && timer <= 51)
    {
      dragonActive = true;
    }
    
    if ((timer >= 50 && timer <= 55) && dragonActive == true)
    {
      laserTime += time;
      dragon -> fireLaser(laserTime);
      //dragon -> movedragon();
      dragon -> detectCollision(p, timer);
      dragon -> laserCollision(p, timer);
      
      if(laserTime >= 4)
      {
        laserTime = 0;
      }
    }
    
    if (timer >= 55 && timer <= 56)
    {
      dragonActive = false;
      
      if (p -> dragonCollision == false && p -> addFifty)
      {
        p -> score += 50;
        p -> scoreText.setString(to_string(p -> score));
        p -> addFifty = false;
      }
      else if (p -> dragonCollision == true)
      {
        p -> dragonCollision = false;
      }
    }
    
    if (timer >= 56 && timer <= 57)
    {
      p -> addFifty = true;
    }
    
    //// D3 ////
    
    if (timer >= 85 && timer <= 86)
    {
      dragonActive = true;
    }
    
    if ((timer >= 85 && timer <= 90) && dragonActive == true)
    {
      laserTime += time;
      dragon -> fireLaser(laserTime);
      //dragon -> movedragon();
      dragon -> detectCollision(p, timer);
      dragon -> laserCollision(p, timer);
      
      if(laserTime >= 4)
      {
        laserTime = 0;
      }
    }
    
    if (timer >= 90 && timer <= 91)
    {
      dragonActive = false;
      
      if (p -> dragonCollision == false && p -> addFifty)
      {
        p -> score += 50;
        p -> scoreText.setString(to_string(p -> score));
        p -> addFifty = false;
      }
      else if (p -> dragonCollision == true)
      {
        p -> dragonCollision = false;
      }
    }
    
    if (timer >= 91 && timer <= 92)
    {
      p -> addFifty = true;
    }
    
    //// M1 ////
    
    if (timer >= 10 && timer <= 11)
    {
      monsterActive = true;
    }
    
    if ((timer >= 10 && timer <= 20) && monsterActive == true)
    {
      laserTime += time;
      monster -> fireLaser(laserTime);
      monster -> moveMonster();
      monster -> detectCollision(p, timer);
      monster -> laserCollision(p, timer);
      
      if(laserTime >= 4)
      {
        laserTime = 0;
      }
    }
    
    if (timer >= 20 && timer <= 21)
    {
      monsterActive = false;
      if (p -> monsterCollision == false && p -> addFifty == true)
      {
        p -> score += 50;
        p -> scoreText.setString(to_string(p -> score));
        p -> addFifty = false;
      }
      else if (p -> monsterCollision == true)
      {
        p -> monsterCollision = false;
      }
    }
    
    if (timer >= 21 && timer <= 22)
    {
      p -> addFifty = true;
    }
    
    //// M2 ////
    
    if (timer >= 35 && timer <= 36)
    {
      monsterActive = true;
    }
    
    if ((timer >= 35 && timer <= 45) && monsterActive == true)
    {
      laserTime += time;
      monster -> fireLaser(laserTime);
      monster -> moveMonster();
      monster -> detectCollision(p, timer);
      monster -> laserCollision(p, timer);
      
      if(laserTime >= 4)
      {
        laserTime = 0;
      }
    }
    
    if (timer >= 45 && timer <= 46)
    {
      monsterActive = false;
      if (p -> monsterCollision == false && p -> addFifty)
      {
        p -> score += 50;
        p -> scoreText.setString(to_string(p -> score));
        p -> addFifty = false;
      }
      else if (p -> monsterCollision == true)
      {
        p -> monsterCollision = false;
      }
    }
    
    if (timer >= 46 && timer <= 47)
    {
      p -> addFifty = true;
    }
    
    //// M3 ////
    
    if (timer >= 65 && timer <= 75)
    {
      monsterActive = true;
    }
    
    if ((timer >= 65 && timer <= 75) && monsterActive == true)
    {
      laserTime += time;
      monster -> fireLaser(laserTime);
      monster -> moveMonster();
      monster -> detectCollision(p, timer);
      monster -> laserCollision(p, timer);
      
      if(laserTime >= 4)
      {
        laserTime = 0;
      }
    }
    
    if (timer >= 75 && timer <= 76)
    {
      monsterActive = false;
      if (p -> monsterCollision == false && p -> addFifty)
      {
        p -> score += 50;
        p -> scoreText.setString(to_string(p -> score));
        p -> addFifty = false;
      }
      else if (p -> monsterCollision == true)
      {
        p -> monsterCollision = false;
      }
    }
    
    if (timer >= 76 && timer <= 77)
    {
      p -> addFifty = true;
    }
    
    //// M4 ////
    
    if (timer >= 100 && timer <= 101)
    {
      monsterActive = true;
    }
    
    if ((timer >= 100 && timer <= 110) && monsterActive == true)
    {
      laserTime += time;
      monster -> fireLaser(laserTime);
      monster -> moveMonster();
      monster -> detectCollision(p, timer);
      monster -> laserCollision(p, timer);
      
      if (laserTime >= 4)
      {
        laserTime = 0;
      }
    }
    
    if (timer >= 110 && timer <= 111)
    {
      monsterActive = false;
      if (p -> monsterCollision == false && p -> addFifty)
      {
        p -> score += 50;
        p -> scoreText.setString(to_string(p -> score));
        p -> addFifty = false;
      }
      else if (p -> monsterCollision == true)
      {
        p -> monsterCollision = false;
      }
    }
    
    if (timer >= 111 && timer <= 112)
    {
      p -> addFifty = true;
    }
  }
    

    
    ///// START OF CREATING ADDONS /////
    
  if (!gameOver && !gameWon)
  {
    // Collect Life Code
    
    ///// 1 /////
    
    if (timer >= 5 && timer <= 10 && p -> lifeCollision == false)
    {
      collectLife1 -> sprite.setPosition(400, 400);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 10 && timer <= 11)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    
    ///// 2 /////
    
    if (timer >= 16 && timer <= 21 && p -> lifeCollision == false)
    {
      collectLife1 -> sprite.setPosition(300, 425);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 21 && timer <= 22)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    
    ///// 3 /////
    
    if (timer >= 25 && timer <= 30)
    {
      collectLife1 -> sprite.setPosition(225, 415);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 30 && timer <= 31)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    
    ///// 4 /////
    
    if (timer >= 36 && timer <= 41)
    {
      collectLife1 -> sprite.setPosition(100, 400);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 41 && timer <= 42)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    

    ///// 5 /////
    
    if (timer >= 48 && timer <= 53)
    {
      collectLife1 -> sprite.setPosition(550, 450);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 53 && timer <= 54)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    
    ///// 6 /////
    
    if (timer >= 65 && timer <= 70)
    {
      collectLife1 -> sprite.setPosition(675, 400);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 70 && timer <= 71)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }

    ///// 7 /////
    
    if (timer >= 80 && timer <= 85)
    {
      collectLife1 -> sprite.setPosition(75, 400);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 85 && timer <= 86)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    
    ///// 8 /////
    
    if (timer >= 93 && timer <= 98)
    {
      collectLife1 -> sprite.setPosition(20, 400);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 98 && timer <= 99)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    
    ///// 9 /////
    
    if (timer >= 110 && timer <= 115)
    {
      collectLife1 -> sprite.setPosition(295, 400);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 115 && timer <= 116)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    
    ///// 10 /////
    
    if (timer >= 125 && timer <= 130)
    {
      collectLife1 -> sprite.setPosition(505, 400);
      p -> detectLifeCollision(collectLife1);
      if (p -> lifeCollision == true)
      {
        collectLife1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (timer >= 130 && timer <= 131)
    {
      collectLife1 -> sprite.setPosition(-100, -100);
      p -> lifeCollision = false;
    }
    
    // Collect Danger Code
    
    ///// 1 /////
    
    if ((timer >= 7 && timer <= 12) && (p -> dangerCollision == false))
    {
      collectDanger1 -> sprite.setPosition(340, 5); 
      p -> dangerActive = true;
      collectDanger1 -> sprite.setPosition(collectDanger1 -> sprite.getPosition().x, collectDanger1 -> sprite.getPosition().y + (timer * 60));
    }
    
    else if (p -> dangerCollision == true)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      hit++;
    }
    
    if (timer >= 12 && timer <= 13)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      p -> dangerCollision = false;
    }
    
    if (hit == 0 && (timer >= 12 && timer <= 13))
    {
      p -> score += 50;
      p -> scoreText.setString(to_string(p -> score));
      hit = -1;
    }
    
    if (timer >= 13 && timer <= 14)
    {
      hit = 0;
    }
    
    if (p -> dangerActive)
    {
      p -> detectDangerCollision(collectDanger1);
    }
    
    ///// 2 /////
    
    if ((timer >= 18 && timer <= 23) && (p -> dangerCollision == false))
    {
      collectDanger1 -> sprite.setPosition(150, 5); 
      p -> dangerActive = true;
      collectDanger1 -> sprite.setPosition(collectDanger1 -> sprite.getPosition().x, collectDanger1 -> sprite.getPosition().y + ((timer - 11) * 60));
    }
    else if (p -> dangerCollision == true)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      hit++;
    }
    
    if (timer >= 18 && timer <= 19)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      p -> dangerCollision = false;
    }
    
    if (hit == 0 && (timer >= 18 && timer <= 19))
    {
      p -> score += 50;
      p -> scoreText.setString(to_string(p -> score));
      hit = -1;
    }
    
    if (timer >= 19 && timer <= 20)
    {
      hit = 0;
    }
    
    if (p -> dangerActive)
    {
      p -> detectDangerCollision(collectDanger1);
    }
    
    ///// 3 /////
    
    if ((timer >= 26 && timer <= 31) && (p -> dangerCollision == false))
    {
      collectDanger1 -> sprite.setPosition(500, 5); 
      p -> dangerActive = true;
      collectDanger1 -> sprite.setPosition(collectDanger1 -> sprite.getPosition().x, collectDanger1 -> sprite.getPosition().y + ((timer - 19) * 60));
    }
    else if (p -> dangerCollision == true)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      hit++;
    }
    
    if (timer >= 31 && timer <= 32)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      p -> dangerCollision = false;
    }
    
    if (hit == 0 && (timer >= 31 && timer <= 32))
    {
      p -> score += 50;
      p -> scoreText.setString(to_string(p -> score));
      hit = -1;
    }
    
    if (timer >= 32 && timer <= 33)
    {
      hit = 0;
    }
    
    if (p -> dangerActive)
    {
      p -> detectDangerCollision(collectDanger1);
    }
    
    ///// 4 /////
    
    if ((timer >= 40 && timer <= 45) && (p -> dangerCollision == false))
    {
      collectDanger1 -> sprite.setPosition(475, 5); 
      p -> dangerActive = true;
      collectDanger1 -> sprite.setPosition(collectDanger1 -> sprite.getPosition().x, collectDanger1 -> sprite.getPosition().y + ((timer - 33) * 60));
    }
    else if (p -> dangerCollision == true)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      hit++;
    }
    
    if (timer >= 45 && timer <= 46)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      p -> dangerCollision = false;
    }
    
    if (hit == 0 && (timer >= 45 && timer <= 46))
    {
      p -> score += 50;
      p -> scoreText.setString(to_string(p -> score));
      hit = -1;
    }
    
    if (timer >= 46 && timer <= 47)
    {
      hit = 0;
    }
    
    if (p -> dangerActive)
    {
      p -> detectDangerCollision(collectDanger1);
    }
    
    ///// 5 /////
    
    if ((timer >= 55 && timer <= 60) && (p -> dangerCollision == false))
    {
      collectDanger1 -> sprite.setPosition(75, 5); 
      p -> dangerActive = true;
      collectDanger1 -> sprite.setPosition(collectDanger1 -> sprite.getPosition().x, collectDanger1 -> sprite.getPosition().y + ((timer - 48) * 60));
    }
    else if (p -> dangerCollision == true)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      hit++;
    }
    
    if (timer >= 61 && timer <= 62)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      p -> dangerCollision = false;
    }
    
    if (hit == 0 && (timer >= 61 && timer <= 62))
    {
      p -> score += 50;
      p -> scoreText.setString(to_string(p -> score));
      hit = -1;
    }
    
    if (timer >= 62 && timer <= 63)
    {
      hit = 0;
    }
    
    if (p -> dangerActive)
    {
      p -> detectDangerCollision(collectDanger1);
    }
    
    ///// 6 /////
    
    if ((timer >= 73 && timer <= 78) && (p -> dangerCollision == false))
    {
      collectDanger1 -> sprite.setPosition(340, 5); 
      p -> dangerActive = true;
      collectDanger1 -> sprite.setPosition(collectDanger1 -> sprite.getPosition().x, collectDanger1 -> sprite.getPosition().y + ((timer - 66) * 60));
    }
    else if (p -> dangerCollision == true)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      hit++;
    }
    
    if (timer >= 78 && timer <= 79)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      p -> dangerCollision = false;
    }
    
    if (hit == 0 && (timer >= 78 && timer <= 79))
    {
      p -> score += 50;
      p -> scoreText.setString(to_string(p -> score));
      hit = -1;
    }
    
    if (timer >= 79 && timer <= 80)
    {
      hit = 0;
    }
    
    if (p -> dangerActive)
    {
      p -> detectDangerCollision(collectDanger1);
    }
    
    ///// 7 /////
    
    if ((timer >= 90 && timer <= 95) && (p -> dangerCollision == false))
    {
      collectDanger1 -> sprite.setPosition(600, 5); 
      p -> dangerActive = true;
      collectDanger1 -> sprite.setPosition(collectDanger1 -> sprite.getPosition().x, collectDanger1 -> sprite.getPosition().y + ((timer - 83) * 60));
    }
    else if (p -> dangerCollision == true)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      hit++;
    }
    
    if (timer >= 95 && timer <= 96)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      p -> dangerCollision = false;
    }
    
    if (hit == 0 && (timer >= 95 && timer <= 96))
    {
      p -> score += 50;
      p -> scoreText.setString(to_string(p -> score));
      hit = -1;
    }
    
    if (timer >= 96 && timer <= 97)
    {
      hit = 0;
    }
    
    if (p -> dangerActive)
    {
      p -> detectDangerCollision(collectDanger1);
    }
    
    ///// 8 /////
    
    if ((timer >= 112 && timer <= 117) && (p -> dangerCollision == false))
    {
      collectDanger1 -> sprite.setPosition(40, 5); 
      p -> dangerActive = true;
      collectDanger1 -> sprite.setPosition(collectDanger1 -> sprite.getPosition().x, collectDanger1 -> sprite.getPosition().y + ((timer - 83) * 60));
    }
    else if (p -> dangerCollision == true)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      hit++;
    }
    
    if (timer >= 117 && timer <= 118)
    {
      collectDanger1 -> sprite.setPosition(-100, -100);
      p -> dangerCollision = false;
    }
    
    if (hit == 0 && (timer >= 117 && timer <= 118))
    {
      p -> score += 50;
      p -> scoreText.setString(to_string(p -> score));
      hit = -1;
    }
    
    if (timer >= 118 && timer <= 119)
    {
      hit = 0;
    }
    
    if (p -> dangerActive)
    {
      p -> detectDangerCollision(collectDanger1);
    }
    
    // Collect Fire Code
    
    ///// 1 /////
    
    if (timer >= 15 && timer <= 20)
    {
      collectFire1 -> sprite.setPosition(200, 400);
      //p -> fireActive = true;
      p -> detectFireCollision(collectFire1);
      
      if (p -> fireCollision == true)
      {
        collectFire1 -> sprite.setPosition(-100, -100);
        
      }
    }
    
    if (p -> fireCollision && !timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
    
    if (p -> fireCollision)
    {  
      if (timer >= timeHolder + 5)
      {
        p -> bullet1 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet1 -> bulletSprite.setTexture(p -> bullet1 -> bulletTexture);
    
        p -> bullet2 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet2 -> bulletSprite.setTexture(p -> bullet2 -> bulletTexture);
    
        p -> bullet3 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet3 -> bulletSprite.setTexture(p -> bullet3 -> bulletTexture);
    
        p -> bullet4 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet4 -> bulletSprite.setTexture(p -> bullet4 -> bulletTexture);
      
        p -> onFire = false;
      }
    }
    
    if (timer >= timeHolder + 5 && p -> fireCollision == true)
    {
      p -> fireCollision = false;
      timeChecker = false;
    }
    
    if (timer >= 20 && timer <= 21)
    {
      collectFire1 -> sprite.setPosition(-100, -100);
    }
    

    //cout << timer << endl;
    
    ///// 2 /////
    
    if (timer >= 28 && timer <= 33)
    {
      collectFire1 -> sprite.setPosition(87, 400);
      p -> fireActive = true;
      p -> detectFireCollision(collectFire1);
      
      if (p -> fireCollision == true)
      {
        collectFire1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (p -> fireCollision && !timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
    
    if (p -> fireCollision)
    {  
      if (timer >= timeHolder + 5)
      {
        p -> bullet1 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet1 -> bulletSprite.setTexture(p -> bullet1 -> bulletTexture);
    
        p -> bullet2 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet2 -> bulletSprite.setTexture(p -> bullet2 -> bulletTexture);
    
        p -> bullet3 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet3 -> bulletSprite.setTexture(p -> bullet3 -> bulletTexture);
    
        p -> bullet4 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet4 -> bulletSprite.setTexture(p -> bullet4 -> bulletTexture);
      
        p -> onFire = false;
      }
    }
    
    if (timer >= timeHolder + 5 && p -> fireCollision == true)
    {
      p -> fireCollision = false;
      timeChecker = false;
    }
    
    if (timer >= 33 && timer <= 34)
    {
      collectFire1 -> sprite.setPosition(-100, -100);
    }
    
    ///// 3 /////
    
    if (timer >= 44 && timer <= 49)
    {
      collectFire1 -> sprite.setPosition(467, 400);
      p -> fireActive = true;
      p -> detectFireCollision(collectFire1);
      
      if (p -> fireCollision == true)
      {
        collectFire1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (p -> fireCollision && !timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
    
    if (p -> fireCollision)
    {  
      if (timer >= timeHolder + 5)
      {
        p -> bullet1 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet1 -> bulletSprite.setTexture(p -> bullet1 -> bulletTexture);
    
        p -> bullet2 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet2 -> bulletSprite.setTexture(p -> bullet2 -> bulletTexture);
    
        p -> bullet3 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet3 -> bulletSprite.setTexture(p -> bullet3 -> bulletTexture);
    
        p -> bullet4 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet4 -> bulletSprite.setTexture(p -> bullet4 -> bulletTexture);
      
        p -> onFire = false;
      }
    }
    
    if (timer >= timeHolder + 5 && p -> fireCollision == true)
    {
      p -> fireCollision = false;
      timeChecker = false;
    }
    
    
    if (timer >= 49 && timer <= 50)
    {
      collectFire1 -> sprite.setPosition(-100, -100);
    }
    
    ///// 4 /////
    
    if (timer >= 60 && timer <= 65)
    {
      collectFire1 -> sprite.setPosition(189, 400);
      p -> fireActive = true;
      p -> detectFireCollision(collectFire1);
      
      if (p -> fireCollision == true)
      {
        collectFire1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (p -> fireCollision && !timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
    
    if (p -> fireCollision)
    {  
      if (timer >= timeHolder + 5)
      {
        p -> bullet1 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet1 -> bulletSprite.setTexture(p -> bullet1 -> bulletTexture);
    
        p -> bullet2 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet2 -> bulletSprite.setTexture(p -> bullet2 -> bulletTexture);
    
        p -> bullet3 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet3 -> bulletSprite.setTexture(p -> bullet3 -> bulletTexture);
    
        p -> bullet4 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet4 -> bulletSprite.setTexture(p -> bullet4 -> bulletTexture);
      
        p -> onFire = false;
      }
    }
    
    if (timer >= timeHolder + 5 && p -> fireCollision == true)
    {
      p -> fireCollision = false;
      timeChecker = false;
    }
    
    
    if (timer >= 65 && timer <= 66)
    {
      collectFire1 -> sprite.setPosition(-100, -100);
    }
    
    ///// 5 /////
    
    if (timer >= 75 && timer <= 80)
    {
      collectFire1 -> sprite.setPosition(502, 400);
      p -> fireActive = true;
      p -> detectFireCollision(collectFire1);
      
      if (p -> fireCollision == true)
      {
        collectFire1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (p -> fireCollision && !timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
    
    if (p -> fireCollision)
    {  
      if (timer >= timeHolder + 5)
      {
        p -> bullet1 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet1 -> bulletSprite.setTexture(p -> bullet1 -> bulletTexture);
    
        p -> bullet2 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet2 -> bulletSprite.setTexture(p -> bullet2 -> bulletTexture);
    
        p -> bullet3 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet3 -> bulletSprite.setTexture(p -> bullet3 -> bulletTexture);
    
        p -> bullet4 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet4 -> bulletSprite.setTexture(p -> bullet4 -> bulletTexture);
      
        p -> onFire = false;
      }
    }
    
    if (timer >= timeHolder + 5 && p -> fireCollision == true)
    {
      p -> fireCollision = false;
      timeChecker = false;
    }
    
    
    if (timer >= 80 && timer <= 81)
    {
      collectFire1 -> sprite.setPosition(-100, -100);
    }
    
    ///// 6 /////
    
    if (timer >= 89 && timer <= 94)
    {
      collectFire1 -> sprite.setPosition(53, 400);
      p -> fireActive = true;
      p -> detectFireCollision(collectFire1);
      
      if (p -> fireCollision == true)
      {
        collectFire1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (p -> fireCollision && !timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
    
    if (p -> fireCollision)
    {  
      if (timer >= timeHolder + 5)
      {
        p -> bullet1 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet1 -> bulletSprite.setTexture(p -> bullet1 -> bulletTexture);
    
        p -> bullet2 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet2 -> bulletSprite.setTexture(p -> bullet2 -> bulletTexture);
    
        p -> bullet3 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet3 -> bulletSprite.setTexture(p -> bullet3 -> bulletTexture);
    
        p -> bullet4 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet4 -> bulletSprite.setTexture(p -> bullet4 -> bulletTexture);
      
        p -> onFire = false;
      }
    }
    
    if (timer >= timeHolder + 5 && p -> fireCollision == true)
    {
      p -> fireCollision = false;
      timeChecker = false;
    }
    
    
    if (timer >= 94 && timer <= 95)
    {
      collectFire1 -> sprite.setPosition(-100, -100);
    }
    
    ///// 7 /////
    
    if (timer >= 106 && timer <= 111)
    {
      collectFire1 -> sprite.setPosition(612, 400);
      p -> fireActive = true;
      p -> detectFireCollision(collectFire1);
      
      if (p -> fireCollision == true)
      {
        collectFire1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (p -> fireCollision && !timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
    
    if (p -> fireCollision)
    {  
      if (timer >= timeHolder + 5)
      {
        p -> bullet1 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet1 -> bulletSprite.setTexture(p -> bullet1 -> bulletTexture);
    
        p -> bullet2 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet2 -> bulletSprite.setTexture(p -> bullet2 -> bulletTexture);
    
        p -> bullet3 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet3 -> bulletSprite.setTexture(p -> bullet3 -> bulletTexture);
    
        p -> bullet4 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet4 -> bulletSprite.setTexture(p -> bullet4 -> bulletTexture);
      
        p -> onFire = false;
      }
    }
    
    if (timer >= timeHolder + 5 && p -> fireCollision == true)
    {
      p -> fireCollision = false;
      timeChecker = false;
    }
    
    
    if (timer >= 111 && timer <= 112)
    {
      collectFire1 -> sprite.setPosition(-100, -100);
    }
    
    ///// 8 /////
    if (timer >= 120 && timer <= 125)
    {
      collectFire1 -> sprite.setPosition(215, 400);
      p -> fireActive = true;
      p -> detectFireCollision(collectFire1);
      
      if (p -> fireCollision == true)
      {
        collectFire1 -> sprite.setPosition(-100, -100);
      }
    }
    
    if (p -> fireCollision && !timeChecker)
    {
      timeHolder = timer;
      timeChecker = true;
    }
    
    if (p -> fireCollision)
    {  
      if (timer >= timeHolder + 5)
      {
        p -> bullet1 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet1 -> bulletSprite.setTexture(p -> bullet1 -> bulletTexture);
    
        p -> bullet2 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet2 -> bulletSprite.setTexture(p -> bullet2 -> bulletTexture);
    
        p -> bullet3 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet3 -> bulletSprite.setTexture(p -> bullet3 -> bulletTexture);
    
        p -> bullet4 -> bulletTexture.loadFromFile("img/PNG/Effects/fire18.png");
        p -> bullet4 -> bulletSprite.setTexture(p -> bullet4 -> bulletTexture);
      
        p -> onFire = false;
      }
    }
    
    if (timer >= timeHolder + 5 && p -> fireCollision == true)
    {
      p -> fireCollision = false;
      timeChecker = false;
    }
    
    
    if (timer >= 125 && timer <= 126)
    {
      collectFire1 -> sprite.setPosition(-100, -100);
    }
    
  }
  
    

    ///// END OF CREATING ADDONS /////
    
    //cout << p -> killCount << endl;
    
    ///// START CALLING YOUR FUNCTIONS HERE /////
    
    if (!gameOver && !gameWon && !gamePaused)
    {
      p -> fire(bulletTime);
    
      if (bulletTime >= 0.5)
      {
        bulletTime = 0;
      }
    }
    
    if (!monsterActive && !dragonActive)
    {
      if (invader1 -> hitNum != 1 || (levelCount == 3 && invader1 -> secondHit == false && p -> killCount >= 55))
      invader1 -> enemySprite.setPosition(225, 150);
      
      if (levelCount == 3 && invader2 -> secondHit == false && p -> killCount >= 55)
      invader2 -> enemySprite.setPosition(125, 150);
      
      if (invader3 -> hitNum != 1 || (levelCount == 3 && invader3 -> secondHit == false && p -> killCount >= 55))
      invader3 -> enemySprite.setPosition(25, 150);
      
      if (invader4 -> hitNum != 1 || (levelCount == 3 && invader4 -> secondHit == false && p -> killCount >= 55))
      invader4 -> enemySprite.setPosition(225, 75)
      ;
      if (invader5 -> hitNum != 1 || (levelCount == 3 && invader5 -> secondHit == false && p -> killCount >= 55))
      invader5 -> enemySprite.setPosition(125, 75);
      
      if (invader6 -> hitNum != 1 || (levelCount == 3 && invader6 -> secondHit == false && p -> killCount >= 55))
      invader6 -> enemySprite.setPosition(25, 75);
      
      if (invader7 -> hitNum  != 1 || (levelCount == 3 && invader7 -> secondHit == false && p -> killCount >= 55))
      invader7 -> enemySprite.setPosition(225, 275);
      
      if (invader8 -> hitNum  != 1 || (levelCount == 3 && invader8 -> secondHit == false && p -> killCount >= 55))
      invader8 -> enemySprite.setPosition(125, 275);
      
      if (invader9 -> hitNum  != 1 || (levelCount == 3 && invader9 -> secondHit == false && p -> killCount >= 55))
      invader9 -> enemySprite.setPosition(25, 275);
      
      if (invader10 -> hitNum  != 1 || (levelCount == 3 && invader10 -> secondHit == false && p -> killCount >= 55))
      invader10 -> enemySprite.setPosition(525, 75);
      
      if (levelCount == 3 && invader11 -> secondHit == false && p -> killCount >= 55)
      invader11 -> enemySprite.setPosition(525, 175);
      
      if (invader12 -> hitNum  != 1 || (levelCount == 3 && invader12 -> secondHit == false && p -> killCount >= 55))
      invader12 -> enemySprite.setPosition(450, 175);
      
      if (invader13 -> hitNum  != 1 || (levelCount == 3 && invader13 -> secondHit == false && p -> killCount >= 55))
      invader13 -> enemySprite.setPosition(600, 175);
      
      if (invader14 -> hitNum  != 1 || (levelCount == 3 && invader14 -> secondHit == false && p -> killCount >= 55))
      invader14 -> enemySprite.setPosition(525, 250);
      
      if (invader15 -> hitNum  != 1 || (levelCount == 3 && invader15 -> secondHit == false && p -> killCount >= 55))
      invader15 -> enemySprite.setPosition(600, 250);
      
      if (invader16 -> hitNum  != 1 || (levelCount == 3 && invader16 -> secondHit == false && p -> killCount >= 55))
      invader16 -> enemySprite.setPosition(450, 250);
      
      if (invader17 -> hitNum  != 1 || (levelCount == 3 && invader17 -> secondHit == false && p -> killCount >= 55))
      invader17 -> enemySprite.setPosition(675, 250);
      
      if (invader18 -> hitNum  != 1 || (levelCount == 3 && invader18 -> secondHit == false && p -> killCount >= 55))
      invader18 -> enemySprite.setPosition(375, 250);
      
      if (invader19 -> hitNum  != 1 || (levelCount == 3 && invader19 -> secondHit == false && p -> killCount >= 71))
      invader19 -> enemySprite.setPosition(50, 50);
      
      if (invader20 -> hitNum  != 1 || (levelCount == 3 && invader20 -> secondHit == false && p -> killCount >= 71))
      invader20 -> enemySprite.setPosition(500, 50);
      
      if (invader21 -> hitNum  != 1 || (levelCount == 3 && invader21 -> secondHit == false && p -> killCount >= 71))
      invader21 -> enemySprite.setPosition(400, 100);
      
      if (invader22 -> hitNum  != 1 || (levelCount == 3 && invader22 -> secondHit == false && p -> killCount >= 71))
      invader22 -> enemySprite.setPosition(150, 100);
      
      if (invader23 -> hitNum  != 1 || (levelCount == 3 && invader23 -> secondHit == false && p -> killCount >= 71))
      invader23 -> enemySprite.setPosition(275, 200); 
      
      if (invader24 -> hitNum  != 1 || (levelCount == 3 && invader24 -> secondHit == false && p -> killCount >= 71))
      invader24 -> enemySprite.setPosition(50, 350);
      
      if (invader25 -> hitNum  != 1 || (levelCount == 3 && invader25 -> secondHit == false && p -> killCount >= 71))
      invader25 -> enemySprite.setPosition(500, 350);
      
      if (invader26 -> hitNum  != 1 || (levelCount == 3 && invader26 -> secondHit == false && p -> killCount >= 71))
      invader26 -> enemySprite.setPosition(400, 250);
      
      if (invader27 -> hitNum  != 1 || (levelCount == 3 && invader27 -> secondHit == false && p -> killCount >= 71))
      invader27 -> enemySprite.setPosition(150, 250);
      
      if (invader28 -> hitNum  != 1 || (levelCount == 3 && invader28 -> secondHit == false && p -> killCount >= 80))
      invader28 -> enemySprite.setPosition(200, 75);
      
      if (invader29 -> hitNum  != 1 || (levelCount == 3 && invader29 -> secondHit == false && p -> killCount >= 80))
      invader29 -> enemySprite.setPosition(100, 75);
      
      if (invader30 -> hitNum  != 1 || (levelCount == 3 && invader30 -> secondHit == false && p -> killCount >= 80))
      invader30 -> enemySprite.setPosition(40, 140);
      
      if (invader31 -> hitNum  != 1 || (levelCount == 3 && invader31 -> secondHit == false && p -> killCount >= 80))
      invader31 -> enemySprite.setPosition(40, 225);
      
      if (invader32 -> hitNum  != 1 || (levelCount == 3 && invader32 -> secondHit == false && p -> killCount >= 80))
      invader32 -> enemySprite.setPosition(100, 300);
      
      if (invader33 -> hitNum  != 1 || (levelCount == 3 && invader33 -> secondHit == false && p -> killCount >= 80))
      invader33 -> enemySprite.setPosition(200, 300);
      
      if (invader34 -> hitNum  != 1 || (levelCount == 3 && invader34 -> secondHit == false && p -> killCount >= 80))
      invader34 -> enemySprite.setPosition(250, 150);
      
      if (invader35 -> hitNum  != 1 || (levelCount == 3 && invader35 -> secondHit == false && p -> killCount >= 80))
      invader35 -> enemySprite.setPosition(250, 225);
      
      if (invader36 -> hitNum  != 1 || (levelCount == 3 && invader36 -> secondHit == false && p -> killCount >= 80))
      invader36 -> enemySprite.setPosition(700, 150);
      
      if (invader37 -> hitNum  != 1 || (levelCount == 3 && invader37 -> secondHit == false && p -> killCount >= 80))
      invader37 -> enemySprite.setPosition(475, 100);
      
      if (invader38 -> hitNum  != 1 || (levelCount == 3 && invader38 -> secondHit == false && p -> killCount >= 80))
      invader38 -> enemySprite.setPosition(400, 150);
      
      if (invader39 -> hitNum  != 1 || (levelCount == 3 && invader39 -> secondHit == false && p -> killCount >= 80))
      invader39 -> enemySprite.setPosition(450, 225);
      
      if (invader40 -> hitNum  != 1 || (levelCount == 3 && invader40 -> secondHit == false && p -> killCount >= 80))
      invader40 -> enemySprite.setPosition(500, 300);
      
      if (invader41 -> hitNum  != 1 || (levelCount == 3 && invader41 -> secondHit == false && p -> killCount >= 80))
      invader41 -> enemySprite.setPosition(550, 375);
      
      if (invader42 -> hitNum  != 1 || (levelCount == 3 && invader42 -> secondHit == false && p -> killCount >= 80))
      invader42 -> enemySprite.setPosition(650, 225);
      
      if (invader43 -> hitNum  != 1 || (levelCount == 3 && invader43 -> secondHit == false && p -> killCount >= 80))
      invader43 -> enemySprite.setPosition(600, 300);
      
      if (invader44 -> hitNum  != 1 || (levelCount == 3 && invader44 -> secondHit == false && p -> killCount >= 80))
      invader44 -> enemySprite.setPosition(625, 100);
      
      if (invader45 -> hitNum  != 1 || (levelCount == 3 && invader45 -> secondHit == false && p -> killCount >= 80))
      invader45 -> enemySprite.setPosition(550, 150);
      
      if (invader46 -> hitNum  != 1 || (levelCount == 3 && invader46 -> secondHit == false && p -> killCount >= 98))
      invader46 -> enemySprite.setPosition(170, 100);
      
      if (invader47 -> hitNum  != 1 || (levelCount == 3 && invader47 -> secondHit == false && p -> killCount >= 98))
      invader47 -> enemySprite.setPosition(245, 100);
      
      if (invader48 -> hitNum  != 1 || (levelCount == 3 && invader48 -> secondHit == false && p -> killCount >= 98))
      invader48 -> enemySprite.setPosition(100, 150);
      
      if (invader49 -> hitNum  != 1 || (levelCount == 3 && invader49 -> secondHit == false && p -> killCount >= 98))
      invader49 -> enemySprite.setPosition(175, 225);
      
      if (invader50 -> hitNum  != 1 || (levelCount == 3 && invader50 -> secondHit == false && p -> killCount >= 98))
      invader50 -> enemySprite.setPosition(250, 300);
      
      if (invader51 -> hitNum  != 1 || (levelCount == 3 && invader51 -> secondHit == false && p -> killCount >= 98))
      invader51 -> enemySprite.setPosition(325, 375);
      
      if (invader52 -> hitNum  != 1 || (levelCount == 3 && invader52 -> secondHit == false && p -> killCount >= 98))
      invader52 -> enemySprite.setPosition(400, 300);
      
      if (invader53 -> hitNum  != 1 || (levelCount == 3 && invader53 -> secondHit == false && p -> killCount >= 98))
      invader53 -> enemySprite.setPosition(475, 225);
      
      if (invader54 -> hitNum  != 1 || (levelCount == 3 && invader54 -> secondHit == false && p -> killCount >= 98))
      invader54 -> enemySprite.setPosition(550, 150);
      
      if (invader55 -> hitNum  != 1 || (levelCount == 3 && invader55 -> secondHit == false && p -> killCount >= 98))
      invader55 -> enemySprite.setPosition(320, 100);
      
      if (invader56 -> hitNum  != 1 || (levelCount == 3 && invader56 -> secondHit == false && p -> killCount >= 98))
      invader56 -> enemySprite.setPosition(395, 100);
      
      if (invader57 -> hitNum  != 1 || (levelCount == 3 && invader57 -> secondHit == false && p -> killCount >= 98))
      invader57 -> enemySprite.setPosition(470, 100); 
    }
    
    
    
    if (monsterActive || dragonActive)
    {
      invader1 -> enemySprite.setPosition(-750, -750);
      invader2 -> enemySprite.setPosition(-750, -750);
      invader3 -> enemySprite.setPosition(-750, -750);
      invader4 -> enemySprite.setPosition(-750, -750);
      invader5 -> enemySprite.setPosition(-750, -750);
      invader6 -> enemySprite.setPosition(-750, -750);
      invader7 -> enemySprite.setPosition(-750, -750);
      invader8 -> enemySprite.setPosition(-750, -750);
      invader9 -> enemySprite.setPosition(-750, -750);
      invader10 -> enemySprite.setPosition(-750, -750);
      invader11 -> enemySprite.setPosition(-750, -750);
      invader12 -> enemySprite.setPosition(-750, -750);
      invader13 -> enemySprite.setPosition(-750, -750);
      invader14 -> enemySprite.setPosition(-750, -750);
      invader15 -> enemySprite.setPosition(-750, -750);
      invader16 -> enemySprite.setPosition(-750, -750);
      invader17 -> enemySprite.setPosition(-750, -750);
      invader18 -> enemySprite.setPosition(-750, -750);
      invader19 -> enemySprite.setPosition(-750, -750);
      invader20 -> enemySprite.setPosition(-750, -750);
      invader21 -> enemySprite.setPosition(-750, -750);
      invader22 -> enemySprite.setPosition(-750, -750);
      invader23 -> enemySprite.setPosition(-750, -750);
      invader24 -> enemySprite.setPosition(-750, -750);
      invader25 -> enemySprite.setPosition(-750, -750);
      invader26 -> enemySprite.setPosition(-750, -750);
      invader27 -> enemySprite.setPosition(-750, -750);
      invader28 -> enemySprite.setPosition(-750, -750);
      invader29 -> enemySprite.setPosition(-750, -750);
      invader30 -> enemySprite.setPosition(-750, -750);
      invader31 -> enemySprite.setPosition(-750, -750);
      invader32 -> enemySprite.setPosition(-750, -750);
      invader33 -> enemySprite.setPosition(-750, -750);
      invader34 -> enemySprite.setPosition(-750, -750);
      invader35 -> enemySprite.setPosition(-750, -750);
      invader36 -> enemySprite.setPosition(-750, -750);
      invader37 -> enemySprite.setPosition(-750, -750);
      invader38 -> enemySprite.setPosition(-750, -750);
      invader39 -> enemySprite.setPosition(-750, -750);
      invader40 -> enemySprite.setPosition(-750, -750);
      invader41 -> enemySprite.setPosition(-750, -750);
      invader42 -> enemySprite.setPosition(-750, -750);
      invader43 -> enemySprite.setPosition(-750, -750);
      invader44 -> enemySprite.setPosition(-750, -750);
      invader45 -> enemySprite.setPosition(-750, -750);
      invader46 -> enemySprite.setPosition(-750, -750);
      invader47 -> enemySprite.setPosition(-750, -750);
      invader48 -> enemySprite.setPosition(-750, -750);
      invader49 -> enemySprite.setPosition(-750, -750);
      invader50 -> enemySprite.setPosition(-750, -750);
      invader51 -> enemySprite.setPosition(-750, -750);
      invader52 -> enemySprite.setPosition(-750, -750);
      invader53 -> enemySprite.setPosition(-750, -750);
      invader54 -> enemySprite.setPosition(-750, -750);
      invader55 -> enemySprite.setPosition(-750, -750);
      invader56 -> enemySprite.setPosition(-750, -750);
      invader57 -> enemySprite.setPosition(-750, -750);
    }
    
    
    if (!gameOver && !gameWon && !gamePaused)
    {
      invader4 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader5 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader6 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader7 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader8 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader9 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader12 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader13 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
    
      invader28 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader29 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader32 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader33 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader36 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader38 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader40 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader43 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader45 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
    
      if(bombTimeAlpha >= 5)
      {
        bombTimeAlpha = 0;
      }
    
      invader1 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader3 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader10 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader14 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader15 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader16 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader17 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader18 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
    
      invader30 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader31 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
    
      invader46 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader47 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader48 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader49 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader50 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader51 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader52 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader53 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader54 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader55 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader56 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader57 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
    
      if(bombTimeBeta >= 3)
      {
        bombTimeBeta = 0;
      }
    
      invader19 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader20 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader21 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader22 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader23 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader24 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader25 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader26 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader27 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
    
      invader34 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader35 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader37 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader39 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader41 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader42 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
      invader44 -> dropBomb(bombTimeAlpha, bombTimeBeta, bombTimeGamma);
    
      if(bombTimeGamma >= 2)
      {
        bombTimeGamma = 0;
      }
    }

    
    if (!monsterActive && !dragonActive)
    {
      ///// START OF DETECTING ENEMY COLLISIONS /////
    
      if (p -> killCount < 16 || p -> killCount >= 55)
      {
        p -> detectCollision(invader1, p -> bullet1);
        p -> detectCollision(invader1, p -> bullet2);
        p -> detectCollision(invader1, p -> bullet3);
        p -> detectCollision(invader1, p -> bullet4);
        p -> detectCollision(invader3, p -> bullet1);
        p -> detectCollision(invader3, p -> bullet2);
        p -> detectCollision(invader3, p -> bullet3);
        p -> detectCollision(invader3, p -> bullet4);
        p -> detectCollision(invader4, p -> bullet1);
        p -> detectCollision(invader4, p -> bullet2);
        p -> detectCollision(invader4, p -> bullet3);
        p -> detectCollision(invader4, p -> bullet4);
        p -> detectCollision(invader5, p -> bullet1);
        p -> detectCollision(invader5, p -> bullet2);
        p -> detectCollision(invader5, p -> bullet3);
        p -> detectCollision(invader5, p -> bullet4);
        p -> detectCollision(invader6, p -> bullet1);
        p -> detectCollision(invader6, p -> bullet2);
        p -> detectCollision(invader6, p -> bullet3);
        p -> detectCollision(invader6, p -> bullet4);
        p -> detectCollision(invader7, p -> bullet1);
        p -> detectCollision(invader7, p -> bullet2);
        p -> detectCollision(invader7, p -> bullet3);
        p -> detectCollision(invader7, p -> bullet4);
        p -> detectCollision(invader8, p -> bullet1);
        p -> detectCollision(invader8, p -> bullet2);
        p -> detectCollision(invader8, p -> bullet3);
        p -> detectCollision(invader8, p -> bullet4);
        p -> detectCollision(invader9, p -> bullet1);
        p -> detectCollision(invader9, p -> bullet2);
        p -> detectCollision(invader9, p -> bullet3);
        p -> detectCollision(invader9, p -> bullet4);
    
        p -> detectCollision(invader10, p -> bullet1);
        p -> detectCollision(invader10, p -> bullet2);
        p -> detectCollision(invader10, p -> bullet3);
        p -> detectCollision(invader10, p -> bullet4);
        p -> detectCollision(invader12, p -> bullet1);
        p -> detectCollision(invader12, p -> bullet2);
        p -> detectCollision(invader12, p -> bullet3);
        p -> detectCollision(invader12, p -> bullet4);
        p -> detectCollision(invader13, p -> bullet1);
        p -> detectCollision(invader13, p -> bullet2);
        p -> detectCollision(invader13, p -> bullet3);
        p -> detectCollision(invader13, p -> bullet4);
        p -> detectCollision(invader14, p -> bullet1);
        p -> detectCollision(invader14, p -> bullet2);
        p -> detectCollision(invader14, p -> bullet3);
        p -> detectCollision(invader14, p -> bullet4);
        p -> detectCollision(invader15, p -> bullet1);
        p -> detectCollision(invader15, p -> bullet2);
        p -> detectCollision(invader15, p -> bullet3);
        p -> detectCollision(invader15, p -> bullet4);
        p -> detectCollision(invader16, p -> bullet1);
        p -> detectCollision(invader16, p -> bullet2);
        p -> detectCollision(invader16, p -> bullet3);
        p -> detectCollision(invader16, p -> bullet4);
        p -> detectCollision(invader17, p -> bullet1);
        p -> detectCollision(invader17, p -> bullet2);
        p -> detectCollision(invader17, p -> bullet3);
        p -> detectCollision(invader17, p -> bullet4);
        p -> detectCollision(invader18, p -> bullet1);
        p -> detectCollision(invader18, p -> bullet2);
        p -> detectCollision(invader18, p -> bullet3);
        p -> detectCollision(invader18, p -> bullet4);
    
        p -> detectBombCollision(invader4 -> bomb1);
        p -> detectBombCollision(invader5 -> bomb1);
        p -> detectBombCollision(invader6 -> bomb1);
        p -> detectBombCollision(invader7 -> bomb1);
        p -> detectBombCollision(invader8 -> bomb1);
        p -> detectBombCollision(invader9 -> bomb1);
        p -> detectBombCollision(invader12 -> bomb1);
        p -> detectBombCollision(invader13 -> bomb1);
    
        p -> detectBombCollision(invader1 -> bomb2);
        p -> detectBombCollision(invader3 -> bomb2);
        p -> detectBombCollision(invader10 -> bomb2);
        p -> detectBombCollision(invader14 -> bomb2);
        p -> detectBombCollision(invader15 -> bomb2);
        p -> detectBombCollision(invader16 -> bomb2);
        p -> detectBombCollision(invader17 -> bomb2);
        p -> detectBombCollision(invader18 -> bomb2);
        
        p -> detectEnemyCollision(invader1);
        p -> detectEnemyCollision(invader3);
        p -> detectEnemyCollision(invader4);
        p -> detectEnemyCollision(invader5);
        p -> detectEnemyCollision(invader6);
        p -> detectEnemyCollision(invader7);
        p -> detectEnemyCollision(invader8);
        p -> detectEnemyCollision(invader9);
        p -> detectEnemyCollision(invader10);
        
        p -> detectEnemyCollision(invader12);
        p -> detectEnemyCollision(invader13);
        p -> detectEnemyCollision(invader14);
        p -> detectEnemyCollision(invader15);
        p -> detectEnemyCollision(invader16);
        p -> detectEnemyCollision(invader17);
        p -> detectEnemyCollision(invader18);
    
      }
      
      if ( p -> killCount >= 55)
      {
        p -> detectCollision(invader2, p -> bullet1);
        p -> detectCollision(invader2, p -> bullet2);
        p -> detectCollision(invader2, p -> bullet3);
        p -> detectCollision(invader2, p -> bullet4);
        
        p -> detectCollision(invader11, p -> bullet1);
        p -> detectCollision(invader11, p -> bullet2);
        p -> detectCollision(invader11, p -> bullet3);
        p -> detectCollision(invader11, p -> bullet4);
        
        p -> detectEnemyCollision(invader2);
        p -> detectEnemyCollision(invader11);
      }
    
      if (p -> killCount >= 16 || p -> killCount >= 73)
      {
       
        p -> detectBombCollision(invader19 -> bomb3);
        p -> detectBombCollision(invader20 -> bomb3);
        p -> detectBombCollision(invader21 -> bomb3);
        p -> detectBombCollision(invader22 -> bomb3);
        p -> detectBombCollision(invader23 -> bomb3);
        p -> detectBombCollision(invader24 -> bomb3);
        p -> detectBombCollision(invader25 -> bomb3);
        p -> detectBombCollision(invader26 -> bomb3);
        p -> detectBombCollision(invader27 -> bomb3);
        
        p -> detectCollision(invader19, p -> bullet1);
        p -> detectCollision(invader19, p -> bullet2);
        p -> detectCollision(invader19, p -> bullet3);
        p -> detectCollision(invader19, p -> bullet4);
      
        p -> detectCollision(invader20, p -> bullet1);
        p -> detectCollision(invader20, p -> bullet2);
        p -> detectCollision(invader20, p -> bullet3);
        p -> detectCollision(invader20, p -> bullet4);
      
        p -> detectCollision(invader21, p -> bullet1);
        p -> detectCollision(invader21, p -> bullet2);
        p -> detectCollision(invader21, p -> bullet3);
        p -> detectCollision(invader21, p -> bullet4);
      
        p -> detectCollision(invader22, p -> bullet1);
        p -> detectCollision(invader22, p -> bullet2);
        p -> detectCollision(invader22, p -> bullet3);
        p -> detectCollision(invader22, p -> bullet4);
      
        p -> detectCollision(invader23, p -> bullet1);
        p -> detectCollision(invader23, p -> bullet2);
        p -> detectCollision(invader23, p -> bullet3);
        p -> detectCollision(invader23, p -> bullet4);
      
        p -> detectCollision(invader24, p -> bullet1);
        p -> detectCollision(invader24, p -> bullet2);
        p -> detectCollision(invader24, p -> bullet3);
        p -> detectCollision(invader24, p -> bullet4);
      
        p -> detectCollision(invader25, p -> bullet1);
        p -> detectCollision(invader25, p -> bullet2);
        p -> detectCollision(invader25, p -> bullet3);
        p -> detectCollision(invader25, p -> bullet4);
      
        p -> detectCollision(invader26, p -> bullet1);
        p -> detectCollision(invader26, p -> bullet2);
        p -> detectCollision(invader26, p -> bullet3);
        p -> detectCollision(invader26, p -> bullet4);
      
        p -> detectCollision(invader27, p -> bullet1);
        p -> detectCollision(invader27, p -> bullet2);
        p -> detectCollision(invader27, p -> bullet3);
        p -> detectCollision(invader27, p -> bullet4);
        
        
        p -> detectEnemyCollision(invader19);
        p -> detectEnemyCollision(invader20);
        p -> detectEnemyCollision(invader21);
        p -> detectEnemyCollision(invader22);
        p -> detectEnemyCollision(invader23);
        p -> detectEnemyCollision(invader24);
        p -> detectEnemyCollision(invader25);
        p -> detectEnemyCollision(invader26);
        p -> detectEnemyCollision(invader27);
        
      }
    
      if (p -> killCount >= 25 || p -> killCount >= 98)
      { 
        levelCount = 2;
        levelText.setString(to_string(levelCount));
        p -> levelUp.play();
      
        p -> detectCollision(invader28, p -> bullet1);
        p -> detectCollision(invader28, p -> bullet2);
        p -> detectCollision(invader28, p -> bullet3);
        p -> detectCollision(invader28, p -> bullet4);
      
        p -> detectCollision(invader29, p -> bullet1);
        p -> detectCollision(invader29, p -> bullet2);
        p -> detectCollision(invader29, p -> bullet3);
        p -> detectCollision(invader29, p -> bullet4);
      
        p -> detectCollision(invader30, p -> bullet1);
        p -> detectCollision(invader30, p -> bullet2);
        p -> detectCollision(invader30, p -> bullet3);
        p -> detectCollision(invader30, p -> bullet4);
      
        p -> detectCollision(invader31, p -> bullet1);
        p -> detectCollision(invader31, p -> bullet2);
        p -> detectCollision(invader31, p -> bullet3);
        p -> detectCollision(invader31, p -> bullet4);
      
        p -> detectCollision(invader32, p -> bullet1);
        p -> detectCollision(invader32, p -> bullet2);
        p -> detectCollision(invader32, p -> bullet3);
        p -> detectCollision(invader32, p -> bullet4);
      
        p -> detectCollision(invader33, p -> bullet1);
        p -> detectCollision(invader33, p -> bullet2);
        p -> detectCollision(invader33, p -> bullet3);
        p -> detectCollision(invader33, p -> bullet4);
      
        p -> detectCollision(invader34, p -> bullet1);
        p -> detectCollision(invader34, p -> bullet2);
        p -> detectCollision(invader34, p -> bullet3);
        p -> detectCollision(invader34, p -> bullet4);
      
        p -> detectCollision(invader35, p -> bullet1);
        p -> detectCollision(invader35, p -> bullet2);
        p -> detectCollision(invader35, p -> bullet3);
        p -> detectCollision(invader35, p -> bullet4);
      
        p -> detectCollision(invader36, p -> bullet1);
        p -> detectCollision(invader36, p -> bullet2);
        p -> detectCollision(invader36, p -> bullet3);
        p -> detectCollision(invader36, p -> bullet4);
      
        p -> detectCollision(invader37, p -> bullet1);
        p -> detectCollision(invader37, p -> bullet2);
        p -> detectCollision(invader37, p -> bullet3);
        p -> detectCollision(invader37, p -> bullet4);
      
        p -> detectCollision(invader38, p -> bullet1);
        p -> detectCollision(invader38, p -> bullet2);
        p -> detectCollision(invader38, p -> bullet3);
        p -> detectCollision(invader38, p -> bullet4);
      
        p -> detectCollision(invader39, p -> bullet1);
        p -> detectCollision(invader39, p -> bullet2);
        p -> detectCollision(invader39, p -> bullet3);
        p -> detectCollision(invader39, p -> bullet4);
      
        p -> detectCollision(invader40, p -> bullet1);
        p -> detectCollision(invader40, p -> bullet2);
        p -> detectCollision(invader40, p -> bullet3);
        p -> detectCollision(invader40, p -> bullet4);
      
        p -> detectCollision(invader41, p -> bullet1);
        p -> detectCollision(invader41, p -> bullet2);
        p -> detectCollision(invader41, p -> bullet3);
        p -> detectCollision(invader41, p -> bullet4);
      
        p -> detectCollision(invader42, p -> bullet1);
        p -> detectCollision(invader42, p -> bullet2);
        p -> detectCollision(invader42, p -> bullet3);
        p -> detectCollision(invader42, p -> bullet4);
      
        p -> detectCollision(invader43, p -> bullet1);
        p -> detectCollision(invader43, p -> bullet2);
        p -> detectCollision(invader43, p -> bullet3);
        p -> detectCollision(invader43, p -> bullet4);
      
        p -> detectCollision(invader44, p -> bullet1);
        p -> detectCollision(invader44, p -> bullet2);
        p -> detectCollision(invader44, p -> bullet3);
        p -> detectCollision(invader44, p -> bullet4);
      
        p -> detectCollision(invader45, p -> bullet1);
        p -> detectCollision(invader45, p -> bullet2);
        p -> detectCollision(invader45, p -> bullet3);
        p -> detectCollision(invader45, p -> bullet4);
      
        p -> detectBombCollision(invader28 -> bomb1);
        p -> detectBombCollision(invader29 -> bomb1);
        p -> detectBombCollision(invader30 -> bomb2);
        p -> detectBombCollision(invader31 -> bomb2);
        p -> detectBombCollision(invader32 -> bomb1);
        p -> detectBombCollision(invader33 -> bomb1);
        p -> detectBombCollision(invader34 -> bomb3);
        p -> detectBombCollision(invader35 -> bomb3);
    
        p -> detectBombCollision(invader36 -> bomb1);
        p -> detectBombCollision(invader37 -> bomb3);
        p -> detectBombCollision(invader38 -> bomb1);
        p -> detectBombCollision(invader39 -> bomb3);
        p -> detectBombCollision(invader40 -> bomb1);
        p -> detectBombCollision(invader41 -> bomb3);
        p -> detectBombCollision(invader42 -> bomb3);
        p -> detectBombCollision(invader43 -> bomb1);
        p -> detectBombCollision(invader44 -> bomb3);
        p -> detectBombCollision(invader45 -> bomb1);
        
        p -> detectEnemyCollision(invader28);
        p -> detectEnemyCollision(invader29);
        p -> detectEnemyCollision(invader30);
        p -> detectEnemyCollision(invader31);
        p -> detectEnemyCollision(invader32);
        p -> detectEnemyCollision(invader33);
        p -> detectEnemyCollision(invader34);
        p -> detectEnemyCollision(invader35);
        p -> detectEnemyCollision(invader36);
        p -> detectEnemyCollision(invader37);
        p -> detectEnemyCollision(invader38);
        p -> detectEnemyCollision(invader39);
        p -> detectEnemyCollision(invader40);
        p -> detectEnemyCollision(invader41);
        p -> detectEnemyCollision(invader42);
        p -> detectEnemyCollision(invader43);
        p -> detectEnemyCollision(invader44);
        p -> detectEnemyCollision(invader45);
      
      }
    
      if (p -> killCount >= 43 || p -> killCount >= 141)
      {
        p -> detectBombCollision(invader46 -> bomb2);
        p -> detectBombCollision(invader47 -> bomb2);
        p -> detectBombCollision(invader48 -> bomb2);
        p -> detectBombCollision(invader49 -> bomb2);
        p -> detectBombCollision(invader50 -> bomb2);
        p -> detectBombCollision(invader51 -> bomb2);
        p -> detectBombCollision(invader52 -> bomb2);
        p -> detectBombCollision(invader53 -> bomb2);
        p -> detectBombCollision(invader54 -> bomb2);
        p -> detectBombCollision(invader55 -> bomb2);
        p -> detectBombCollision(invader56 -> bomb2);
        p -> detectBombCollision(invader57 -> bomb2);
      
        p -> detectCollision(invader46, p -> bullet1);
        p -> detectCollision(invader46, p -> bullet2);
        p -> detectCollision(invader46, p -> bullet3);
        p -> detectCollision(invader46, p -> bullet4);
      
        p -> detectCollision(invader47, p -> bullet1);
        p -> detectCollision(invader47, p -> bullet2);
        p -> detectCollision(invader47, p -> bullet3);
        p -> detectCollision(invader47, p -> bullet4);
      
        p -> detectCollision(invader48, p -> bullet1);
        p -> detectCollision(invader48, p -> bullet2);
        p -> detectCollision(invader48, p -> bullet3);
        p -> detectCollision(invader48, p -> bullet4);
      
        p -> detectCollision(invader49, p -> bullet1);
        p -> detectCollision(invader49, p -> bullet2);
        p -> detectCollision(invader49, p -> bullet3);
        p -> detectCollision(invader49, p -> bullet4);
      
        p -> detectCollision(invader50, p -> bullet1);
        p -> detectCollision(invader50, p -> bullet2);
        p -> detectCollision(invader50, p -> bullet3);
        p -> detectCollision(invader50, p -> bullet4);
      
        p -> detectCollision(invader51, p -> bullet1);
        p -> detectCollision(invader51, p -> bullet2);
        p -> detectCollision(invader51, p -> bullet3);
        p -> detectCollision(invader51, p -> bullet4);
      
        p -> detectCollision(invader52, p -> bullet1);
        p -> detectCollision(invader52, p -> bullet2);
        p -> detectCollision(invader52, p -> bullet3);
        p -> detectCollision(invader52, p -> bullet4);
      
        p -> detectCollision(invader53, p -> bullet1);
        p -> detectCollision(invader53, p -> bullet2);
        p -> detectCollision(invader53, p -> bullet3);
        p -> detectCollision(invader53, p -> bullet4);
      
        p -> detectCollision(invader54, p -> bullet1);
        p -> detectCollision(invader54, p -> bullet2);
        p -> detectCollision(invader54, p -> bullet3);
        p -> detectCollision(invader54, p -> bullet4);
      
        p -> detectCollision(invader55, p -> bullet1);
        p -> detectCollision(invader55, p -> bullet2);
        p -> detectCollision(invader55, p -> bullet3);
        p -> detectCollision(invader55, p -> bullet4);
      
        p -> detectCollision(invader56, p -> bullet1);
        p -> detectCollision(invader56, p -> bullet2);
        p -> detectCollision(invader56, p -> bullet3);
        p -> detectCollision(invader56, p -> bullet4);
      
        p -> detectCollision(invader57, p -> bullet1);
        p -> detectCollision(invader57, p -> bullet2);
        p -> detectCollision(invader57, p -> bullet3);
        p -> detectCollision(invader57, p -> bullet4);
        
        p -> detectEnemyCollision(invader46);
        p -> detectEnemyCollision(invader47);
        p -> detectEnemyCollision(invader48);
        p -> detectEnemyCollision(invader49);
        p -> detectEnemyCollision(invader50);
        p -> detectEnemyCollision(invader51);
        p -> detectEnemyCollision(invader52);
        p -> detectEnemyCollision(invader53);
        p -> detectEnemyCollision(invader54);
        p -> detectEnemyCollision(invader55);
        p -> detectEnemyCollision(invader56);
        p -> detectEnemyCollision(invader57);
      }
    }
    
    if (p -> killCount >= 55)
    {
      levelCount = 3;
      levelText.setString(to_string(levelCount));
      p -> levelUp.play();
    }
    
    ///// END OF DETECTING ENEMY COLLISIONS /////

    ///// END CALLING YOUR FUNCTIONS HERE /////

    window.clear(Color::Black); // Clears the screen
    
    window.draw(background);  // Seting background
    window.draw(p -> playerSprite);   // Setting player on screen
    
    window.draw(gameOverText);
    window.draw(gameWonText);
    window.draw(playAgainButton);
    window.draw(quitButton);
    

    
    window.draw(p -> scoreText);
    window.draw(scoreWritten);
    window.draw(levelWritten);
    window.draw(levelText);
    
    window.draw(p -> life1 -> sprite);
    window.draw(p -> life2 -> sprite);
    window.draw(p -> life3 -> sprite);
    

    
  if (!gameOver && !gameWon)
  {
    window.draw(collectLife1 -> sprite);
    window.draw(collectDanger1 -> sprite);
    window.draw(collectFire1 -> sprite);
    
    window.draw(p -> bullet1 -> bulletSprite);
    window.draw(p -> bullet2 -> bulletSprite);
    window.draw(p -> bullet3 -> bulletSprite);
    window.draw(p -> bullet4 -> bulletSprite);
  
    if (p -> killCount < 16 || p -> killCount >= 55)
    {
      window.draw(invader1 -> enemySprite);
      window.draw(invader3 -> enemySprite);
      window.draw(invader4 -> enemySprite);
      window.draw(invader5 -> enemySprite);
      window.draw(invader6 -> enemySprite);
      window.draw(invader7 -> enemySprite);
      window.draw(invader8 -> enemySprite);
      window.draw(invader9 -> enemySprite);
    
      window.draw(invader10 -> enemySprite);
      window.draw(invader12 -> enemySprite);
      window.draw(invader13 -> enemySprite);
      window.draw(invader14 -> enemySprite);
      window.draw(invader15 -> enemySprite);
      window.draw(invader16 -> enemySprite);
      window.draw(invader17 -> enemySprite);
      window.draw(invader18 -> enemySprite);
    
      // drawing bombs
      window.draw(invader1 -> bomb2 -> bombSprite);
      window.draw(invader3 -> bomb2 -> bombSprite);
      window.draw(invader4 -> bomb1 -> bombSprite);
      window.draw(invader5 -> bomb1 -> bombSprite);
      window.draw(invader6 -> bomb1 -> bombSprite);
      window.draw(invader7 -> bomb1 -> bombSprite);
      window.draw(invader8 -> bomb1 -> bombSprite);
      window.draw(invader9 -> bomb1 -> bombSprite);
      window.draw(invader10 -> bomb2 -> bombSprite);
      window.draw(invader12 -> bomb1 -> bombSprite);
      window.draw(invader13 -> bomb1 -> bombSprite);
      window.draw(invader14 -> bomb2 -> bombSprite);
      window.draw(invader15 -> bomb2 -> bombSprite);
      window.draw(invader16 -> bomb2 -> bombSprite);
      window.draw(invader17 -> bomb2 -> bombSprite);
      window.draw(invader18 -> bomb2 -> bombSprite);
    }
    
    if (p -> killCount >= 55)
    {
      window.draw(invader2 -> enemySprite);
      window.draw(invader11 -> enemySprite);
      window.draw(invader2 -> bomb2 -> bombSprite);
      window.draw(invader11 -> bomb1 -> bombSprite);
    }
    
    if (p -> killCount >= 16 || p -> killCount >= 73)
    {
      
      window.draw(invader19 -> enemySprite);
      window.draw(invader20 -> enemySprite);
      window.draw(invader21 -> enemySprite);
      window.draw(invader22 -> enemySprite);
      window.draw(invader23 -> enemySprite);
      window.draw(invader24 -> enemySprite);
      window.draw(invader25 -> enemySprite);
      window.draw(invader26 -> enemySprite);
      window.draw(invader27 -> enemySprite);
      
      window.draw(invader19 -> bomb3 -> bombSprite);
      window.draw(invader20 -> bomb3 -> bombSprite);
      window.draw(invader21 -> bomb3 -> bombSprite);
      window.draw(invader22 -> bomb3 -> bombSprite);
      window.draw(invader23 -> bomb3 -> bombSprite);
      window.draw(invader24 -> bomb3 -> bombSprite);
      window.draw(invader25 -> bomb3 -> bombSprite);
      window.draw(invader26 -> bomb3 -> bombSprite);
      window.draw(invader27 -> bomb3 -> bombSprite);
      
    }
    
    if (p -> killCount >= 25 || p -> killCount >= 98)
    {
      
      window.draw(invader28 -> enemySprite);
      window.draw(invader29 -> enemySprite);
      window.draw(invader30 -> enemySprite);
      window.draw(invader31 -> enemySprite);
      window.draw(invader32 -> enemySprite);
      window.draw(invader33 -> enemySprite);
      window.draw(invader34 -> enemySprite);
      window.draw(invader35 -> enemySprite);
      window.draw(invader36 -> enemySprite);
      window.draw(invader37 -> enemySprite);
      window.draw(invader38 -> enemySprite);
      window.draw(invader39 -> enemySprite);
      window.draw(invader40 -> enemySprite);
      window.draw(invader41 -> enemySprite);
      window.draw(invader42 -> enemySprite);
      window.draw(invader43 -> enemySprite);
      window.draw(invader44 -> enemySprite);
      window.draw(invader45 -> enemySprite);
      
      window.draw(invader28 -> bomb1 -> bombSprite);
      window.draw(invader29 -> bomb1 -> bombSprite);
      window.draw(invader30 -> bomb2 -> bombSprite);
      window.draw(invader31 -> bomb2 -> bombSprite);
      window.draw(invader32 -> bomb1 -> bombSprite);
      window.draw(invader33 -> bomb1 -> bombSprite);
      window.draw(invader34 -> bomb3 -> bombSprite);
      window.draw(invader35 -> bomb3 -> bombSprite);
      
      window.draw(invader36 -> bomb1 -> bombSprite);
      window.draw(invader37 -> bomb3 -> bombSprite);
      window.draw(invader38 -> bomb1 -> bombSprite);
      window.draw(invader39 -> bomb3 -> bombSprite);
      window.draw(invader40 -> bomb1 -> bombSprite);
      window.draw(invader41 -> bomb3 -> bombSprite);
      window.draw(invader42 -> bomb3 -> bombSprite);
      window.draw(invader43 -> bomb1 -> bombSprite);
      window.draw(invader44 -> bomb3 -> bombSprite);
      window.draw(invader45 -> bomb1 -> bombSprite);
      
    }
    
    if (p -> killCount >= 43 || p -> killCount >= 141)
    {
      window.draw(invader46 -> enemySprite);
      window.draw(invader47 -> enemySprite);
      window.draw(invader48 -> enemySprite);
      window.draw(invader49 -> enemySprite);
      window.draw(invader50 -> enemySprite);
      window.draw(invader51 -> enemySprite);
      window.draw(invader52 -> enemySprite);
      window.draw(invader53 -> enemySprite);
      window.draw(invader54 -> enemySprite);
      window.draw(invader55 -> enemySprite);
      window.draw(invader56 -> enemySprite);
      window.draw(invader57 -> enemySprite);
      
      window.draw(invader46 -> bomb2 -> bombSprite);
      window.draw(invader47 -> bomb2 -> bombSprite);
      window.draw(invader48 -> bomb2 -> bombSprite);
      window.draw(invader49 -> bomb2 -> bombSprite);
      window.draw(invader50 -> bomb2 -> bombSprite);
      window.draw(invader51 -> bomb2 -> bombSprite);
      window.draw(invader52 -> bomb2 -> bombSprite);
      window.draw(invader53 -> bomb2 -> bombSprite);
      window.draw(invader54 -> bomb2 -> bombSprite);
      window.draw(invader55 -> bomb2 -> bombSprite);
      window.draw(invader56 -> bomb2 -> bombSprite);
      window.draw(invader57 -> bomb2 -> bombSprite);
      
    }
  }
    
      window.draw(scoresButton);
      window.draw(resumeBackground);
      window.draw(resumeButton);
    
    if (!gameOver && !gameWon)
    {
      if ((timer >= 10 && timer <= 20) && monsterActive == true)
      {
        window.draw(monster -> enemySprite);
        window.draw(monster -> laser -> laserSprite);
      }
    
      if ((timer >= 35 && timer <= 45) && monsterActive == true)
      {
        window.draw(monster -> enemySprite);
        window.draw(monster -> laser -> laserSprite);
      }
    
      if ((timer >= 65 && timer <= 75) && monsterActive == true)
      {
        window.draw(monster -> enemySprite);
        window.draw(monster -> laser -> laserSprite);
      }
    
      if ((timer >= 100 && timer <= 110) && monsterActive == true)
      {
        window.draw(monster -> enemySprite);
        window.draw(monster -> laser -> laserSprite);
      }
      
      /// DRAGON ///
      
      if ((timer >= 25 && timer <= 30) && dragonActive == true)   
      {
        window.draw(dragon -> enemySprite);
        window.draw(dragon -> laser -> laserSprite);
      }
    
      if ((timer >= 50 && timer <= 55) && dragonActive == true)
      {
        window.draw(dragon -> enemySprite);
        window.draw(dragon -> laser -> laserSprite);
      }
    
      if ((timer >= 85 && timer <= 90) && dragonActive == true)
      {
        window.draw(dragon -> enemySprite);
        window.draw(dragon -> laser -> laserSprite);
      }
    }
    

    
    window.display(); // Displaying all the sprites
  }
}

