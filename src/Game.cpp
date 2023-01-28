#include "Game.h"

Game::Game()
    : m_pWindow(), m_pRenderer(), m_bRunning(false), m_pGameStateMachine(),
      m_playerLives(3), m_scrollSpeed(0.8), m_bLevelComplete(false),
      m_bChangingState(false), m_pSoundManager(), m_pTextureManager(),
      m_pGameObjFactory(), m_pInputHandler() {

  // add some level files to an array
  m_levelFiles.push_back(DATA_PREFIX "gfx/map1.tmx");
  m_levelFiles.push_back(DATA_PREFIX "gfx/map2.tmx");

  // start at this level
  m_currentLevel = 1;
}

Game::~Game() { // we must clean up after ourselves to prevent memory leaks
  m_pGameStateMachine = nullptr;
}

SDL_Renderer *Game::getRenderer() const { return m_pRenderer; }
SDL_Window *Game::getWindow() const { return m_pWindow; }
GameStateMachine *Game::getStateMachine() { return m_pGameStateMachine; }
void Game::setPlayerLives(int lives) { m_playerLives = lives; }
int Game::getPlayerLives() { return m_playerLives; }

void Game::setCurrentLevel(int currentLevel) {
  m_currentLevel = currentLevel;
  m_pGameStateMachine->changeState(new GameOverState());
  m_bLevelComplete = false;
}
const int Game::getCurrentLevel() { return m_currentLevel; }

void Game::setNextLevel(int nextLevel) { m_nextLevel = nextLevel; }
const int Game::getNextLevel() { return m_nextLevel; }

void Game::setLevelComplete(bool levelComplete) {
  m_bLevelComplete = levelComplete;
}
const bool Game::getLevelComplete() { return m_bLevelComplete; }

bool Game::running() { return m_bRunning; }

void Game::quit() { m_bRunning = false; }

int Game::getGameWidth() const { return m_gameWidth; }
int Game::getGameHeight() const { return m_gameHeight; }
float Game::getScrollSpeed() { return m_scrollSpeed; }

bool Game::changingState() { return m_bChangingState; }
void Game::changingState(bool cs) { m_bChangingState = cs; }

std::vector<std::string> Game::getLevelFiles() { return m_levelFiles; }

bool Game::init(const char *title, int xpos, int ypos, int width, int height,
                bool fullscreen) {

  int flags = 0;

  // store the game width and height
  m_gameWidth = width;
  m_gameHeight = height;

  if (fullscreen) {
    flags = SDL_WINDOW_FULLSCREEN;
  }

  // attempt to initialise SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "SDL init success\n";
    // init the window
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

    if (m_pWindow != 0) { // window init success
      std::cout << "window creation success\n";
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

      if (m_pRenderer != 0) { // renderer init success
        std::cout << "renderer creation success\n";
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
      } else {
        std::cout << "renderer init fail\n";
        return false; // renderer init fail
      }
    } else {
      std::cout << "window init fail\n";
      return false; // window init fail
    }
  } else {
    std::cout << "SDL init fail\n";
    return false; // SDL init fail
  }

  // initialise the texture manager
  m_pTextureManager = std::make_shared<TextureManager>();

  // add some sound effects
  m_pSoundManager = std::make_shared<SoundManager>();
  m_pSoundManager->load("DST_ElectroRock.ogg", "music1", SOUND_MUSIC);
  m_pSoundManager->load("boom.wav", "explode", SOUND_SFX);
  m_pSoundManager->load("phaser.wav", "shoot", SOUND_SFX);

  m_pSoundManager->playMusic("music1", -1);

  // initialise the input handler
  m_pInputHandler = std::make_shared<InputHandler>();
  // inputHandler->initialiseJoysticks();

  // register the types for the game
  m_pGameObjFactory = std::make_shared<GameObjectFactory>();
  m_pGameObjFactory->registerType("MenuButton",
                                  new MenuButtonCreator(m_pInputHandler));
  m_pGameObjFactory->registerType("Player", new PlayerCreator());
  m_pGameObjFactory->registerType("ScrollingBackground",
                                  new ScrollingBackgroundCreator());
  m_pGameObjFactory->registerType("Turret", new TurretCreator());
  m_pGameObjFactory->registerType("Glider", new GliderCreator());
  m_pGameObjFactory->registerType("ShotGlider", new ShotGliderCreator());
  m_pGameObjFactory->registerType("RoofTurret", new RoofTurretCreator());
  m_pGameObjFactory->registerType("Eskeletor", new EskeletorCreator());
  m_pGameObjFactory->registerType("Level1Boss", new Level1BossCreator());

  // start the menu state
  m_pGameStateMachine = new GameStateMachine();
  m_pGameStateMachine->changeState(new MainMenuState());

  m_bRunning = true; // everything inited successfully, start the main loop
  return true;
}

void Game::render() {
  SDL_RenderClear(m_pRenderer);
  m_pGameStateMachine->render();
  SDL_RenderPresent(m_pRenderer);
}

void Game::update() { m_pGameStateMachine->update(); }

void Game::handleEvents() { m_pInputHandler->update(); }

void Game::clean() {
  std::cout << "cleaning game\n";

  m_pInputHandler->clean();
  m_pTextureManager->clearTextureMap();
  m_pSoundManager->clearSoundMap();

  m_pGameStateMachine->clean();
  delete m_pGameStateMachine;

  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}
