#include "Bullet.h"

PlayerBullet::PlayerBullet() { m_dyingTime =5; }    
PlayerBullet::~PlayerBullet() {}
    
std::string PlayerBullet::type() { return "PlayerBullet"; }
    
void PlayerBullet::load(std::unique_ptr<LoaderParams> &pParams, Vector2D heading) {
    ShooterObject::load(std::move(pParams));
    m_heading = heading;
}

void PlayerBullet::draw() { ShooterObject::draw(); }
    
void PlayerBullet::collision() {
    m_textureID = "smallexplosion";
    m_currentFrame = 0;
    m_numFrames = 2;
    m_width = 20;
    m_height = 20;
    m_bDying = true;
}
    
void PlayerBullet::update() {
    if(!m_bDying) {
        m_velocity.setX(m_heading.getX());
        m_velocity.setY(m_heading.getY());

        ShooterObject::update();
    } else {
        m_velocity.setX(0);
        m_velocity.setY(0);
        doDyingAnimation();
    }
}
    
void PlayerBullet::clean() { ShooterObject::clean(); }
    
EnemyBullet::EnemyBullet() : PlayerBullet() { }  
EnemyBullet::~EnemyBullet() {}    
std::string EnemyBullet::type() { return "EnemyBullet"; }

