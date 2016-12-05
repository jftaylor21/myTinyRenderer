#ifndef WAVEFRONT_HPP
#define WAVEFRONT_HPP

#include <string>
#include <vector>

struct Vec3f
{
    Vec3f() : x(0), y(0), z(0) {}
    
    float x;
    float y;
    float z;
};

class Wavefront
{
public:
    Wavefront(const std::string& filename);
    
    // vertexIndex is 0-based
    Vec3f geometricVertex(int vertexIndex);
    size_t numGeometricVertices() const;
    
    // faceIndex is 0-based
    std::vector<int> faceGeometricVertices(int faceIndex);
    size_t numFaceGeometricVertices() const;
    
private:
    std::vector<Vec3f> fGeometricVertices;
    std::vector<std::vector<int>> fFaceGeometricVertices;
};

#endif
