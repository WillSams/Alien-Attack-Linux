#include "GameObject.h"

GameObject::~GameObject() {}
    
Vector2D& GameObject::getPosition() { return m_position; }
Vector2D& GameObject::getVelocity() { return m_velocity; }
    
int GameObject::getWidth() { return m_width; }
int GameObject::getHeight() { return m_height; }
    
void GameObject::scroll(float scrollSpeed) {
    if(type() != std::string("Player")) // player is never scrolled
    {
        m_position.setX(m_position.getX() - scrollSpeed);
    }
}
    
    // is the object currently being updated?
    bool GameObject::updating() { return m_bUpdating; }
    
    // is the object dead?
    bool GameObject::dead() { return m_bDead; }
    
    // is the object doing a death animation?
    bool GameObject::dying() { return m_bDying; }
    
    // set whether to update the object or not
    void GameObject::setUpdating(bool updating) { m_bUpdating = updating; }
    
    // constructor with default initialisation list
    GameObject::GameObject() :  m_position(0,0),
                    m_velocity(0,0),
                    m_acceleration(0,0),
                    m_width(0),
                    m_height(0),
                    m_currentRow(0),
                    m_currentFrame(0),
                    m_bUpdating(false),
                    m_bDead(false),
                    m_bDying(false),
                    m_angle(0),
                    m_alpha(255)
    {
    }
