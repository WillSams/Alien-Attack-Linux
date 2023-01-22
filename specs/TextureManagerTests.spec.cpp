#include <map>
#include <string>

#include <gtest/gtest.h>

#include "../src/TextureManager.h"

TEST(TextureManagerTests, testLoad) { 
    const char* title = "TextureManagerTests::testLoad";
    int xpos = 30;
    int ypos = 35;
    int width = 640;
    int height = 480;
    int flags = 0;
    
    SDL_Window* window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    bool isLoaded = TheTextureManager::Instance()->load("bullet1.png", "bullet1", renderer);
    
    ASSERT_EQ(true, isLoaded);
    
    delete window;
    delete renderer;
}

TEST(DISABLED_TextureManagerTests, testDraw) { }

TEST(DISABLED_TextureManagerTests, testDrawFrame) { }

TEST(DISABLED_TextureManagerTests, testDrawTile) { }

TEST(TextureManagerTests, testClearTextureMap) { 
    const char* title = "TextureManagerTests::testClearTextureMap";
    int xpos = 30;
    int ypos = 35;
    int width = 640;
    int height = 480;
    int flags = 0;
    
    SDL_Window* window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    TheTextureManager::Instance()->load("bullet1.png", "bullet1", renderer);
    
    std::map<std::string, SDL_Texture*> textureMap = TheTextureManager::Instance()->getTextureMap();
    
    EXPECT_TRUE(textureMap["bullet1"] != NULL);
    
    TheTextureManager::Instance()->clearTextureMap();    
    textureMap = TheTextureManager::Instance()->getTextureMap();
    
    EXPECT_TRUE(textureMap["bullet1"] == NULL);   
    
    delete window;
    delete renderer;
}

TEST(TextureManagerTests, testClearFromTextureMap) { 
    const char* title = "TextureManagerTests::testClearFromTextureMap";
    int xpos = 30;
    int ypos = 35;
    int width = 640;
    int height = 480;
    int flags = 0;
    
    SDL_Window* window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    TheTextureManager::Instance()->load("bullet1.png", "bullet1", renderer);
    TheTextureManager::Instance()->load("bullet2.png", "bullet2", renderer);
    
    std::map<std::string, SDL_Texture*> textureMap = TheTextureManager::Instance()->getTextureMap();
    
    EXPECT_TRUE(textureMap["bullet1"] != NULL);
    EXPECT_TRUE(textureMap["bullet2"] != NULL);
    
    TheTextureManager::Instance()->clearFromTextureMap("bullet2");    
    textureMap = TheTextureManager::Instance()->getTextureMap();
    
    EXPECT_TRUE(textureMap["bullet1"] != NULL);   
    EXPECT_TRUE(textureMap["bullet2"] == NULL); 
    
    delete window;
    delete renderer;
}

