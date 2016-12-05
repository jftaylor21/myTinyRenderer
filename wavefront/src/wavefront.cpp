#include "wavefront/wavefront.hpp"

#include <cassert>
#include <fstream>
#include <sstream>

Wavefront::Wavefront(const std::string& filename)
{
    std::ifstream input(filename);
    
    // read line from file
    std::string line;
    while (std::getline(input, line))
    {
        // get tokens
        std::vector<std::string> tokens;
        std::istringstream parser(line);
        std::string token;
        while (parser >> token)
        {
            tokens.push_back(token);
        }
        
        // store parts of the file that we care about
        if (tokens.size() > 0)
        {
            // geometric vertex
            if (tokens[0].compare("v") == 0)
            {
                assert(tokens.size() == 4);
                
                datatypes::Vec3f v;
                v.x = std::stof(tokens[1]);
                v.y = std::stof(tokens[2]);
                v.z = std::stof(tokens[3]);
                
                fGeometricVertices.push_back(v);
            }
            else if (tokens[0].compare("f") == 0)
            {
                std::vector<int> face;
                for(int i = 1; i < tokens.size(); ++i)
                {
                    std::istringstream slashParser(tokens[i]);
                    std::string faceVertex;
                    if (std::getline(slashParser, faceVertex, '/'))
                    {
                        int faceVertex0 = std::stoi(faceVertex) - 1; // wavefront model is 1-based
                        assert(faceVertex0 >= 0);
                        face.push_back(faceVertex0);
                    }
                    else
                    {
                        assert(false);
                    }
                }
                assert(face.size() > 0);
                fFaceGeometricVertices.push_back(face);
            }
        }
    }
}

datatypes::Vec3f Wavefront::geometricVertex(int vertexIndex)
{
    assert(vertexIndex < fGeometricVertices.size() && vertexIndex >= 0);
    return fGeometricVertices[vertexIndex];
}

size_t Wavefront::numGeometricVertices() const
{
    return fGeometricVertices.size();
}

std::vector<int> Wavefront::faceGeometricVertices(int faceIndex)
{
    assert(faceIndex < fFaceGeometricVertices.size() && faceIndex >= 0);
    return fFaceGeometricVertices[faceIndex];
}

size_t Wavefront::numFaceGeometricVertices() const
{
    return fFaceGeometricVertices.size();
}
