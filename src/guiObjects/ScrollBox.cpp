//
// Created by BethsFaith on 14.03.2024.
//

#include "GraphicLib/GuiObjects/ScrollBox.hpp"

#include <utility>

namespace GraphicLib::GuiObjects {
    GuiObjects::ScrollBox::ScrollBox(Layout::Ptr layout) : WidgetBox(SCROLL_BOX), _layout(std::move(layout)) {}

    void ScrollBox::putGuiObject(GuiObject::Ptr object) {
        _layout->putGuiObject(std::move(object));
    }

    bool ScrollBox::checkSelecting(unsigned int x, unsigned int y) {
        return x >= _xMinPos && x <= _xMaxPos && y >= _yMinPos && y <= _yMaxPos;
    }

    void ScrollBox::draw(Shaders::ShaderProgram::Ptr colorShader,
                         Shaders::ShaderProgram::Ptr textureShader,
                         Shaders::ShaderProgram::Ptr textShader,
                         Shaders::ShaderProgram::Ptr pickShader) {
        glScissor(_xMinPos, _yMinPos, _width, _height);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_SCISSOR_TEST);

        glClearColor(_backgroundColor.x, _backgroundColor.y, _backgroundColor.z, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        auto widgets = _layout->getWidgets();
        for (auto& widget : widgets) {
            widget->draw(colorShader, textureShader, textShader, pickShader);
        }

        glDisable(GL_SCISSOR_TEST);
        glDisable(GL_DEPTH_TEST);
    }

    void ScrollBox::setTransform(glm::vec2 position, glm::vec2 scale) {
        _layout->setTransform(position, scale);
    }

    void ScrollBox::setTransform(glm::vec2 position) {
        _layout->setTransform(position);
    }

    void ScrollBox::setScale(glm::vec2 scale) {
        _layout->setScale(scale);
    }

    glm::vec2 ScrollBox::getScale() {
        return _layout->getScale();
    }

    glm::vec2 ScrollBox::getPosition() {
        return _layout->getPosition();
    }

    void ScrollBox::setSpeed(float speed) {
        _speed = speed;
    }

    float ScrollBox::getSpeed() const {
        return _speed;
    }

    const Layout::Ptr& ScrollBox::getLayout() const {
        return _layout;
    }

    std::vector<Widget::Ptr> ScrollBox::getWidgets() {
        return _layout->getWidgets();
    }

    void ScrollBox::setCanvas(const Objects::PickableTexture::Ptr& pickableTexture) {
        for (const auto& widget : _layout->getWidgets()) {
            widget->setCanvas(pickableTexture);
        }
    }

    void ScrollBox::setBorders(const glm::vec2& start, const glm::vec2& end) {
        auto w = (float)windowWidth / 2;
        auto h = (float)windowHeight / 2;

        _xMaxPos = int(w * (1 + end.x));
        _xMinPos = int(w * (1 + start.x));
        _width = _xMaxPos - _xMinPos;

        _yMaxPos = (int)(h * (1 + end.y));
        _yMinPos = int(h * (1 + start.y));
        _height = _yMaxPos - _yMinPos;
    }

    void ScrollBox::setBackgroundColor(const glm::vec3& backgroundColor) {
        _backgroundColor = backgroundColor;
    }
}    //namespace GraphicLib::GuiObjects
