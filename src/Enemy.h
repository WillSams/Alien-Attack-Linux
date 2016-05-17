#ifndef ENEMY_H_DEFINED
#define ENEMY_H_DEFINED

#include "ShooterObject.h"

#include <iostream>

// Enemy base class
class Enemy : public ShooterObject {
public:    
    virtual std::string type();
    
protected:    
    int m_health;
    
    Enemy();
    virtual ~Enemy();
};

#endif /* defined(ENEMY_H_DEFINED) */
