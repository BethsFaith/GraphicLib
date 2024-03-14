//
// Created by BethsFaith on 14.03.2024.
//

#ifndef GRAPHICLIB_SCROLLBOX_HPP
#define GRAPHICLIB_SCROLLBOX_HPP

#include <algorithm>
#include <ranges>

#include "Layout.hpp"
#include "WidgetBox.hpp"

namespace GraphicLib::Widgets {
    class ScrollBox : public WidgetBox {
    public:
        using Ptr = std::shared_ptr<ScrollBox>;

        ~ScrollBox() override = default;

        virtual bool scrollForward() = 0;
        virtual bool scrollBack() = 0;

        virtual void putWidget(const Widget::Ptr& widget);

        void draw(Shaders::ShaderProgram::Ptr colorShader,
                  Shaders::ShaderProgram::Ptr textureShader,
                  Shaders::ShaderProgram::Ptr textShader,
                  Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;
        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;

        void setScale(glm::vec2 scale) override;
        glm::vec2 getScale() override;

        glm::vec2 getPosition() override;

        void setStartBorder(float startBorder);
        void setEndBorder(float endBorder);
        void setSpeed(float speed);

        [[nodiscard]] float getStartBorder() const;
        [[nodiscard]] float getEndBorder() const;
        [[nodiscard]] float getSpeed() const;
        std::vector<Widget::Ptr> getWidgets() override;

    protected:
        explicit ScrollBox(Layout::Ptr layout);

        [[nodiscard]] const Layout::Ptr& getLayout() const;

    private:
        Layout::Ptr _layout;
        float _startBorder = 0.0f;
        float _endBorder = 0.0f;

        float _speed = 0.01f;
    };
}    //namespace GraphicLib::Widgets

#endif    //GRAPHICLIB_SCROLLBOX_HPP
