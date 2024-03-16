//
// Created by VerOchka on 23.10.2023.
//
#include "GraphicLib/GuiObjects/Widget.hpp"

namespace GraphicLib::GuiObjects {
    Widget::Widget(WidgetType type) : _type(type) {}

    void Widget::setCanvas(const Objects::PickableTexture::Ptr& pickableTexture) {
        Widget::canvas = pickableTexture;
    }

    WidgetType Widget::getType() const {
        return _type;
    }

    GuiObjectType Widget::getGuiType() const {
        return WIDGET;
    }

    glm::vec2 Widget::countUniformPosition(glm::vec2 position, glm::vec2 scale) {
        position.x += scale.x/2;
        position.y -= scale.y/2;

        return position;
    }

    glm::vec2 Widget::countOriginalPosition(glm::vec2 position, glm::vec2 scale) {
        position.x -= scale.x/2;
        position.y += scale.y/2;

        return position;
    }
}    //namespace Forms
