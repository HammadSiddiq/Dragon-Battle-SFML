#include "menu.h"

Menu::Menu()
{

  if (!buffer.loadFromFile("img/music.ogg"))
  {
    cout << "Error! Background Music not loaded correctly" << endl;
  }

  if (!buttonFont.loadFromFile("img/spaceshooter_font.ttf"))
  {
    cout << "Error! Score font not loaded correctly" << endl;
  }
  
  if (!clickBuffer.loadFromFile("img/Click.ogg"))
  {
    cout << "Error! Click Music not loaded correctly" << endl;
  }
  
  clickSound.setBuffer(clickBuffer);
  clickSound.setVolume(50); // Set the volume to 50% (0 to 100)
  clickSound.setPitch(1); // Increase the pitch by 50%
  clickSound.setLoop(false); // Enable looping

  backgroundTexture.loadFromFile("img/background_1.png");
  backgroundSprite.setTexture(backgroundTexture);
  backgroundSprite.setScale(2, 1.5);

  gameText.setFont(buttonFont);
  gameText.setCharacterSize(50);
  gameText.setFillColor(sf::Color::Red);
  gameText.setPosition(125, 50);
  gameText.setString("WELCOME TO SPACE SHOOTER!");

  playText.setFont(buttonFont);
  playText.setCharacterSize(40);
  playText.setFillColor(sf::Color::White);
  playText.setPosition(340, 290);
  playText.setString("[PLAY]");
  
  helpText.setFont(buttonFont);
  helpText.setCharacterSize(40);
  helpText.setFillColor(sf::Color::White);
  helpText.setPosition(340, 360);
  helpText.setString("[HELP]");
  
  scoresText.setFont(buttonFont);
  scoresText.setCharacterSize(40);
  scoresText.setFillColor(sf::Color::White);
  scoresText.setPosition(340, 430);
  scoresText.setString("[SCORES]");
  
  exitText.setFont(buttonFont);
  exitText.setCharacterSize(40);
  exitText.setFillColor(sf::Color::White);
  exitText.setPosition(340, 500);
  exitText.setString("[EXIT]");
  
  backgroundMusic.setBuffer(buffer);
  backgroundMusic.setVolume(50); // Set the volume to 50% (0 to 100)
  backgroundMusic.setPitch(1); // Increase the pitch by 50%
  backgroundMusic.setLoop(true); // Enable looping
  

}

void Menu::display_menu()
{
  srand(time(0));
  RenderWindow window(VideoMode(780, 780), title);
  Clock clock;
  float timer = 0;
  float mouseX;
  float mouseY;
  Game g;
  
  
  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asSeconds(); 
    clock.restart();
    timer += time;
    
    //backgroundMusic.setLoop(true);
    //backgroundMusic.play();
    
    
    Event event;
    while (window.pollEvent(event))
    {  
      if (event.type == Event::Closed) // If cross/close is clicked/pressed
      {
        window.close(); // Close the Game
      }
      
      else if (event.type == Event::MouseButtonPressed)
      {
        mouseX = Mouse::getPosition(window).x;
        mouseY = Mouse::getPosition(window).y;
        
        if ((mouseX >= 340 && mouseX <= 440) && (mouseY >= 290 && mouseY <= 340))
        {
          clickSound.play();
          window.close();
          g.start_game();
        }
        
        if ((mouseX >= 340 && mouseX <= 440) && (mouseY >= 360 && mouseY <= 410))
        {
          clickSound.play();
          //window.close();
          g.displayHelp();
        }
        
        if ((mouseX >= 340 && mouseX <= 440) && (mouseY >= 430 && mouseY <= 480))
        {
          clickSound.play();
          //window.close();
          g.displayScores();
        }
        
        if ((mouseX >= 340 && mouseX <= 440) && (mouseY >= 500 && mouseY <= 550))
        {
          clickSound.play();
          window.close();
        }
      }
    }
    window.clear(Color::Black); // Clears the screen
    
    window.draw(backgroundSprite);  // Seting background
    window.draw(gameText);
    window.draw(playText);
    window.draw(helpText);
    window.draw(scoresText);
    window.draw(exitText);
    
    window.display(); // Displaying all the sprites 
  }
}
