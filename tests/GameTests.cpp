#include <gtest/gtest.h>

#include "../src/Game.h"

TEST(GameTests, testInit) { 
    const char* title = "GameTests::testInit";
    int xpos = 30;
    int ypos = 35;
    int width = 640;
    int height = 480;
    bool fullscreen = false;
    
    bool isInit = TheGame::Instance()->init(title, xpos, ypos, width, height, fullscreen);
    ASSERT_EQ(true, isInit);
    
    bool isRunning = TheGame::Instance()->running();    
    ASSERT_EQ(true, isRunning);
}

TEST(GameTests, modifyCurrentLevel) { 
    //test default value
    int currentLevel = TheGame::Instance()->getCurrentLevel();
    ASSERT_EQ(1, currentLevel);
    
    //test value editing
    TheGame::Instance()->setCurrentLevel(++currentLevel);
    currentLevel = TheGame::Instance()->getCurrentLevel();
    
    ASSERT_EQ(2, currentLevel);
}

TEST(GameTests, modifyNextLevel) {     
    TheGame::Instance()->setNextLevel(2);
    int nextLevel = TheGame::Instance()->getNextLevel();
    
    ASSERT_EQ(2, nextLevel);
}

TEST(GameTests, modifyPlayerLives) { 
    //test default value
    int playerLives = TheGame::Instance()->getPlayerLives();
    ASSERT_EQ(3, playerLives);  
    
    //test value editing
    TheGame::Instance()->setPlayerLives(++playerLives);
    playerLives = TheGame::Instance()->getPlayerLives();
    
    ASSERT_EQ(4, playerLives);
}

TEST(GameTests, modifylevelComplete) { 
    bool levelComplete = TheGame::Instance()->getLevelComplete();
    ASSERT_EQ(false, levelComplete);
    
    TheGame::Instance()->setLevelComplete(true);
    levelComplete = TheGame::Instance()->getLevelComplete();
    ASSERT_EQ(true, levelComplete);
}

TEST(DISABLED_GameTests, testRender) { }

TEST(DISABLED_GameTests, testUpdate) { }

TEST(DISABLED_GameTests, testHandleEvents) { }

TEST(DISABLED_GameTests, testClean) { }

