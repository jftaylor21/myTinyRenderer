#ifndef LINE_HPP
#define LINE_HPP

#include "tgaimage/tgaimage.h"

namespace tinyrenderer
{
    void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor& color);
}

#endif
