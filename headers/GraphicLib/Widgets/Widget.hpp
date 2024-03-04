//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_WIDGET_HPP
#define ROLLANDPLAY_WIDGET_HPP

#include "GraphicLib/Objects/PickableTexture.hpp"
#include "GraphicLib/Objects/Shaders/ShaderProgram.hpp"

#include "WidgetType.hpp"

namespace GraphicLib::Widgets {
    class Widget {
    public:
        using Ptr = std::shared_ptr<Widget>;

        explicit Widget(WidgetType type);
        virtual ~Widget() = default;

        virtual bool checkSelecting(unsigned int x, unsigned int y) = 0;

        virtual void draw(Objects::Shaders::ShaderProgram::Ptr colorShader,
                          Objects::Shaders::ShaderProgram::Ptr textureShader,
                          Objects::Shaders::ShaderProgram::Ptr textShader,
                          Objects::Shaders::ShaderProgram::Ptr pickShader) = 0;

        virtual void setTransform(glm::vec2 position, glm::vec2 scale) = 0;
        virtual void setTransform(glm::vec2 position) = 0;
        virtual void setScale(glm::vec2 scale) = 0;

        virtual void setCanvas(const Objects::PickableTexture::Ptr& pickableTexture);

        virtual glm::vec2 getScale() = 0;
        virtual glm::vec2 getPosition() = 0;

        [[nodiscard]] WidgetType getType() const;

    protected:
        Objects::PickableTexture::Ptr canvas;

    private:
        WidgetType _type;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_WIDGET_HPP
