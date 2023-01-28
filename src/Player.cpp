//
//  Player.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 12/01/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//
#include <memory>

#include "BulletHandler.h"
#include "Game.h"
#include "InputHandler.h"
#include "Player.h"
#include "SoundManager.h"
#include "TileLayer.h"

Player::Player()
    : ShooterObject(), m_invulnerable(false), m_invulnerableTime(200),
      m_invulnerableCounter(0) {}

void Player::collision() {
  // if the player is not invulnerable then set to dying and change values for
  // death animation tile sheet
  if (!m_invulnerable && !game->getLevelComplete()) {
    m_textureID = "largeexplosion";
    m_currentFrame = 0;
    m_numFrames = 9;
    m_width = 60;
    m_height = 60;
    m_bDying = true;
  }
}

void Player::load(std::unique_ptr<LoaderParams> const &pParams) {
  ShooterObject::load(std::move(pParams)); // inherited load function

  // can set up the players inherited values here
  // set up bullets
  m_bulletFiringSpeed = 13;
  m_moveSpeed = 3;

  m_bulletCounter = m_bulletFiringSpeed; // we want to be able to fire instantly

  m_dyingTime = 100; // time it takes for death explosion
}

// player has no special drawing requirements
void Player::draw() { ShooterObject::draw(); }

void Player::handleAnimation() {
  // if the player is invulnerable we can flash its alpha to let people know
  if (m_invulnerable) {
    // invulnerability is finished, set values back
    if (m_invulnerableCounter == m_invulnerableTime) {
      m_invulnerable = false;
      m_invulnerableCounter = 0;
      m_alpha = 255;
    } else { // otherwise, flash the alpha on and off
      if (m_alpha == 255) {
        m_alpha = 0;
      } else {
        m_alpha = 255;
      }
    }

    m_invulnerableCounter++; // increment our counter
  }

  // if the player is not dead then we can change the angle with the velocity
  // to give the impression of a moving helicopter
  if (!m_bDead) {
    if (m_velocity.getX() < 0) {
      m_angle = -10.0;
    } else if (m_velocity.getX() > 0) {
      m_angle = 10.0;
    } else {
      m_angle = 0.0;
    }
  }

  // our standard animation code - for helicopter propellors
  m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
}

void Player::update() {
  if (game->getLevelComplete()) {
    if (m_position.getX() >= game->getGameWidth()) {
      game->setCurrentLevel(game->getCurrentLevel() + 1);
    } else {
      m_velocity.setY(0);
      m_velocity.setX(3);
      ShooterObject::update();
      handleAnimation();
    }
  } else {
    // if the player is not doing its death animation then update it normally
    if (!m_bDying) {
      // reset velocity
      m_velocity.setX(0);
      m_velocity.setY(0);

      // get input
      handleInput();

      // do normal position += velocity update
      ShooterObject::update();

      // update the animation
      handleAnimation();
    } else { // if the player is doing the death animation
      m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));

      // if the death animation has completed
      // ressurect the player
      if (m_dyingCounter == m_dyingTime) {
        ressurect();
      }
      m_dyingCounter++;
    }
  }
}

void Player::ressurect() {
  game->setPlayerLives(game->getPlayerLives() - 1);

  m_position.setX(10);
  m_position.setY(200);
  m_bDying = false;

  m_textureID = "player";

  m_currentFrame = 0;
  m_numFrames = 5;
  m_width = 101;
  m_height = 46;

  m_dyingCounter = 0;
  m_invulnerable = true;
}

void Player::clean() { ShooterObject::clean(); }

void Player::handleInput() {
  if (!m_bDead) {
    // handle keys
    if (inputHandler->isKeyDown(SDL_SCANCODE_UP) && m_position.getY() > 0) {
      m_velocity.setY(-m_moveSpeed);
    } else if (inputHandler->isKeyDown(SDL_SCANCODE_DOWN) &&
               (m_position.getY() + m_height) < game->getGameHeight() - 10) {
      m_velocity.setY(m_moveSpeed);
    }

    if (inputHandler->isKeyDown(SDL_SCANCODE_LEFT) && m_position.getX() > 0) {
      m_velocity.setX(-m_moveSpeed);
    } else if (inputHandler->isKeyDown(SDL_SCANCODE_RIGHT) &&
               (m_position.getX() + m_width) < game->getGameWidth()) {
      m_velocity.setX(m_moveSpeed);
    }

    if (inputHandler->isKeyDown(SDL_SCANCODE_SPACE)) {
      if (m_bulletCounter == m_bulletFiringSpeed) {
        soundManager->playSound("shoot", 0);
        TheBulletHandler::Instance()->addPlayerBullet(
            m_position.getX() + 90, m_position.getY() + 12, 11, 11, "bullet1",
            1, Vector2D(10, 0));
        m_bulletCounter = 0;
      }

      m_bulletCounter++;
    } else {
      m_bulletCounter = m_bulletFiringSpeed;
    }
    // */

    /* handle joysticks */
    // Check for joysticks
    if (SDL_NumJoysticks() < 1) {
      // printf( "Warning: No joysticks connected!\n" );
    } else {
      if (inputHandlerjoysticksInitialised()) {
        if (inputHandler->getButtonState(0, 2)) {
          if (m_bulletCounter == m_bulletFiringSpeed) {
            soundManager->playSound("shoot", 0);
            TheBulletHandler::Instance()->addPlayerBullet(
                m_position.getX() + 90, m_position.getY() + 12, 11, 11,
                "bullet1", 1, Vector2D(10, 0));
            m_bulletCounter = 0;
          }

          m_bulletCounter++;
        } else {
          m_bulletCounter = m_bulletFiringSpeed;
        }

        if ((inputHandler->getAxisX(0, 1) > 0 &&
             (m_position.getX() + m_width) < game->getGameWidth()) ||
            (inputHandler->getAxisX(0, 1) < 0 && m_position.getX() > 0)) {
          m_velocity.setX(m_moveSpeed * inputHandler->getAxisX(0, 1));
        }

        if ((inputHandler->getAxisY(0, 1) > 0 &&
             (m_position.getY() + m_height) < game->getGameHeight() - 10) ||
            (inputHandler->getAxisY(0, 1) < 0 && m_position.getY() > 0)) {
          m_velocity.setY(m_moveSpeed * inputHandler->getAxisY(0, 1));
        }
      }
    }
  }
}