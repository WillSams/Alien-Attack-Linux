#ifndef ESKELETOR_H_DEFINED
#define ESKELETOR_H_DEFINED

#include "GameObjectFactory.h"
#include "BulletHandler.h"
#include "SoundManager.h"
#include "Enemy.h"

class Eskeletor : public Enemy {
    
public:    
    virtual ~Eskeletor();

    Eskeletor();

    virtual void collision();    
    virtual void update();
    
private:        
    int m_dyingTime;
    int m_health;
    int m_moveSpeed;
    int m_bulletFiringSpeed;   
};

class EskeletorCreator : public BaseCreator {
    
public:    
    virtual GameObject* createGameObject() const;
};

#endif /* defined(ESKELETOR_H_DEFINED) */
