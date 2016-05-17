#ifndef BULLET_H_DEFINED
#define BULLET_H_DEFINED

#include "ShooterObject.h"

class PlayerBullet : public ShooterObject {
    
public:
    PlayerBullet();    
    virtual ~PlayerBullet();    
    virtual std::string type();    
    virtual void load(std::unique_ptr<LoaderParams> &pParams, Vector2D heading);    
    virtual void draw();    
    virtual void collision();    
    virtual void update();    
    virtual void clean();
    
private:    
    Vector2D m_heading;
};

class EnemyBullet : public PlayerBullet {
    
public:
    EnemyBullet();   
    virtual ~EnemyBullet();  
    virtual std::string type();
};

#endif /* defined(BULLET_H_DEFINED) */
