#include "Game.h"

Game* Game::s_pInstance = 0;

 Game* Game::Instance() {
    if(s_pInstance == 0) {
        s_pInstance = new Game();
        return s_pInstance;
    }

    return s_pInstance;
}

Game::Game():
    m_pWindow(),
    m_pRenderer(),
    m_bRunning(false),
    m_pGameStateMachine(),
    m_playerLives(3),
    m_scrollSpeed(0.8),
    m_bLevelComplete(false),
    m_bChangingState(false) {
    
    // add some level files to an array
    m_levelFiles.push_back("data/gfx/map1.tmx");
    m_levelFiles.push_back("data/gfx/map2.tmx");
    
    // start at this level
    m_currentLevel = 1;
}

Game::~Game() {          // we must clean up after ourselves to prevent memory leaks    
    m_pGameStateMachine = nullptr;
}

SDL_Renderer* Game::getRenderer() const { return m_pRenderer; }
SDL_Window* Game::getWindow() const { return m_pWindow; }
GameStateMachine* Game::getStateMachine() { return m_pGameStateMachine; }
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

void Game::setLevelComplete(bool levelComplete) { m_bLevelComplete = levelComplete; }
const bool Game::getLevelComplete() { return m_bLevelComplete; }

bool Game::running() { return m_bRunning; }

void Game::quit() { m_bRunning = false; }

int Game::getGameWidth() const { return m_gameWidth; }
int Game::getGameHeight() const { return m_gameHeight; }
float Game::getScrollSpeed() { return m_scrollSpeed; }

bool Game::changingState() { return m_bChangingState; }
void Game::changingState(bool cs) { m_bChangingState = cs; }

std::vector<std::string> Game::getLevelFiles() { return m_levelFiles; }

bool Game::init(const char* title, int xpos, int ypos, int width, int height, 
    bool fullscreen) {
    
    int flags = 0;
    
    // store the game width and height
    m_gameWidth = width;
    m_gameHeight = height;
    
    if(fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }
    
    // attempt to initialise SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        
        if(m_pWindow != 0) {    // window init success
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
            
            if(m_pRenderer != 0) {      // renderer init success            
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0,0,0,255);
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
    
    // add some sound effects - TODO move to better place
    TheSoundManager::Instance()->load("DST_ElectroRock.ogg", "music1", SOUND_MUSIC);
    TheSoundManager::Instance()->load("boom.wav", "explode", SOUND_SFX);
    TheSoundManager::Instance()->load("phaser.wav", "shoot", SOUND_SFX);
    
    TheSoundManager::Instance()->playMusic("music1", -1);
    
    //TheInputHandler::Instance()->initialiseJoysticks();
    
    // register the types for the game
    TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
    TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
    TheGameObjectFactory::Instance()->registerType("ScrollingBackground", new ScrollingBackgroundCreator());
    TheGameObjectFactory::Instance()->registerType("Turret", new TurretCreator());
    TheGameObjectFactory::Instance()->registerType("Glider", new GliderCreator());
    TheGameObjectFactory::Instance()->registerType("ShotGlider", new ShotGliderCreator());
    TheGameObjectFactory::Instance()->registerType("RoofTurret", new RoofTurretCreator());
    TheGameObjectFactory::Instance()->registerType("Eskeletor", new EskeletorCreator());
    TheGameObjectFactory::Instance()->registerType("Level1Boss", new Level1BossCreator());
    
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

void Game::handleEvents() { TheInputHandler::Instance()->update(); }

void Game::clean() {
    std::cout << "cleaning game\n";
    
    TheInputHandler::Instance()->clean();    
    TheTextureManager::Instance()->clearTextureMap();
    TheSoundManager::Instance()->clearSoundMap();
    
    m_pGameStateMachine->clean();
    delete m_pGameStateMachine;
            
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}


