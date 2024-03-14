//
// Created by BethsFaith on 14.03.2024.
//

#ifndef GRAPHICLIB_SCROLLBOX_HPP
#define GRAPHICLIB_SCROLLBOX_HPP

#include <algorithm>
#include <ranges>

#include "Layout.hpp"
#include "WidgetBox.hpp"

namespace GraphicLib::GuiObjects {
    class ScrollBox : public WidgetBox {
    public:
        using Ptr = std::shared_ptr<ScrollBox>;

        ~ScrollBox() override = default;

        virtual void scroll(double xOffset, double yOffset) = 0;

        virtual void putGuiObject(GuiObject::Ptr object);

        virtual void setBorders(const glm::vec2& start, const glm::vec2& end);

        void draw(Shaders::ShaderProgram::Ptr colorShader,
                  Shaders::ShaderProgram::Ptr textureShader,
                  Shaders::ShaderProgram::Ptr textShader,
                  Shaders::ShaderProgram::Ptr pickShader) override;

        bool checkSelecting(unsigned int x, unsigned int y) override;
        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 scale) override;

        void setCanvas(const Objects::PickableTexture::Ptr& pickableTexture) override;
        glm::vec2 getScale() override;
        glm::vec2 getPosition() override;

        std::vector<Widget::Ptr> getWidgets() override;
        void setBackgroundColor(const glm::vec3& backgroundColor);
        void setSpeed(float speed);

        static inline int windowWidth{};

        static inline int windowHeight{};

    protected:
        explicit ScrollBox(Layout::Ptr layout);

        [[nodiscard]] const Layout::Ptr& getLayout() const;
        [[nodiscard]] float getSpeed() const;

    private:
        Layout::Ptr _layout;

        int _xMinPos{};
        int _xMaxPos{};
        int _yMinPos{};
        int _yMaxPos{};
        int _width{};
        int _height{};

        float _speed = 0.01f;

        glm::vec3 _backgroundColor{};
    };
}    //namespace GraphicLib::GuiObjects

#endif    //GRAPHICLIB_SCROLLBOX_HPP
