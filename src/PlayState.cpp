//
//  PlayState.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 09/02/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//

#include "PlayState.h"
#include "BulletHandler.h"
#include "Game.h"
#include "GameOverState.h"
#include "InputHandler.h"
#include "Level.h"
#include "LevelParser.h"
#include "PauseState.h"
#include <iostream>

const std::string PlayState::s_playID = "PLAY";

void PlayState::update() {
  if (m_loadingComplete && !m_exiting) {
    if (inputHandler->isKeyDown(SDL_SCANCODE_ESCAPE)) {
      game->getStateMachine()->pushState(new PauseState());
    }

    //        if(inputHandler->getButtonState(0, 8))
    //        {
    //            game->getStateMachine()->pushState(new PauseState());
    //        }

    TheBulletHandler::Instance()->updateBullets();

    if (game->getPlayerLives() == 0) {
      game->getStateMachine()->changeState(new GameOverState());
    }

    if (pLevel != 0) {
      pLevel->update();
    }
  }
}

void PlayState::render() {
  if (m_loadingComplete) {
    if (pLevel != 0) {
      pLevel->render();
    }

    for (int i = 0; i < game->getPlayerLives(); i++) {
      textureManager->drawFrame("lives", i * 30, 0, 32, 30, 0, 0,
                                game->getRenderer(), 0.0, 255);
    }

    TheBulletHandler::Instance()->drawBullets();
  }
}

bool PlayState::onEnter() {
  game->setPlayerLives(3);

  LevelParser levelParser;
  pLevel = levelParser.parseLevel(
      game->getLevelFiles()[game->getCurrentLevel() - 1].c_str());

  textureManager->load("bullet1.png", "bullet1", game->getRenderer());
  textureManager->load("bullet2.png", "bullet2", game->getRenderer());
  textureManager->load("bullet3.png", "bullet3", game->getRenderer());
  textureManager->load("lives.png", "lives", game->getRenderer());

  if (pLevel != 0) {
    m_loadingComplete = true;
  }

  std::cout << "entering PlayState\n";
  return true;
}

bool PlayState::onExit() {
  m_exiting = true;

  inputHandler->reset();
  TheBulletHandler::Instance()->clearBullets();

  std::cout << "exiting PlayState\n";
  return true;
}
