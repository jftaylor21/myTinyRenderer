#include "tgaimage/tgaimage.h"

// creates output.tga which is a blue image
int main()
{
    int width = 255;
    int height = 255;
    TGAColor blue(0, 0, 255, 255);
    
    TGAImage image(width, height, TGAImage::RGB);
    for(int w = 0; w < width; ++w)
    {
        for(int h = 0; h < height; ++h)
        {
            image.set(w, h, blue);
        }
    }
    image.write_tga_file("output.tga");
    
    return 0;
}