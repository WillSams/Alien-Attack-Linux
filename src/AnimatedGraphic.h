#ifndef ANIMATEDGRAPHIC_H_DEFINED
#define ANIMATEDGRAPHIC_H_DEFINED

#include "GameObjectFactory.h"
#include "ShooterObject.h"

class AnimatedGraphic : public ShooterObject {
    
public:        
    AnimatedGraphic();
    virtual ~AnimatedGraphic();

    virtual void load(std::unique_ptr<LoaderParams> const &pParams);

    virtual void draw();
    virtual void update();
    virtual void clean();

private:    
    int m_animSpeed;
    int m_frameCount;
};

class AnimatedGraphicCreator : public BaseCreator {
    
public:    
    virtual GameObject* createGameObject() const;
};

#endif /* defined(ANIMATEDGRAPHIC_H_DEFINED) */
