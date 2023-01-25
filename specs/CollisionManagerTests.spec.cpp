#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Mocks.h"

#include "../src/CollisionManager.h"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::NiceMock;
using ::testing::Return;

class MockBullet {
public:
  MOCK_METHOD0(draw, void());
  MOCK_METHOD0(update, void());
};

class CollisionManagerTest : public ::testing::Test {
protected:
  std::shared_ptr<MockPlayer> player;
  std::shared_ptr<MockEnemy> enemy;
  std::shared_ptr<MockPlayerBullet> playerBullet;
  std::shared_ptr<MockEnemyBullet> enemyBullet;
  std::vector<std::shared_ptr<MockEnemy>> enemies;
  std::vector<std::shared_ptr<MockPlayerBullet>> playerBullets;
  std::vector<std::shared_ptr<MockEnemyBullet>> enemyBullets;
  CollisionManager *collisionManager;

  void SetUp() override {
    player = std::make_shared<MockPlayer>();
    enemy = std::make_shared<MockEnemy>();
    playerBullet = std::make_shared<MockPlayerBullet>();
    enemyBullet = std::make_shared<MockEnemyBullet>();
    enemies.push_back(enemy);
    playerBullets.push_back(playerBullet);
    enemyBullets.push_back(enemyBullet);
    collisionManager = new CollisionManager();
  }
};

TEST_F(CollisionManagerTest, RectRect) {
  std::shared_ptr<SDL_Rect> A = std::make_shared<SDL_Rect>();
  std::shared_ptr<SDL_Rect> B = std::make_shared<SDL_Rect>();
  EXPECT_TRUE(CollisionManager::RectRect(A, B));
}

TEST_F(CollisionManagerTest, checkPlayerEnemyBulletCollision) {
  EXPECT_CALL(*player, collision()).Times(AtLeast(1));
  collisionManager->checkPlayerEnemyBulletCollision(player.get());
}

TEST_F(CollisionManagerTest, checkPlayerEnemyCollision) {
  EXPECT_CALL(*player, collision()).Times(AtLeast(1));

  std::vector<GameObject *> rawEnemies;
  for (auto &e : enemies)
    rawEnemies.push_back(e.get());
  collisionManager->checkPlayerEnemyCollision(player.get(), rawEnemies);
}

TEST_F(CollisionManagerTest, checkEnemyPlayerBulletCollision) {
  EXPECT_CALL(*enemy, collision()).Times(AtLeast(1));

  std::vector<GameObject *> rawBullets;
  for (auto &b : enemyBullets)
    rawBullets.push_back(b.get());
  collisionManager->checkEnemyPlayerBulletCollision(rawBullets);
}

TEST_F(CollisionManagerTest, checkPlayerTileCollision) {
  EXPECT_CALL(*player, collision()).Times(AtLeast(1));

  std::vector<TileLayer *> collisionLayers;
  collisionManager->checkPlayerTileCollision(player.get(), collisionLayers);
}