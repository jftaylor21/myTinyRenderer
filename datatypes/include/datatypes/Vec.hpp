#ifndef VEC_HPP
#define VEC_HPP

namespace datatypes
{
    struct Vec2i
    {
        Vec2i() : x(0), y(0){}
        
        int x;
        int y;
    };
    
    struct Vec3f
    {
        Vec3f() : x(0), y(0), z(0) {}
        
        float x;
        float y;
        float z;
    };
}

#endif
