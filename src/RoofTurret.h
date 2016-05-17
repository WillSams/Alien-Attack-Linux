#ifndef ROOFTURRET_H_DEFINED
#define ROOFTURRET_H_DEFINED

#include "Turret.h"

class RoofTurret : public Turret {
    
public:    
    virtual ~RoofTurret();    
    virtual void draw();    
    virtual void update();
};

class RoofTurretCreator : public BaseCreator {
    virtual GameObject* createGameObject() const;
}; 

#endif /* defined (ROOFTURRET_H_DEFINED) */
