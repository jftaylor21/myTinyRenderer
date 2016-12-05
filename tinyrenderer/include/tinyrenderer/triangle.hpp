#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "datatypes/Vec.hpp"
#include "tgaimage/tgaimage.h"

namespace tinyrenderer
{
    void triangle(datatypes::Vec2i& t0, datatypes::Vec2i& t1, datatypes::Vec2i& t2, TGAImage &image, const TGAColor& color);
}

#endif
