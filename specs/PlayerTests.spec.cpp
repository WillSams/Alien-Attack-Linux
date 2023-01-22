#include <memory>

#include <gtest/gtest.h>

#include "../src/Player.h"

TEST(DISABLED_PlayerTests, testCollision) { }

TEST(PlayerTests, testLoad) {   
    int x = 500, y =100, width = 128, height = 128, numFrames = 4;
    int callbackID = 0, animSpeed = 0;
    
    std::string textureID = "helicopter";
    std::string type = "Player";
    
    GameObject* gameObject = TheGameObjectFactory::Instance()->create(type);
    
    ASSERT_TRUE(gameObject);
    
    gameObject->load(std::unique_ptr<LoaderParams>(
        new LoaderParams(x, y, width, height, textureID, numFrames, 
                callbackID, animSpeed)
    ));
   
    ASSERT_EQ(500, gameObject->getPosition().getX());
    ASSERT_EQ(100, gameObject->getPosition().getY());
    ASSERT_EQ(128, gameObject->getWidth());
    ASSERT_EQ(128, gameObject->getHeight());
    
    Player* player = dynamic_cast<Player*>(gameObject);
    ASSERT_EQ("Player", player->type());  
    
    delete gameObject;
}

TEST(DISABLED_PlayerTests, testDraw) { }

TEST(DISABLED_PlayerTests, testHandleAnimation) { }

TEST(DISABLED_PlayerTests, testUpdate) { }

TEST(DISABLED_PlayerTests, testRessurect) { }

TEST(DISABLED_PlayerTests, testClean) { }

TEST(DISABLED_PlayerTests, testHandleInput) { }
