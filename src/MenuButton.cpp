#include "MenuButton.h"
#include "InputHandler.h"

MenuButton::MenuButton(std::shared_ptr<InputHandler> &InputHandler)
    : ShooterObject(), m_callback(0), m_bReleased(true), m_inputHandler() {}

void MenuButton::load(std::unique_ptr<LoaderParams> const &pParams) {
  ShooterObject::load(std::move(pParams));
  m_callbackID = pParams->getCallbackID();
  m_currentFrame = MOUSE_OUT;
}

void MenuButton::draw() { ShooterObject::draw(); }

void MenuButton::update() {
  Vector2D *pMousePos = m_inputHandler->getMousePosition();

  if (pMousePos->getX() < (m_position.getX() + m_width) &&
      pMousePos->getX() > m_position.getX() &&
      pMousePos->getY() < (m_position.getY() + m_height) &&
      pMousePos->getY() > m_position.getY()) {
    if (m_inputHandler->getMouseButtonState(LEFT) && m_bReleased) {
      m_currentFrame = CLICKED;

      if (m_callback != 0) {
        m_callback();
      }

      m_bReleased = false;
    } else if (!m_inputHandler->getMouseButtonState(LEFT)) {
      m_bReleased = true;
      m_currentFrame = MOUSE_OVER;
    }
  } else {
    m_currentFrame = MOUSE_OUT;
  }
}

void MenuButton::clean() { ShooterObject::clean(); }
