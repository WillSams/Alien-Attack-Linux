#ifndef MOCKS_HPP
#define	MOCKS_HPP

#include <functional>
#include <iostream>
#include <memory>

#include <gmock/gmock.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

#include "../src/Bullet.h"
#include "../src/ShooterObject.h"

class MockPlayerBullet : public PlayerBullet {    
    public:
        virtual ~MockPlayerBullet() {}

        MOCK_METHOD0(type, std::string());
        MOCK_METHOD2(load, void(LoaderParams* pParams, Vector2D heading));    
        MOCK_METHOD0(draw, void());    
        MOCK_METHOD0(collision, void());
        MOCK_METHOD0(update, void());
        MOCK_METHOD0(clean, void());
};

#include "../src/LoaderParams.h"
class MockLoaderParams : public LoaderParams {   
    public:
        virtual ~MockLoaderParams() {}
    
};

#include "../src/Vector2D.h"
class MockVector2D : public Vector2D {   
    public:
        virtual ~MockVector2D() {}
    
};

#include "../src/BulletHandler.h"
class MockBulletHandler : public BulletHandler {
    public:
        MOCK_METHOD7(addPlayerBullet, void (int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading));
        MOCK_METHOD7(addEnemyBullet, void (int x, int y, int width, int height, std::string textureID, int numFrames, Vector2D heading));

        MOCK_METHOD0(updateBullets, void());
        MOCK_METHOD0(drawBullets, void());

        MOCK_METHOD0(clearBullets, void());
};


#include "../src/Game.h"
class MockGame: public Game {
    public:
        MOCK_METHOD0(render, void());
        MOCK_METHOD0(update, void());
        MOCK_METHOD0(handleEvents, void());
        MOCK_METHOD0(clean, void()); 
};

/*
#include "../Aircraft.hpp"

class MockAircraft : public Aircraft {
    public:
        MOCK_CONST_METHOD0(getCategory, unsigned int());
        MOCK_CONST_METHOD0(getBoundingRect, sf::FloatRect());
        MOCK_METHOD0(remove, void());
        MOCK_CONST_METHOD0(isMarkedForRemoval, bool());
        MOCK_CONST_METHOD2(drawCurrent, void(sf::RenderTarget& target, sf::RenderStates states));
        MOCK_METHOD2(updateCurrent, void(sf::Time dt, CommandQueue& commands));
        MOCK_CONST_METHOD0(isAllied, float());
        MOCK_CONST_METHOD0(getMaxSpeed, float());
        MOCK_METHOD0(disablePickups, void());
        MOCK_METHOD0(increaseFireRate, void());
        MOCK_METHOD0(increaseSpread, void());
        MOCK_METHOD1(collectMissles, void(unsigned int count));
        MOCK_METHOD0(fire, void());
        MOCK_METHOD0(launchMissle, void());
        MOCK_METHOD2(playLocalSound, void(CommandQueue& commands, SoundEffect::ID effect));
        MOCK_METHOD0(getIdentifier, int());
        MOCK_METHOD1(setIdentifier, void(int identifier));
        MOCK_CONST_METHOD0(getMissleAmmo, int());
        MOCK_CONST_METHOD1(setMissleAmmo, void(int ammo));
        
        MOCK_METHOD1(updateMovementPattern, void(sf::Time dt));
        MOCK_METHOD1(checkPickupDrop, void(CommandQueue& commands);
        MOCK_METHOD2(checkProjectileLaunch, void(sf::Time dt, CommandQueue& commands);

        MOCK_CONST_METHOD2(createBullets, void(SceneNode& node, const TextureHolder& textures));
        MOCK_CONST_METHOD5(createProjectile, void(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures));
        MOCK_CONST_METHOD2(createPickup, void(SceneNode& node, const TextureHolder& textures));

        MOCK_METHOD0(updateTexts, void();
        MOCK_METHOD0(updateRollAnimation, void();
};

//our mock object with our virtual public implementations
class MockButton : public GUI::Button {
    public:
        MOCK_CONST_METHOD0(isSelectable, bool());
        MOCK_METHOD0(select, void());
        MOCK_METHOD0(deselect, void());

        MOCK_METHOD0(activate, void());
        MOCK_METHOD0(deactivate, void());
        MOCK_METHOD1(handleEvent, void(const sf::Event& event));
};

// Templates to help with mocking our non-virtual implementations. 
// For example, in our tests:  
template <class GUI::Button>
void setCallback(GUI::Button* btn, std::function<void()> callback){}
*/
#endif	/* MOCKS_HPP */

