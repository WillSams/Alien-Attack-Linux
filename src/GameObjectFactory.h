#ifndef GAMEOBJECTFACTORY_H_DEFINED
#define GAMEOBJECTFACTORY_H_DEFINED

#include "GameObject.h"

#include <string>
#include <map>
#include <iostream>

class BaseCreator {
    
public:    
    virtual GameObject* createGameObject() const = 0;
    virtual ~BaseCreator();
};

class GameObjectFactory {
    
public:    
    static GameObjectFactory* Instance();
    
    bool registerType(std::string typeID, BaseCreator* pCreator);
    
    GameObject* create(std::string typeID);
    
private:
    
    GameObjectFactory();
    ~GameObjectFactory();
    
    std::map<std::string, BaseCreator*> m_creators;
    
    static GameObjectFactory* pInstance;
};

typedef GameObjectFactory TheGameObjectFactory;

#endif /* defined(GAMEOBJECTFACTORY_H_DEFINED) */
