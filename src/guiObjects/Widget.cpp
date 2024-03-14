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
}    //namespace Forms
