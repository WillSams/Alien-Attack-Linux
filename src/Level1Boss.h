#ifndef LEVEL1BOSS_H_DEFINED
#define LEVEL1BOSS_H_DEFINED

#include "GameObjectFactory.h"
#include "SoundManager.h"
#include "Enemy.h"
#include "Game.h"

#include <iostream>
#include <math.h>

class Level1Boss : public Enemy {
    
public:    
    virtual ~Level1Boss();
    
    Level1Boss();
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);    
    virtual void collision();    
    virtual void update();
    
private:    
    bool m_entered;
    
    int m_dyingTime;
    int m_health;
    int m_moveSpeed;
    int m_bulletFiringSpeed;
};

class Level1BossCreator : public BaseCreator {
    GameObject* createGameObject() const;
};

#endif /* defined(LEVEL1BOSS_H_DEFINED) */
