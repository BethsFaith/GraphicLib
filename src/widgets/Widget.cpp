//
// Created by VerOchka on 23.10.2023.
//
#include "GraphicLib/Widgets/Widget.hpp"

namespace GraphicLib::Widgets {
    Widget::Widget(WidgetType type) : _type(type) {}

    void Widget::setCanvas(const Objects::PickableTexture::Ptr& pickableTexture) {
        Widget::canvas = pickableTexture;
    }

    WidgetType Widget::getType() const {
        return _type;
    }
}    //namespace Forms
