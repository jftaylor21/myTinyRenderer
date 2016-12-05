#ifndef WAVEFRONT_HPP
#define WAVEFRONT_HPP

#include "datatypes/Vec.hpp"

#include <string>
#include <vector>

class Wavefront
{
public:
    Wavefront(const std::string& filename);
    
    // vertexIndex is 0-based
    datatypes::Vec3f geometricVertex(int vertexIndex);
    size_t numGeometricVertices() const;
    
    // faceIndex is 0-based
    std::vector<int> faceGeometricVertices(int faceIndex);
    size_t numFaceGeometricVertices() const;
    
private:
    std::vector<datatypes::Vec3f> fGeometricVertices;
    std::vector<std::vector<int>> fFaceGeometricVertices;
};

#endif
