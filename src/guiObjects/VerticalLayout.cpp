//
// Created by BethsFaith on 29.01.2024.
//

#include "GraphicLib/GuiObjects/VerticalLayout.hpp"

#include "GraphicLib/GuiObjects/GuiObject.hpp"

namespace GraphicLib::GuiObjects {
    VerticalLayout::VerticalLayout() : Layout(VERTICAL) {}

    void VerticalLayout::beforePuttingGuiObject(GuiObject::Ptr guiObject) {
        glm::vec2 widgetScale;

        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = guiObject->getScale();
        } else {
            widgetScale = elemScale;
            guiObject->setScale(elemScale);
        }

        scale.y += widgetScale.y;
        if (scale.x < widgetScale.x) {
            scale.x = widgetScale.x;
        }

        guiObject->setTransform({position.x, position.y});

        position.y -= widgetOffset + widgetScale.y;
    }

    void VerticalLayout::beforeDeletingGuiObject(GuiObject::Ptr guiObject) {
        auto widgetScale = guiObject->getScale();;

        position.y += widgetOffset + widgetScale.y;
    }

    void VerticalLayout::clear() {
        position.y += (scale.y*2 + widgetOffset * (float)objects.size());

        objects.clear();

        scale = {};
    }
}