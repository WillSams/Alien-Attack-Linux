#ifndef GAMEOBJECT_H_DEFINED
#define GAMEOBJECT_H_DEFINED

#include "LoaderParams.h"
#include "Vector2D.h"

#include <string>
#include <memory>

class GameObject {
    
public:    
    virtual ~GameObject();
    
    // load from file - int x, int y, int width, int height, std::string textureID, int numFrames, int callbackID = 0, int animSpeed = 0
    virtual void load(std::unique_ptr<LoaderParams> const &pParams)=0;    
    
    virtual void draw()=0;              // draw the object  
    virtual void update()=0;            // do update stuff    
    virtual void clean()=0;             // remove anything that needs to be deleted 
    virtual void collision() = 0;       // object has collided, handle accordingly 
    virtual std::string type() = 0;     // get the type of the object
    
    virtual Vector2D& getPosition();
    virtual Vector2D& getVelocity();
    
    virtual int getWidth();
    virtual int getHeight();    
    
    virtual void scroll(float scrollSpeed);         // scroll along with tile map
    
    virtual bool updating();
    virtual bool dead();    
    virtual bool dying() ;                          // is the object doing a death animation?
    
    // set whether to update the object or not
    virtual void setUpdating(bool updating);
        
protected:
    GameObject();

    // movement variables
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    
    int m_width;
    int m_height;
    
    // animation variables
    int m_currentRow;
    int m_currentFrame;
    int m_numFrames;
    std::string m_textureID;
    
    bool m_bUpdating;
    bool m_bDead;
    bool m_bDying;    
    
    double m_angle;         // rotation    
    
    int m_alpha;            // blending
};

#endif /* defined (GAMEOBJECT_H_DEFINED) */
