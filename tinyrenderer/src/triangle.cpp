#include "tinyrenderer/line.hpp"
#include "tinyrenderer/triangle.hpp"

void tinyrenderer::triangle(const datatypes::Vec2i& t0, const datatypes::Vec2i& t1, const datatypes::Vec2i& t2, TGAImage &image, const TGAColor& color)
{
    line(t0, t1, image, color);
    line(t1, t2, image, color);
    line(t2, t0, image, color);
}
