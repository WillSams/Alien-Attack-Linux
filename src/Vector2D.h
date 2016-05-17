#ifndef VECTOR2D_H_DEFINED
#define VECTOR2D_H_DEFINED

#include <iostream>
#include <math.h>

class Vector2D {
    
public:
    Vector2D();
    Vector2D(float x, float y);
    
    virtual ~Vector2D();    
    
    virtual const float getX();
    virtual const float getY();
    
    virtual void setX(float x);
    virtual void setY(float y);
    
    virtual int length();
    
    Vector2D operator+(const Vector2D& v2) const { 
        return Vector2D(m_x + v2.m_x, m_y + v2.m_y); 
    }
    
    friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2) {
        v1.m_x += v2.m_x;
        v1.m_y += v2.m_y;
        
        return v1;
    }
    
    Vector2D operator-(const Vector2D& v2) const { 
        return Vector2D(m_x - v2.m_x, m_y - v2.m_y); 
    }
    
    friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2)  {
        v1.m_x -= v2.m_x;
        v1.m_y -= v2.m_y;
        
        return v1;
    }
    
    Vector2D operator*(float scalar) {
        return Vector2D(m_x * scalar, m_y * scalar);
    }
    
    Vector2D& operator*=(float scalar) {
        m_x *= scalar;
        m_y *= scalar;
        
        return *this;
    }
    
    Vector2D operator/(float scalar) {
        return Vector2D(m_x / scalar, m_y / scalar);
    }
    
    Vector2D& operator/=(float scalar) {
        m_x /= scalar;
        m_y /= scalar;
        
        return *this;
    }

private:    
    virtual void normalize();  
    
    float m_x;
    float m_y;
};

#endif /* defined(VECTOR2D_H_DEFINED) */
