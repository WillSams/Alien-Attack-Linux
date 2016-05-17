#ifndef GLIDER_H_DEFINED
#define GLIDER_H_DEFINED

#include "GameObjectFactory.h"
#include "SoundManager.h"
#include "TextureManager.h"
#include "Enemy.h"

#include <iostream>
#include <math.h>

class Glider : public Enemy {
    
public:    
    Glider() ;
    
    virtual ~Glider();    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    virtual void collision();    
    virtual void update();
    
private:    
    int m_maxHeight;
    int m_minHeight;
    int m_gap;
    
    int m_dyingTime;
    int m_health;
    int m_moveSpeed;
};

class GliderCreator : public BaseCreator {
    virtual GameObject* createGameObject() const;
};

#endif /* defined(GLIDER_H_DEFINED) */
