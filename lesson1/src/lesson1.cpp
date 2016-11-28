#include "tgaimage/tgaimage.h"
#include "TGAColors.hpp"

namespace
{
    void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor& color)
    { 
        for (float t=0.; t<1.; t+=.01)
        { 
            int x = x0*(1.-t) + x1*t; 
            int y = y0*(1.-t) + y1*t; 
            image.set(x, y, color); 
        } 
    }
}

// creates output.tga which is a blue image
int main()
{
    int width = 255;
    int height = 255;
    TGAImage image(width, height, TGAImage::RGB);
    line(0, 0, width, height, image, COLOR_BLUE);
    image.write_tga_file("output.tga");
    
    return 0;
}