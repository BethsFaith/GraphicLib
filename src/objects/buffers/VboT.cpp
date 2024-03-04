//
// Created by VerOchka on 22.09.2023.
//

#include "GraphicLib/Objects/Buffers/Vbo.hpp"
#include "GraphicLib/Objects/Buffers/Vertex.hpp"
#include "Vbo.cpp"

template class GraphicLib::Objects::Buffers::VBO<GraphicLib::Objects::Buffers::Vertex>;

template class GraphicLib::Objects::Buffers::VBO<glm::vec3>;

template class GraphicLib::Objects::Buffers::VBO<glm::vec4>;
