#ifndef VEC_HPP
#define VEC_HPP

#include <cmath>

namespace datatypes
{
    struct Vec2i
    {
        Vec2i() : x(0), y(0){}
        Vec2i(int _x, int _y) : x(_x), y(_y){}
        
        int x;
        int y;
    };
    
    struct Vec3f
    {
        Vec3f() : x(0), y(0), z(0) {}
        Vec3f(float _x, float _y, float _z) : x(_x), y(_y), z(_z){}
        
        Vec3f operator-(const Vec3f& rhs) const
        {
            return Vec3f(x-rhs.x, y-rhs.y, z-rhs.z);
        }
        
        Vec3f crossProduct(const Vec3f& rhs) const
        {
            return Vec3f(y * rhs.z - z * rhs.y,
                         z * rhs.x - x * rhs.z,
                         x * rhs.y - y * rhs.x);
        }
        
        float magnitude() const
        {
            return sqrt(x*x + y*y + z*z);
        }
        
        float x;
        float y;
        float z;
    };
}

#endif
