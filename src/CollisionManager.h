#pragma once

#include <iostream>
#include <vector>

#include "BulletHandler.h"
#include "Enemy.h"
#include "TileLayer.h"

class CollisionManager {

public:
  const static int s_buffer;

  static bool RectRect(std::shared_ptr<SDL_Rect> &A,
                       std::shared_ptr<SDL_Rect> &B);

  void checkPlayerEnemyBulletCollision(Player *pPlayer);
  void checkPlayerEnemyCollision(Player *pPlayer,
                                 const std::vector<GameObject *> &objects);
  void
  checkEnemyPlayerBulletCollision(const std::vector<GameObject *> &objects);
  void
  checkPlayerTileCollision(Player *pPlayer,
                           const std::vector<TileLayer *> &collisionLayers);
};
