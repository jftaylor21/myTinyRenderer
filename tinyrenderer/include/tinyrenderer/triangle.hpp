#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "datatypes/Vec.hpp"
#include "tgaimage/tgaimage.h"

namespace tinyrenderer
{
    void triangle(const datatypes::Vec2i& t0, const datatypes::Vec2i& t1, const datatypes::Vec2i& t2, TGAImage &image, const TGAColor& color);
}

#endif
