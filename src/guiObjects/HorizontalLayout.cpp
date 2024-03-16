//
// Created by BethsFaith on 29.01.2024.
//

#include "GraphicLib/GuiObjects/HorizontalLayout.hpp"

namespace GraphicLib::GuiObjects {
    HorizontalLayout::HorizontalLayout() : Layout(HORIZONTAL) {}

    void HorizontalLayout::beforePuttingGuiObject(GuiObject::Ptr guiObject) {
        glm::vec2 widgetScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = guiObject->getScale();
        } else {
            widgetScale = elemScale;
            guiObject->setScale(elemScale);
        }

        scale.x += widgetScale.x;
        if (scale.y < widgetScale.y) {
            scale.y = widgetScale.y;
        }

        guiObject->setTransform({position.x, position.y});

        position.x += widgetScale.x + widgetOffset;
    }

    void HorizontalLayout::beforeDeletingGuiObject(GuiObject::Ptr guiObject) {}

    void HorizontalLayout::clear() {
        position.x -= (scale.x*2 + widgetOffset * (float)objects.size());

        objects.clear();

        scale = {};
    }

    glm::vec2 HorizontalLayout::getScale() {
        return {scale.x + widgetOffset, scale.y};
    }
}    //namespace Widgets
