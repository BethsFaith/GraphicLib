//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_OBJECT_HPP
#define ROLLANDPLAY_OBJECT_HPP

#include <map>
#include <utility>

#include "GraphicLib/Objects/Primitives/AbstractPrimitive.hpp"
#include "GraphicLib/Objects/Shaders/ShaderProgram.hpp"
#include "GraphicLib/Objects/Techniques/Technique.hpp"
#include "GraphicLib/Objects/Techniques/TechniqueName.hpp"

namespace GraphicLib::Objects {
    class Object {
    public:
        using Ptr = std::shared_ptr<Object>;

        Object() = default;
        virtual ~Object() = default;

        virtual void render(Shaders::ShaderProgram::Ptr shader);

        void addTechnique(Techniques::TechniqueName name, Techniques::Technique::Ptr technique);
        void removeTechnique(Techniques::TechniqueName name);
        void enableTechnique(Techniques::TechniqueName name);
        void disableTechnique(Techniques::TechniqueName name);
        bool hasTechnique(Techniques::TechniqueName name);

        void setPrimitive(const Primitives::AbstractPrimitive::Ptr &primitive);

        Techniques::Technique::Ptr getTechnique(Techniques::TechniqueName name);

    protected:
        std::map<Techniques::TechniqueName, Techniques::Technique::Ptr> techniques;

    private:
        Primitives::AbstractPrimitive::Ptr _primitive;
    };
}

#endif //ROLLANDPLAY_OBJECT_HPP
