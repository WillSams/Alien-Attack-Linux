#ifndef GAME_H_DEFINED
#define GAME_H_DEFINED

#include "Eskeletor.h"
#include "GameObjectFactory.h"
#include "GameOverState.h"
#include "GameStateMachine.h"
#include "InputHandler.h"
#include "Level1Boss.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "Player.h"
#include "RoofTurret.h"
#include "ScrollingBackground.h"
#include "ShotGlider.h"
#include "SoundManager.h"
#include "TextureManager.h"

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

class Game {
private:
  bool m_bChangingState;

  SDL_Window *m_pWindow;
  SDL_Renderer *m_pRenderer;

  GameStateMachine *m_pGameStateMachine;

  bool m_bRunning;

  static Game *s_pInstance;

  int m_gameWidth;
  int m_gameHeight;
  float m_scrollSpeed;

  int m_playerLives;

  int m_currentLevel;
  int m_nextLevel;
  bool m_bLevelComplete;

  std::vector<std::string> m_levelFiles;

public:
  static Game *Instance();

  SDL_Renderer *getRenderer() const;
  SDL_Window *getWindow() const;
  GameStateMachine *getStateMachine();

  void setPlayerLives(int lives);
  int getPlayerLives();

  void setCurrentLevel(int currentLevel);
  const int getCurrentLevel();

  void setNextLevel(int nextLevel);
  const int getNextLevel();

  void setLevelComplete(bool levelComplete);
  const bool getLevelComplete();

  bool running();
  void quit();

  int getGameWidth() const;
  int getGameHeight() const;
  float getScrollSpeed();

  bool changingState();
  void changingState(bool cs);

  std::vector<std::string> getLevelFiles();

  // member functions
private:
  Game();
  ~Game();

  Game(const Game &);
  Game &operator=(const Game &);

public:
  bool init(const char *title, int xpos, int ypos, int width, int height,
            bool fullscreen);

  void render();
  void update();
  void handleEvents();
  void clean();
};

typedef Game TheGame;

#endif /* defined(GAME_H_DEFINED) */
