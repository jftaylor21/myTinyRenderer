#include "datatypes/Vec.hpp"
#include "tgaimage/tgaimage.h"
#include "tinyrenderer/TGAColors.hpp"
#include "tinyrenderer/triangle.hpp"

int main()
{
    const int width = 255;
    const int height = 255;
    TGAImage image(width, height, TGAImage::RGB);
    
    datatypes::Vec2i t0[3] = {datatypes::Vec2i(10, 70),
                              datatypes::Vec2i(50, 160),
                              datatypes::Vec2i(70, 80)}; 

    datatypes::Vec2i t1[3] = {datatypes::Vec2i(180, 50),
                              datatypes::Vec2i(150, 1),
                              datatypes::Vec2i(70, 180)};
    
    datatypes::Vec2i t2[3] = {datatypes::Vec2i(180, 150),
                              datatypes::Vec2i(120, 160),
                              datatypes::Vec2i(130, 180)};
    
    tinyrenderer::triangle(t0[0], t0[1], t0[2], image, tinyrenderer::COLOR_RED); 
    tinyrenderer::triangle(t1[0], t1[1], t1[2], image, tinyrenderer::COLOR_WHITE); 
    tinyrenderer::triangle(t2[0], t2[1], t2[2], image, tinyrenderer::COLOR_GREEN);
    
    image.flip_vertically();
    image.write_tga_file("output.tga");
    
    return 0;
}