#include "tinyrenderer/line.hpp"
#include "tinyrenderer/triangle.hpp"

void tinyrenderer::triangle(datatypes::Vec2i& t0, datatypes::Vec2i& t1, datatypes::Vec2i& t2, TGAImage &image, const TGAColor& color)
{
    // sort vertices by y in ascending order
    if (t0.y > t1.y)
    {
        std::swap(t0, t1);
    }
    if (t0.y > t2.y)
    {
        std::swap(t0, t2);
    }
    if (t1.y > t2.y)
    {
        std::swap(t1, t2);
    }
    
    //line(t0, t1, image, color);
    //line(t1, t2, image, color);
    //line(t2, t0, image, color);
    
    auto lineSweeper = [&image, &color](float lx, float ldx, float rx, float rdx, int y0, int height)
    {
        for(int y = y0; y < y0 + height; ++y)
        {
            lx += ldx;
            rx += rdx;
            line(lx, y, rx, y, image, color);
        }
    };
    
    // draw segments t0 and t1 (line sweeping)
    float ldx = 0;
    if (t2.y - t0.y != 0)
    {
        ldx = (t2.x - t0.x) * 1. / (t2.y - t0.y); // left dx
    }
    float rdx = 0;
    if (t1.y - t0.y != 0)
    {
        rdx = (t1.x - t0.x) * 1. / (t1.y - t0.y); // right dx
    }
    lineSweeper(t0.x, ldx, t0.x, rdx, t0.y, t1.y - t0.y);
    
    // draw segments t1 and t2 (line sweeping)
    rdx = 0; // recalc rdx to be from t1 to t2 (ldx is already from t0 to t2)
    if (t2.y - t1.y != 0)
    {
        rdx = (t2.x - t1.x) * 1. / (t2.y - t1.y); // right dx
    }
    int lx = ldx * (t1.y - t0.y) + t0.x;
    int rx = t1.x;
    lineSweeper(lx, ldx, rx, rdx, t1.y, t2.y - t1.y);
}
