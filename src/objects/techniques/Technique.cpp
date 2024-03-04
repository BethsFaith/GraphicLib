//
// Created by VerOchka on 23.10.2023.
//

#include "GraphicLib/Objects/Techniques/Technique.hpp"

namespace GraphicLib::Objects::Techniques {
    void Technique::setShader(GraphicLib::Objects::Shaders::ShaderProgram::Ptr shaderProgram) {
        shader = std::move(shaderProgram);
    }

    void Technique::enable() {
        enabled = true;
    }

    void Technique::disable() {
        enabled = false;
    }

    bool Technique::isEnabled() const {
        return enabled;
    }
}    //namespace GraphicLib::Techniques
