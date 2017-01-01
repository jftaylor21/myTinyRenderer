#ifndef VEC_HPP
#define VEC_HPP

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
        Vec3f(int _x, int _y, int _z) : x(_x), y(_y), z(_z){}
        
        Vec3f operator-(const Vec3f& rhs) const
        {
            return Vec3f(x-rhs.x, y-rhs.y, z-rhs.z);
        }
        
        float x;
        float y;
        float z;
    };
}

#endif
