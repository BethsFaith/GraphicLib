//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_WIDGET_HPP
#define ROLLANDPLAY_WIDGET_HPP

#include "GraphicLib/Objects/PickableTexture.hpp"
#include "GuiObject.hpp"
#include "WidgetType.hpp"

namespace GraphicLib::GuiObjects {
    class Widget : public GuiObject {
    public:
        using Ptr = std::shared_ptr<Widget>;

        explicit Widget(WidgetType type);
        virtual ~Widget() = default;

        virtual bool checkSelecting(unsigned int x, unsigned int y) = 0;

        virtual void draw(Shaders::ShaderProgram::Ptr colorShader,
                          Shaders::ShaderProgram::Ptr textureShader,
                          Shaders::ShaderProgram::Ptr textShader,
                          Shaders::ShaderProgram::Ptr pickShader) = 0;

        virtual void setCanvas(const Objects::PickableTexture::Ptr& pickableTexture);

        [[nodiscard]] WidgetType getType() const;
        GuiObjectType getGuiType() const override;

    protected:
        Objects::PickableTexture::Ptr canvas;

    private:
        WidgetType _type;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_WIDGET_HPP
