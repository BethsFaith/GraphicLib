//
// Created by BethsFaith on 14.03.2024.
//

#include "GraphicLib/Widgets/ScrollBox.hpp"

namespace GraphicLib::Widgets {
    Widgets::ScrollBox::ScrollBox(Layout::Ptr  layout) : WidgetBox(SCROLL_BOX), _layout(std::move(layout)) {}

    bool ScrollBox::checkSelecting(unsigned int x, unsigned int y) {
        auto widgets = _layout->getWidgets();

        return std::ranges::any_of(widgets, [=](const Widget::Ptr& widget){
            return widget->checkSelecting(x, y);
        });
    }

    void ScrollBox::draw(Shaders::ShaderProgram::Ptr colorShader,
                         Shaders::ShaderProgram::Ptr textureShader,
                         Shaders::ShaderProgram::Ptr textShader,
                         Shaders::ShaderProgram::Ptr pickShader) {
        auto widgets = _layout->getWidgets();
        for (auto& widget : widgets) {
            widget->draw(colorShader, textureShader, textShader, pickShader);
        }
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

    void ScrollBox::putWidget(const Widget::Ptr& widget) {
        _layout->putWidget(widget);
    }

    void ScrollBox::putLayout(const Layout::Ptr& layout) {
        _layout->putLayout(layout);
    }

    void ScrollBox::setStartBorder(float startBorder) {
        _startBorder = startBorder;
    }

    void ScrollBox::setEndBorder(float endBorder) {
        _endBorder = endBorder;
    }

    void ScrollBox::setSpeed(float speed) {
        _speed = speed;
    }

    float ScrollBox::getStartBorder() const {
        return _startBorder;
    }

    float ScrollBox::getEndBorder() const {
        return _endBorder;
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
}