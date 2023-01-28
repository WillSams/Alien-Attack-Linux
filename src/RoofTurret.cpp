#include "RoofTurret.h"
#include "Game.h"

RoofTurret::~RoofTurret() {}

void RoofTurret::draw() {
  TextureManager::Instance()->drawFrame(
      m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(),
      m_width, m_height, m_currentRow, m_currentFrame, game->getRenderer(),
      m_angle, m_alpha, SDL_FLIP_VERTICAL);
}

void RoofTurret::update() {
  if (!m_bDying) {
    // we want to scroll this object with the rest
    scroll(game->getScrollSpeed());

    if (m_bulletCounter == m_bulletFiringSpeed) {
      TheBulletHandler::Instance()->addEnemyBullet(
          m_position.getX(), m_position.getY() + 20, 16, 16, "bullet2", 1,
          Vector2D(-3, 3));
      TheBulletHandler::Instance()->addEnemyBullet(
          m_position.getX() + 20, m_position.getY() + 20, 16, 16, "bullet2", 1,
          Vector2D(0, 3));
      TheBulletHandler::Instance()->addEnemyBullet(
          m_position.getX() + 40, m_position.getY() + 20, 16, 16, "bullet2", 1,
          Vector2D(3, 3));
      m_bulletCounter = 0;
    }

    m_bulletCounter++;
  } else {
    scroll(game->getScrollSpeed());
    doDyingAnimation();
  }
}

GameObject *RoofTurretCreator::createGameObject() const {
  return new RoofTurret();
}
