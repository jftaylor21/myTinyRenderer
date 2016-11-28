#include "tgaimage/tgaimage.h"
#include "TGAColors.hpp"

#include <cmath>

namespace
{
    void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor& color)
    {
        // draw the maximum number of points by checking to see whether
        // the biggest difference is in x or y
        bool xAndYAreSwapped = false;
        if (std::abs(x1 - x0) < std::abs(y1 - y0))
        {
            std::swap(x0, y0);
            std::swap(x1, y1);
            xAndYAreSwapped = true;
        }
        
        // We assume that x0 to x1 is increasing. If it is not, we need to
        // flip the line.
        if (x0 > x1)
        {
            std::swap(x0, x1);
            std::swap(y0, y1);
        }
        
        // initialize error variables (multiplied by 2)
        int dx = x1 - x0;
        int dy = y1 - y0;
        int derror2 = std::abs(dy) * 2; // error accumulated at each step
        int totalError2 = 0;
        
        // draw the line
        int y = y0;
        for (int x = x0; x <= x1; ++x)
        {
            if (xAndYAreSwapped)
            {
                image.set(y, x, color);
            }
            else
            {
                image.set(x, y, color);
            }
            
            // account for error
            // if totalError is > 0.5, move y 1 unit further in the current 
            // direction
            totalError2 += derror2;
            if (totalError2 > dx)
            {
                // add or subtract 1 depending on which direction we are drawing
                y += (y1 > y0 ? 1 : -1);
                totalError2 -= dx * 2;
            }
        }
    }
}

// creates output.tga which is a blue image
int main()
{
    const int width = 255;
    const int height = 255;
    TGAImage image(width, height, TGAImage::RGB);
    
    // draw blue x across screen
    line(0, 0, width, height, image, COLOR_BLUE);
    line(width, 0, 0, height, image, COLOR_BLUE);
    
    // make one of the x lines blue
    line(width, height, 0, 0, image, COLOR_RED);
    
    // draw horizontal line
    line(0, height/2, width, height/2, image, COLOR_GREEN);
    
    // draw vertical line
    line(width/2, 0, width/2, height, image, COLOR_GREEN);
    
    image.write_tga_file("output.tga");
    
    return 0;
}