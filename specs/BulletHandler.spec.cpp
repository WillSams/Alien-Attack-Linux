#include <igloo/igloo_alt.h>

#include "include/fakeit.h"

#include "../src/Bullet.h"
#include "../src/BulletHandler.h"
#include "../src/Game.h"

using namespace igloo;
using namespace fakeit;

// Mock<Game> mockGame;
Mock<PlayerBullet> mockPlayerBullet;
Mock<EnemyBullet> mockEnemyBullet;

Describe(BulletHandlerSpec) {
  void SetUp() {
    // mockGame.Reset();
    mockPlayerBullet.Reset();
    mockEnemyBullet.Reset();

    // Define the behavior of other methods
    // When(Method(mockGame, getGameWidth)).Return(640);
    // When(Method(mockGame, getGameHeight)).Return(480);
  };

  // It(should_add_a_player_bullet) {
  //   TheBulletHandler::Instance()->addPlayerBullet(0, 0, 0, 0, "", 0,
  //                                                 Vector2D(0, 0));

  //   auto playerBullets = TheBulletHandler::Instance()->getPlayerBullets();
  //   Assert::That(playerBullets.size(), Equals(1));
  // };

  // It(should_add_an_enemy_bullet) {
  //   TheBulletHandler::Instance()->addEnemyBullet(0, 0, 0, 0, "", 0,
  //                                                Vector2D(0, 0));

  //   auto enemyBullets = TheBulletHandler::Instance()->getEnemyBullets();
  //   Assert::That(enemyBullets.size(), Equals(1));
  // };

  // It(should_update_bullets) {
  //   MockBullet bullet;

  //   // pBulletHandler->addPlayerBullet(10, 20, 30, 40, "bullet", 1,
  //   //                                 Vector2D(1.0, 0.0));
  //   TheBulletHandler::Instance()->addEnemyBullet(
  //       10, 20, 30, 40, "random enemy bullet", 1, Vector2D(1.0, 0.0));
  //   TheBulletHandler::Instance()->addPlayerBullet(
  //       10, 20, 30, 40, "bullet player bullet", 1, Vector2D(1.0, 0.0));

  //   TheBulletHandler::Instance()->updateBullets();

  //   // auto enemyBullets = TheBulletHandler::Instance()->getEnemyBullets();
  //   // auto playerBullets = TheBulletHandler::Instance()->getPlayerBullets();

  //   // Assert::That(enemyBullets.size(), Equals(0));
  //   // Assert::That(playerBullets.size(), Equals(0));
  // };

  // It(should_update_bullets) {
  //   BulletHandler *pBulletHandler = BulletHandler::Instance();

  //   pBulletHandler->addPlayerBullet(10, 20, 30, 40, "bullet", 1,
  //                                   Vector2D(1.0, 0.0));

  //   // auto mockPlayerBullet = std::make_shared<Mock<PlayerBullet>>();

  //   MockBullet bullet;
  //   // When(Method(mockPlayerBullet, update)).AlwaysReturn();
  //   pBulletHandler->getPlayerBullets()[0] = mockPlayerBullet.get();

  //   pBulletHandler->updateBullets();

  //   // Verify(Method(mockPlayerBullet, update));
  // }

  It(should_draw_bullets){

      // // Expect draw method to be called on both player and enemy bullets
      // When(Method(mockPlayerBullet, draw)).Return();
      // When(Method(mockEnemyBullet, draw)).Return();

      // // Add the mock bullets to the bullet handler
      // BulletHandler::Instance()->addPlayerBullet(10, 20, 30, 40, "bullet", 1,
      //                                            Vector2D(1.0, 0.0));
      // BulletHandler::Instance()->addEnemyBullet(10, 20, 30, 40, "bullet", 1,
      //                                           Vector2D(1.0, 0.0));

      // // Verify that the draw method is called on both player and enemy
      // bullets
      // BulletHandler::Instance()->drawBullets();
      // Verify(Method(mockPlayerBullet, draw));
      // Verify(Method(mockEnemyBullet, draw));
  };

  // It(should_clear_bullets) {
  //   MockBullet bullet;
  //   TheBulletHandler::Instance()->addEnemyBullet(0, 0, 0, 0, "", 0,
  //                                                Vector2D(0, 0));
  //   TheBulletHandler::Instance()->addPlayerBullet(0, 0, 0, 0, "", 0,
  //                                                 Vector2D(0, 0));

  //   TheBulletHandler::Instance()->clearBullets();

  //   // auto enemyBullets = TheBulletHandler::Instance()->getEnemyBullets();
  //   // auto playerBullets = TheBulletHandler::Instance()->getPlayerBullets();

  //   // Assert::That(enemyBullets.size(), Equals(0));
  //   // Assert::That(playerBullets.size(), Equals(0));
  // };
};
