# Dragon Battle (SFML) 🐉

### A 2D space shooter / arcade survival game built in C++ using SFML. Pilot a spaceship, fire continuously, dodge enemy attacks, survive timed waves (monster + dragon), collect power-ups, avoid hazards, and chase high scores.


## 📌 Project Highlights

#### Dragon Battle is an OOP-based SFML game where you control a player ship inside a scrolling space setting. Enemies and hazards spawn on timers, bosses appear in waves, and the game rewards you for surviving patterns and avoiding damage. This project is structured with multiple C++ classes (Player, Enemies, Bullets, Lasers, Addons, Bombs, Fire, Danger, Lives, Menu, Game flow, etc.) and SFML assets for sprites + sound effects.


## ✨ Features

#### ✅ Main Menu UI (Play / Help / Scores / Exit)
#### ✅ SFML Graphics + Audio (textures, music, SFX)
#### ✅ Player ship movement (arrow keys)
#### ✅ Continuous firing system (timed bullets)
#### ✅ Multiple enemy types (Alpha / Beta / Gamma invaders + Monster + Dragon)
#### ✅ Enemy lasers / attacks (including boss patterns)
#### ✅ Pickups / Addons (collectible boosts)
#### ✅ Hazards (danger objects, fire, bombs)
#### ✅ Lives system (damage & game-over flow)
#### ✅ Score tracking + High score file (scores.txt)
#### ✅ Win/Lose screens and pause flow (Escape)


## 🎮 Controls

#### • ⬅ Left Arrow → Move left
#### • ➡ Right Arrow → Move right
#### • ⬆ Up Arrow → Move up
#### • ⬇ Down Arrow → Move down
#### • Esc → Pause / resume flow (menu overlay)


## 🧠 Core Gameplay Loop

### 1) Start from Menu
#### main.cpp creates a Menu object and runs display_menu()

### 2) Game Session
#### The Game class handles:
#### • Spawning enemies and bosses on time-based waves
#### • Updating player movement and firing
#### • Checking collisions (player ↔ enemy attacks, bullets ↔ enemies, player ↔ hazards, player ↔ addons)
#### • Updating score, lives, level text, and end-game screens


### 3) Scoring
#### From the in-code scoring logic, points are awarded in several timed scenarios, including:
##### • Dodging boss / monster encounters (example: +50 when you survive a timed wave without collision)
##### • Successfully avoiding “danger” hazards (example: +50 when a danger event completes without a hit)
##### • Collecting addons / pickups (reward events + sound cues)


## 📂 Project Structure

###### Dragon-Battle-SFML/
###### ├── main.cpp                 # Entry point (launches Menu)
###### ├── menu.h / menu.cpp        # Main menu UI + navigation
###### ├── game.h / game.cpp        # Core game loop, waves, logic, scoring, UI
###### │
###### ├── player.h / player.cpp    # Player ship, movement, firing, collisions, lives
###### ├── bullet.h / bullet.cpp    # Bullet behavior + movement
###### ├── laser.h / laser.cpp      # Laser attacks (enemy/boss)
###### │
###### ├── enemy.h / enemy.cpp      # Abstract enemy base
###### ├── invader.h / invader.cpp  # Invader logic (Alpha/Beta/Gamma derived)
###### ├── alpha.* / beta.* / gamma.*  # Enemy variants
###### ├── gaints.h / gaints.cpp    # Monster logic (name kept as in project)
###### ├── dragon.h / dragon.cpp    # Dragon boss logic
###### │
###### ├── addon.* / addons.*       # Powerups / collectibles
###### ├── danger.*                # Hazard object
###### ├── fire.*                  # Fire hazard / attack
###### ├── bomb.*                  # Bomb hazard / attack
###### ├── lives.*                 # Life sprites / life handling
###### │
###### ├── img/                    # Sprites, backgrounds, UI images, audio
###### └── scores.txt              # Persistent scores / leaderboard storage

## ✅ Requirements

#### • C++ compiler (g++, MinGW, clang, MSVC)
#### • SFML (Graphics, Window, System, Audio)


## 🛠️ Build & Run

#### This project includes some .cpp files inside headers (for example menu.h includes game.cpp, and main.cpp includes menu.cpp). Because of that structure, compiling only main.cpp is often enough.

##### Windows (PowerShell / CMD):
###### g++ main.cpp -o DragonBattle -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio .\DragonBattle.exe

##### Linux:
###### g++ main.cpp -o DragonBattle -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio ./DragonBattle


## 📁 Assets & Audio

#### • Backgrounds and UI sprites
#### • Player ship textures + damage sprites
#### • Enemy sprites (invaders, monster, dragon)
#### • Attack sprites (laser, fire, bomb, explosions)
#### • Audio files (.ogg) for clicks, hits, level-up, collecting addons, music, etc.


## 💾 Scores / Leaderboard

#### • High scores are stored in scores.txt
#### • The game reads/writes scores to display in the “Scores” screen from the menu.


## 🔧 Notes on Code Structure

#### Some .cpp files are included directly inside headers (example: menu.h includes game.cpp). This is unusual in C++ and not recommended for large projects, but it works for class projects.

#### If you want to clean it up later:
##### • Convert .cpp includes into proper compilation units
##### • Create a Makefile / CMakeLists.txt
##### • Compile all .cpp files normally


## 🗺️ Roadmap / Improvements

#### • Add shoot button option (manual fire)
#### • Add enemy wave variety + difficulty scaling
#### • Add settings (volume, controls)
#### • Add particle effects and better explosion animations
#### • Add CMake build setup
#### • Refactor to standard compilation structure (no .cpp includes in headers)


## 👤 Author
#### Hammad Muhammad Siddique
