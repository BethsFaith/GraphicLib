//
// Created by VerOchka on 06.10.2023.
//

#ifndef ROLLANDPLAY_BUTTON_HPP
#define ROLLANDPLAY_BUTTON_HPP

#include <functional>
#include <iostream>
#include <utility>

#include "Widget.hpp"
#include "graphic/PickableForm.hpp"
#include "styles/TextParams.hpp"

namespace GraphicLib::GuiObjects {
    class Button : public Widget {
    public:
        using Ptr = std::shared_ptr<Button>;

        explicit Button(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);
        ~Button() override = default;

        void draw(Shaders::ShaderProgram::Ptr colorShader,
                  Shaders::ShaderProgram::Ptr textureShader,
                  Shaders::ShaderProgram::Ptr textShader,
                  Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;

        glm::vec2 getPosition() override;
        glm::vec2 getScale() override;

        virtual void press();
        virtual void release();

        [[nodiscard]] bool isUnderCursor() const;
        [[nodiscard]] bool isPressed() const;

        void setScale(glm::vec2 scale) override;

        [[nodiscard]] bool checkId(int id_) const;

        void setPressCallback(const std::function<void()>& function);
        void setReleaseCallback(const std::function<void()>& function);

        void setUnderCursor(bool isUnderCursor);

        virtual void setLabelParams(const Styles::TextParams& text);
        virtual void setLabelText(const std::u16string& text);
        virtual void setLabelPosition(glm::vec2 position);
        virtual void setLabelColor(glm::vec3 color);
        virtual void setLabelTextSize(float size);
        virtual void setColor(glm::vec3 color);
        virtual void setTraceColor(glm::vec3 traceColor);

        std::u16string getTextLabelContent();
        glm::vec2 getTextLabelPosition();
        glm::vec3 getColor();
        glm::vec2 getUniformPosition() override;

    protected:
        explicit Button(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, WidgetType type);

        virtual void updateTextPosition(glm::vec2 position, glm::vec2 scale);

        static int IdCounter;

        int id;
        bool _isUnderCursor = false;
        bool _isPressed = false;

        std::function<void()> _pressCallback{[]() {}};
        std::function<void()> _releaseCallback{[]() {}};

        Graphic::PickableForm _form;
        Graphic::Form _tracing;
    };
}    //namespace GraphicLib::Widgets

#endif    //ROLLANDPLAY_BUTTON_HPP
