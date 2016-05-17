#ifndef COLLISIONMANAGER_H_DEFINED
#define COLLISIONMANAGER_H_DEFINED

#include "Enemy.h"
#include "BulletHandler.h"
#include "TileLayer.h"

#include <iostream>
#include <vector>

class CollisionManager {
    
public:    
    const static int s_buffer;

    static bool RectRect(std::shared_ptr<SDL_Rect> &A, std::shared_ptr<SDL_Rect> &B);
    
    void checkPlayerEnemyBulletCollision(Player* pPlayer);
    void checkPlayerEnemyCollision(Player* pPlayer, 
        const std::vector<GameObject*> &objects);
    void checkEnemyPlayerBulletCollision(const std::vector<GameObject*>& objects);
    void checkPlayerTileCollision(Player* pPlayer, 
        const std::vector<TileLayer*>& collisionLayers);
};

#endif /* defined(COLLISIONMANAGER_H_DEFINED) */
