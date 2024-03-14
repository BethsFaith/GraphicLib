//
// Created by BethsFaith on 14.03.2024.
//

#ifndef GRAPHICLIB_GUIOBJECT_HPP
#define GRAPHICLIB_GUIOBJECT_HPP

#include "GraphicLib/Shaders/ShaderProgram.hpp"
#include "GuiObjectType.hpp"

namespace GraphicLib::GuiObjects {
    class GuiObject {
    public:
        using Ptr = std::shared_ptr<GuiObject>;

        virtual void setTransform(glm::vec2 position, glm::vec2 scale) = 0;
        virtual void setTransform(glm::vec2 position) = 0;
        virtual void setScale(glm::vec2 scale) = 0;

        virtual glm::vec2 getScale() = 0;
        virtual glm::vec2 getPosition() = 0;

        [[nodiscard]] virtual GuiObjectType getGuiType() const = 0;
    };
}

#endif    //GRAPHICLIB_GUIOBJECT_HPP
