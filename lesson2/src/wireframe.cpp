#include "tinyrenderer/triangle.hpp"
#include "wavefront/wavefront.hpp"
#include "tinyrenderer/TGAColors.hpp"

#include <cassert>

int main()
{
    const int width = 255;
    const int height = 255;
    TGAImage image(width, height, TGAImage::RGB);
    
    Wavefront wf("../wavefront/models/african_head.obj");
    
    for (int i(0); i < wf.numFaceGeometricVertices(); ++i)
    { 
        std::vector<int> face = wf.faceGeometricVertices(i);
        assert(face.size() == 3);
        std::array<datatypes::Vec3f,3> t;
        std::array<datatypes::Vec2i,3> scaledT;
        for (int j = 0; j < face.size(); ++j)
        {
            datatypes::Vec3f vf(wf.geometricVertex(face[j]));
            t[j] = vf;
            datatypes::Vec2i vi((vf.x + 1.) * width / 2., (vf.y + 1.) * height / 2.);
            scaledT[j] = vi;
        }
        datatypes::Vec3f normal(datatypes::Vec3f(t[2].x-t[0].x, t[2].y-t[0].y, t[2].z-t[0].z).crossProduct(
                                    datatypes::Vec3f(t[1].x-t[0].x, t[1].y-t[0].y, t[1].z-t[0].z)));
        float intensity = -1*normal.z / normal.magnitude();
        if (intensity > 0)
        {
            tinyrenderer::triangle(scaledT,
                                   image,
                                   TGAColor(intensity*255, intensity*255, intensity*255, 255));
        }
    }
    
    image.flip_vertically();
    image.write_tga_file("output.tga");

    return 0;
}
