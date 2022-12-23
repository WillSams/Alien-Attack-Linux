#ifndef BULLETHANDLER_H_DEFINED
#define BULLETHANDLER_H_DEFINED

#include "Bullet.h"
#include "Game.h"

#include <iostream>
#include <vector>

class BulletHandler {
    
public:    
    static BulletHandler* Instance();
    
    void addPlayerBullet(int x, int y, int width, int height, 
        std::string textureID, int numFrames, Vector2D heading);
    void addEnemyBullet(int x, int y, int width, int height, 
        std::string textureID, int numFrames, Vector2D heading);
    
    void updateBullets();
    void drawBullets();
    
    void clearBullets();
    
    const std::vector<PlayerBullet*> getPlayerBullets();
    const std::vector<EnemyBullet*> getEnemyBullets();
    
private:    
    BulletHandler();
    ~BulletHandler();
    
    BulletHandler(const BulletHandler&);
    BulletHandler& operator=(const BulletHandler&);
    
    static BulletHandler* s_pInstance;
    
    // in play bullets
    std::vector<PlayerBullet*> m_playerBullets;
    std::vector<EnemyBullet*> m_enemyBullets;
};

typedef BulletHandler TheBulletHandler;

#endif /* defined(BULLETHANDLER_H_DEFINED) */
