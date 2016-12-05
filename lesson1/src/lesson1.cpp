#include "tgaimage/tgaimage.h"
#include "tinyrenderer/line.hpp"
#include "TGAColors.hpp"

#include <cmath>

// creates output.tga which is a blue image
int main()
{
    const int width = 255;
    const int height = 255;
    TGAImage image(width, height, TGAImage::RGB);
    
    // draw blue x across screen
    tinyrenderer::line(0, 0, width, height, image, COLOR_BLUE);
    tinyrenderer::line(width, 0, 0, height, image, COLOR_BLUE);
    
    // make one of the x lines blue
    tinyrenderer::line(width, height, 0, 0, image, COLOR_RED);
    
    // draw horizontal line
    tinyrenderer::line(0, height/2, width, height/2, image, COLOR_GREEN);
    
    // draw vertical line
    tinyrenderer::line(width/2, 0, width/2, height, image, COLOR_GREEN);
    
    image.write_tga_file("output.tga");
    
    return 0;
}
