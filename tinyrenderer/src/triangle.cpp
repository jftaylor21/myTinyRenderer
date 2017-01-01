#include "tinyrenderer/line.hpp"
#include "tinyrenderer/triangle.hpp"

#include <cmath>

namespace
{ 
    float dot(const datatypes::Vec3f& v1, const datatypes::Vec3f& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }
    
    bool isPointInTriangle(const std::array<datatypes::Vec2i,3>& vertices, const datatypes::Vec2i& P)
    {
        // uses barycentric coordinates to check whether P is in triangle
        datatypes::Vec3f v0(vertices[1].x - vertices[0].x, vertices[1].y - vertices[0].y, 0);
        datatypes::Vec3f v1(vertices[2].x - vertices[0].x, vertices[2].y - vertices[0].y, 0);
        datatypes::Vec3f v2(P.x - vertices[0].x, P.y - vertices[0].y, 0);
        float d00 = dot(v0, v0);
        float d01 = dot(v0, v1);
        float d02 = dot(v0, v2);
        float d11 = dot(v1, v1);
        float d12 = dot(v1, v2);
        float denom = d00 * d11 - d01 * d01;
        float u = (d11 * d02 - d01 * d12) / denom;
        float v = (d00 * d12 - d01 * d02) / denom;
        return (u >= 0) && (v >= 0) && (u + v < 1);
    }
}

void tinyrenderer::triangle(const datatypes::Vec2i& t0, const datatypes::Vec2i& t1, const datatypes::Vec2i& t2, TGAImage &image, const TGAColor& color)
{
    std::array<datatypes::Vec2i, 3> vertices = {t0, t1, t2};
    triangle(vertices, image, color);
}

void tinyrenderer::triangle(const std::array<datatypes::Vec2i,3>& vertices, TGAImage &image, const TGAColor& color)
{
    // get bounding box of triangle
    datatypes::Vec2i bboxmin(vertices[0]);
    bboxmin.x = std::min(bboxmin.x, vertices[1].x);
    bboxmin.x = std::min(bboxmin.x, vertices[2].x);
    bboxmin.y = std::min(bboxmin.y, vertices[1].y);
    bboxmin.y = std::min(bboxmin.y, vertices[2].y);
    datatypes::Vec2i bboxmax(vertices[0]);
    bboxmax.x = std::max(bboxmax.x, vertices[1].x);
    bboxmax.x = std::max(bboxmax.x, vertices[2].x);
    bboxmax.y = std::max(bboxmax.y, vertices[1].y);
    bboxmax.y = std::max(bboxmax.y, vertices[2].y);
    
    // check each point in bounding box to see if it is in triangle
    datatypes::Vec2i P;
    for(P.x = bboxmin.x; P.x <= bboxmax.x; ++P.x)
    {
        for(P.y = bboxmin.y; P.y <= bboxmax.y; ++P.y)
        {
            if (isPointInTriangle(vertices, P))
            {
                image.set(P.x, P.y, color);
            }
        }
    }
}
