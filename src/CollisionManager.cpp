#include <memory>

#include "CollisionManager.h"

const int CollisionManager::s_buffer = 4;

bool CollisionManager::RectRect(std::shared_ptr<SDL_Rect> &A, std::shared_ptr<SDL_Rect> &B) {
    int aHBuf = A->h / s_buffer;
    int aWBuf = A->w / s_buffer;
    
    int bHBuf = B->h / s_buffer;
    int bWBuf = B->w / s_buffer;
    
    // if the bottom of A is less than the top of B - no collision
    if((A->y + A->h) - aHBuf <= B->y + bHBuf)  { return false; }
    
    // if the top of A is more than the bottom of B = no collision
    if(A->y + aHBuf >= (B->y + B->h) - bHBuf)  { return false; }
    
    // if the right of A is less than the left of B - no collision
    if((A->x + A->w) - aWBuf <= B->x +  bWBuf) { return false; }
    
    // if the left of A is more than the right of B - no collision
    if(A->x + aWBuf >= (B->x + B->w) - bWBuf)  { return false; }
    
    // otherwise there has been a collision
    return true;
}

void CollisionManager::checkPlayerEnemyBulletCollision(Player* pPlayer) {
    auto pRect1 = std::make_shared<SDL_Rect>();
    pRect1->x = pPlayer->getPosition().getX();
    pRect1->y = pPlayer->getPosition().getY();
    pRect1->w = pPlayer->getWidth();
    pRect1->h = pPlayer->getHeight();
    
    for(unsigned int i = 0; i < 
            TheBulletHandler::Instance()->getEnemyBullets().size(); i++) {
        auto pEnemyBullet = TheBulletHandler::Instance()->getEnemyBullets()[i];
        
        auto pRect2 = std::make_shared<SDL_Rect>();
        pRect2->x = pEnemyBullet->getPosition().getX();
        pRect2->y = pEnemyBullet->getPosition().getY();
        
        pRect2->w = pEnemyBullet->getWidth();
        pRect2->h = pEnemyBullet->getHeight();
        
        if(RectRect(pRect1, pRect2)) {
            if(!pPlayer->dying() && !pEnemyBullet->dying()) {
                pEnemyBullet->collision();
                pPlayer->collision();
            }
        }
    }
}

void CollisionManager::checkEnemyPlayerBulletCollision(
        const std::vector<GameObject *> &objects) {
    for(unsigned int i = 0; i < objects.size(); i++) {
        auto pObject = objects[i];
        
        for(unsigned int j = 0; j < 
                TheBulletHandler::Instance()->getPlayerBullets().size(); j++) {
            if(pObject->type() != std::string("Enemy") || !pObject->updating()) {
                continue;
            }
            
            auto pRect1 = std::make_shared<SDL_Rect>();
            pRect1->x = pObject->getPosition().getX();
            pRect1->y = pObject->getPosition().getY();
            pRect1->w = pObject->getWidth();
            pRect1->h = pObject->getHeight();
            
            auto pPlayerBullet = TheBulletHandler::Instance()->
                getPlayerBullets()[j];
            
            auto pRect2 = std::make_shared<SDL_Rect>();
            pRect2->x = pPlayerBullet->getPosition().getX();
            pRect2->y = pPlayerBullet->getPosition().getY();
            pRect2->w = pPlayerBullet->getWidth();
            pRect2->h = pPlayerBullet->getHeight();
            
            if(RectRect(pRect1, pRect2)) {
                if(!pObject->dying() && !pPlayerBullet->dying()) {
                    pPlayerBullet->collision();
                    pObject->collision();
                }                
            }            
        }
    }
}

void CollisionManager::checkPlayerEnemyCollision(Player* pPlayer, 
        const std::vector<GameObject*> &objects) {
    auto pRect1 = std::make_shared<SDL_Rect>();
    pRect1->x = pPlayer->getPosition().getX();
    pRect1->y = pPlayer->getPosition().getY();
    pRect1->w = pPlayer->getWidth();
    pRect1->h = pPlayer->getHeight();
    
    for(unsigned int i = 0; i < objects.size(); i++) {
        if(objects[i]->type() != std::string("Enemy") || !objects[i]->updating()) {
            continue;
        }
        
        auto pRect2 = std::make_shared<SDL_Rect>();
        pRect2->x = objects[i]->getPosition().getX();
        pRect2->y = objects[i]->getPosition().getY();
        pRect2->w = objects[i]->getWidth();
        pRect2->h = objects[i]->getHeight();
        
        if(RectRect(pRect1, pRect2)) {
            if(!objects[i]->dead() && !objects[i]->dying()) {
                pPlayer->collision();
            }
        }
    }
}

void CollisionManager::checkPlayerTileCollision(Player* pPlayer, 
        const std::vector<TileLayer*>& collisionLayers) {
    for(auto it = collisionLayers.begin(); 
            it != collisionLayers.end(); ++it) {
        TileLayer* pTileLayer = (*it);
        std::vector<std::vector<int>> tiles = pTileLayer->getTileIDs();
        
        Vector2D layerPos = pTileLayer->getPosition();
        
        int x, y, tileColumn, tileRow, tileid = 0;
        
        x = layerPos.getX() / pTileLayer->getTileSize();
        y = layerPos.getY() / pTileLayer->getTileSize();
        
        if(pPlayer->getVelocity().getX() >= 0 || pPlayer->getVelocity().getY() >= 0) {
            tileColumn = ((pPlayer->getPosition().getX() + 
                pPlayer->getWidth()) / pTileLayer->getTileSize());
            tileRow = ((pPlayer->getPosition().getY() + 
                pPlayer->getHeight()) / pTileLayer->getTileSize());
            tileid = tiles[tileRow + y][tileColumn + x];
        }
        else if(pPlayer->getVelocity().getX() < 0 || 
                pPlayer->getVelocity().getY() < 0) {
            tileColumn = pPlayer->getPosition().getX() / pTileLayer->getTileSize();
            tileRow = pPlayer->getPosition().getY() / pTileLayer->getTileSize();
            tileid = tiles[tileRow + y][tileColumn + x];
        }
        
        if(tileid != 0) { pPlayer->collision(); }
    }
}