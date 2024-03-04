//
// Created by BethsFaith on 28.01.2024.
//

#ifndef ROLLANDPLAY_FORM_HPP
#define ROLLANDPLAY_FORM_HPP

#include "GraphicLib/Objects/GlagGlfw.hpp"
#include "GraphicLib/Objects/Object.hpp"
#include "GraphicLib/Objects/Techniques/ColorTechnique.hpp"
#include "GraphicLib/Objects/Techniques/PickTechnique.hpp"
#include "GraphicLib/Objects/Techniques/TextTechnique.hpp"
#include "GraphicLib/Objects/Techniques/TransformTechnique.hpp"
#include "GraphicLib/Objects/Techniques/TextureTechnique.hpp"

#include "GraphicLib/Objects/PickableTexture.hpp"

namespace GraphicLib::Widgets::Graphic {
    class Form {
    public:
        using Ptr = std::shared_ptr<Form>;

        explicit Form(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);

        virtual void setTransform(glm::vec2 position, glm::vec2 scale);
        virtual void setTransform(glm::vec2 position);
        virtual void setScale(glm::vec2 scale);
        virtual void setText(std::u16string content);
        virtual void setText(std::u16string content, glm::vec3 color);
        virtual void setTextPosition(glm::vec2 position);
        virtual void setTextSize(float scale);
        virtual void setTextColor(glm::vec3 color);
        virtual void setColor(glm::vec3 color);
        virtual void setTexture(Objects::Textures::Texture::Ptr, int textureIndex);

        glm::vec2 getScale();
        glm::vec2 getPosition();
        std::u16string getText();
        glm::vec2 getTextPosition();
        float getTextScale();
        glm::vec3 getTextColor();
        glm::vec3 getColor();
        Objects::Textures::Texture::Ptr getTexture();

        virtual void renderText(Objects::Shaders::ShaderProgram::Ptr shader);
        virtual void renderForm(Objects::Shaders::ShaderProgram::Ptr shader);

    protected:
        Objects::Object _object{};
    };
}    //namespace Widgets::Graphic

#endif    //ROLLANDPLAY_FORM_HPP
