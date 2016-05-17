#ifndef SHOTGLIDER_H_DEFINED
#define SHOTGLIDER_H_DEFINED

#include "Glider.h"

class ShotGlider : public Glider {
    
public:    
    virtual ~ShotGlider();
    
    ShotGlider();
    
    virtual void load(std::unique_ptr<LoaderParams> const &pParams);
    virtual void update();
    
    private:
        int m_bulletFiringSpeed;
        int m_moveSpeed;
};

class ShotGliderCreator : public BaseCreator {
    
public:
    virtual GameObject* createGameObject() const;
};
#endif /* defined(SHOTGLIDER_H_DEFINED) */
