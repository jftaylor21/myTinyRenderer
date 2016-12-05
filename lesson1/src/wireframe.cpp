#include "tinyrenderer/line.hpp"
#include "wavefront/wavefront.hpp"
#include "TGAColors.hpp"

int main()
{
    const int width = 255;
    const int height = 255;
    TGAImage image(width, height, TGAImage::RGB);
    
    Wavefront wf("../wavefront/models/african_head.obj");
    
    for (int i(0); i < wf.numFaceGeometricVertices(); ++i)
    { 
        std::vector<int> face = wf.faceGeometricVertices(i);
        for (int j(0); j < face.size(); ++j)
        { 
            Vec3f v0 = wf.geometricVertex(face[j]); 
            Vec3f v1 = wf.geometricVertex(face[(j+1)%face.size()]);
            
            // Each vertex xyz is between -1,1, so we need to add 1 to shift it
            // between 0,2. We later divide by 2 to change range to 0,1
            int x0 = (v0.x + 1.) * width / 2.; 
            int y0 = (v0.y + 1.) * height / 2.; 
            int x1 = (v1.x + 1.) * width / 2.; 
            int y1 = (v1.y + 1.) * height / 2.; 
            tinyrenderer::line(x0, y0, x1, y1, image, COLOR_WHITE); 
        } 
    }
    
    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}
