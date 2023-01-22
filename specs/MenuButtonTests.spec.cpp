#include <memory>

#include <gtest/gtest.h>

#include "../src/MenuButton.h"
#include "../src/GameObjectFactory.h"

TEST(MenuButtonTests, testLoad) {    
    int x = 100, y =100, width = 400, height = 100, numFrames = 2;
    int callbackID = 1, animSpeed = 0;
    std::string textureID = "playbutton";
    std::string type = "MenuButton";
    
    GameObject* gameObject = TheGameObjectFactory::Instance()->create(type);
    
    ASSERT_TRUE(gameObject);
    
    gameObject->load(std::unique_ptr<LoaderParams>(
        new LoaderParams(x, y, width, height, textureID, numFrames, 
                callbackID, animSpeed)
    ));
   
    ASSERT_EQ(100, gameObject->getPosition().getX());
    ASSERT_EQ(100, gameObject->getPosition().getY());
    ASSERT_EQ(400, gameObject->getWidth());
    ASSERT_EQ(100, gameObject->getHeight());
    
    //MenuButton type returns from GameObject base class
    MenuButton* button = dynamic_cast<MenuButton*>(gameObject);
    ASSERT_EQ("SDLGameObject", button->type());    
    
    delete gameObject;
}

TEST(DISABLED_MenuButtonTests, testDraw) {}

TEST(DISABLED_MenuButtonTests, testUpdate) {}

TEST(DISABLED_MenuButtonTests, testClean) {}
