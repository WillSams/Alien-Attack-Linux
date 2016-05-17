#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic()
: m_animSpeed(0),
  m_frameCount(0)
{ }

void AnimatedGraphic::load(std::unique_ptr<LoaderParams> const &pParams) {
    ShooterObject::load(pParams);
    m_animSpeed = pParams->getAnimSpeed();
}

void AnimatedGraphic::draw() { ShooterObject::draw(); }

void AnimatedGraphic::update() {
    m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}

void AnimatedGraphic::clean() { ShooterObject::clean(); }


GameObject* AnimatedGraphicCreator::createGameObject() const {
    return new AnimatedGraphic();
}
