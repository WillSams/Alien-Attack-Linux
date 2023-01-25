#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "../src/Bullet.h"
#include "../src/BulletHandler.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::NiceMock;
using ::testing::Return;

class MockBullet {
public:
  MOCK_METHOD0(draw, void());
  MOCK_METHOD0(update, void());
};

class BulletHandlerTest : public ::testing::Test {
protected:
  std::shared_ptr<MockBullet> playerBullet, enemyBullet;
  std::vector<std::shared_ptr<MockBullet>> playerBullets;
  std::vector<std::shared_ptr<MockBullet>> enemyBullets;
  BulletHandler *bulletHandler;

  void SetUp() override {
    playerBullet = std::make_shared<MockBullet>();
    enemyBullet = std::make_shared<MockBullet>();
    playerBullets.push_back(playerBullet);
    enemyBullets.push_back(enemyBullet);
    bulletHandler = BulletHandler::Instance();
  }
};

TEST_F(BulletHandlerTest, addPlayerBullet) {
  bulletHandler->addPlayerBullet(0, 0, 0, 0, "", 0, Vector2D());
  EXPECT_EQ(bulletHandler->getPlayerBullets().size(), 2);
}

TEST_F(BulletHandlerTest, addEnemyBullet) {
  bulletHandler->addEnemyBullet(0, 0, 0, 0, "", 0, Vector2D());
  EXPECT_EQ(bulletHandler->getEnemyBullets().size(), 2);
}

TEST_F(BulletHandlerTest, updateBullets) {
  EXPECT_CALL(*playerBullet, update()).Times(AtLeast(1));
  EXPECT_CALL(*enemyBullet, update()).Times(AtLeast(1));
  bulletHandler->updateBullets();
}

TEST_F(BulletHandlerTest, drawBullets) {
  EXPECT_CALL(*playerBullet, draw()).Times(AtLeast(1));
  EXPECT_CALL(*enemyBullet, draw()).Times(AtLeast(1));
  bulletHandler->drawBullets();
}

TEST_F(BulletHandlerTest, clearBullets) {
  bulletHandler->clearBullets();
  EXPECT_EQ(bulletHandler->getPlayerBullets().size(), 0);
  EXPECT_EQ(bulletHandler->getEnemyBullets().size(), 0);
}
