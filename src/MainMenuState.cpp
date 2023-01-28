//
//  MenuState.cpp
//  SDL Game Programming Book
//
//  Created by shaun mitchell on 09/02/2013.
//  Copyright (c) 2013 shaun mitchell. All rights reserved.
//
#include "MainMenuState.h"
#include "Game.h"
#include "InputHandler.h"
#include "MenuButton.h"
#include "PlayState.h"
#include "StateParser.h"
#include "TextureManager.h"
#include <assert.h>
#include <iostream>

const std::string MainMenuState::s_menuID = "MENU";

// Callbacks
void MainMenuState::s_menuToPlay() {
  game->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu() { game->quit(); }

// end callbacks

void MainMenuState::update() {
  if (inputHandler->isKeyDown(SDL_SCANCODE_SPACE)) {
    s_menuToPlay();
  }
  if (!m_gameObjects.empty()) {
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
      if (m_gameObjects[i] != 0) {
        m_gameObjects[i]->update();
      }
    }
  }
}

void MainMenuState::render() {
  if (m_loadingComplete && !m_gameObjects.empty()) {
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
      m_gameObjects[i]->draw();
    }
  }
}

bool MainMenuState::onEnter() {
  // parse the state
  StateParser stateParser;
  stateParser.parseState(DATA_PREFIX "attack.xml", s_menuID, &m_gameObjects,
                         &m_textureIDList);

  m_callbacks.push_back(0);
  m_callbacks.push_back(s_menuToPlay);
  m_callbacks.push_back(s_exitFromMenu);

  // set the callbacks for menu items
  setCallbacks(m_callbacks);

  m_loadingComplete = true;
  std::cout << "entering MenuState\n";
  return true;
}

bool MainMenuState::onExit() {
  m_exiting = true;

  // clean the game objects
  if (m_loadingComplete && !m_gameObjects.empty()) {
    m_gameObjects.back()->clean();
    m_gameObjects.pop_back();
  }

  m_gameObjects.clear();

  /* clear the texture manager
  for(unsigned int i = 0; i < m_textureIDList.size(); i++)
  {
      textureManager->clearFromTextureMap(m_textureIDList[i]);
  }
      */

  // reset the input handler
  inputHandler->reset();

  std::cout << "exiting MenuState\n";
  return true;
}

void MainMenuState::setCallbacks(const std::vector<Callback> &callbacks) {
  // go through the game objects
  if (!m_gameObjects.empty()) {
    for (unsigned int i = 0; i < m_gameObjects.size(); i++) {
      // if they are of type MenuButton then assign a callback based on the id
      // passed in from the file
      if (dynamic_cast<MenuButton *>(m_gameObjects[i])) {
        MenuButton *pButton = dynamic_cast<MenuButton *>(m_gameObjects[i]);
        pButton->setCallback(callbacks[pButton->getCallbackID()]);
      }
    }
  }
}
