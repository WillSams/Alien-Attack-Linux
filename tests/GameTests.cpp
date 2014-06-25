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
}

TEST(DISABLED_GameTests, testSetCurrentLevel) { }

TEST(DISABLED_GameTests, testRender) { }

TEST(DISABLED_GameTests, testUpdate) { }

TEST(DISABLED_GameTests, testHandleEvents) { }

TEST(DISABLED_GameTests, testClean) { }

