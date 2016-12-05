#ifndef LINE_HPP
#define LINE_HPP

#include "datatypes/Vec.hpp"
#include "tgaimage/tgaimage.h"

namespace tinyrenderer
{
    void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor& color);
    
    void line(const datatypes::Vec2i& p0, const datatypes::Vec2i& p1, TGAImage &image, const TGAColor& color);
}

#endif
