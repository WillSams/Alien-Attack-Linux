#pragma once

#include "GameObjectFactory.h"
#include "ShooterObject.h"

class MenuButton : public ShooterObject {
public:
  MenuButton(std::shared_ptr<InputHandler> &inputHandler);
  virtual ~MenuButton() {}

  virtual void load(std::unique_ptr<LoaderParams> const &pParams);

  virtual void draw();
  virtual void update();
  virtual void clean();

  void setCallback(void (*callback)()) { m_callback = callback; }
  int getCallbackID() { return m_callbackID; }

private:
  enum button_state { MOUSE_OUT = 0, MOUSE_OVER = 1, CLICKED = 2 };

  bool m_bReleased;
  int m_callbackID;
  void (*m_callback)();

  std::shared_ptr<InputHandler> m_inputHandler;
};

class MenuButtonCreator : public BaseCreator {
  GameObject *
  createGameObject(std::shared_ptr<InputHandler> &inputHandler) const {
    return new MenuButton(inputHandler);
  }
};
