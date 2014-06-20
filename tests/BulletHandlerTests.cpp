#include <vector>

#include <gtest/gtest.h>

#include "../src/BulletHandler.h"
#include "../src/Vector2D.h"

TEST(BulletHandlerTests, testAddPlayerBullet) {     
    int x = 90, y = 12, width = 11, height = 11, numFrames = 1;
 
    std::string textureID = "bulllet1";
    Vector2D heading = Vector2D(10,0);
    
    int preCount = TheBulletHandler::Instance()->getPlayerBullets().size();
        
    TheBulletHandler::Instance()->addPlayerBullet(x, y, width, height, 
        textureID, numFrames, heading);
    
    int postCount = TheBulletHandler::Instance()->getPlayerBullets().size();
    
    ASSERT_EQ(preCount + 1, postCount);    
}

TEST(BulletHandlerTests, testAddEnemyBullet) {     
    int x = 90, y = 12, width = 11, height = 11, numFrames = 1;
 
    std::string textureID = "bulllet1";
    Vector2D heading = Vector2D(10,0);
    
    int preCount = TheBulletHandler::Instance()->getEnemyBullets().size();
        
    TheBulletHandler::Instance()->addEnemyBullet(x, y, width, height, 
        textureID, numFrames, heading);
    
    int postCount = TheBulletHandler::Instance()->getEnemyBullets().size();
    
    ASSERT_EQ(preCount + 1, postCount);
}

TEST(BulletHandlerTests, testClearBullets) { 
    int prePlayerCount = TheBulletHandler::Instance()->getPlayerBullets().size();
    int preEnemyCount = TheBulletHandler::Instance()->getPlayerBullets().size();
        
    TheBulletHandler::Instance()->addPlayerBullet(90, 12, 11, 11, 
        "bullet1", 1, Vector2D(10,0));
    TheBulletHandler::Instance()->addEnemyBullet(0, 0, 16, 16, 
        "bullet1", 1, Vector2D(3,0));
    TheBulletHandler::Instance()->addEnemyBullet(106, 28, 16, 16, 
        "bullet2", 1, Vector2D(-3,0));
    
    int postPlayerCount = TheBulletHandler::Instance()->getPlayerBullets().size();
    int postEnemyCount = TheBulletHandler::Instance()->getEnemyBullets().size();
    
    ASSERT_EQ(prePlayerCount + 1, postPlayerCount);
    ASSERT_EQ(preEnemyCount + 2, postEnemyCount);
}

TEST(DISABLED_BulletHandlerTests, testUpdateBullets) { }

TEST(DISABLED_BulletHandlerTests, testDrawBullets) { }