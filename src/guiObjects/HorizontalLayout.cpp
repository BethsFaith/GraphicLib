//
// Created by BethsFaith on 29.01.2024.
//

#include "GraphicLib/GuiObjects/HorizontalLayout.hpp"

namespace GraphicLib::GuiObjects {
    HorizontalLayout::HorizontalLayout() : Layout(HORIZONTAL) {}

    void HorizontalLayout::putWidget(const Widget::Ptr& widget) {
        glm::vec2 widgetScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = widget->getScale();
        } else {
            widgetScale = elemScale;
            widget->setScale(elemScale);
        }

        //
        //        if (objects.empty()) {
        //            position.x += widgetScale.x/2;
        //        }

        scale.x += widgetScale.x;
        if (scale.y < widgetScale.y) {
            scale.y = widgetScale.y;
        }

        widget->setTransform({position.x, position.y});

        position.x += widgetScale.x + widgetOffset;

        objects.push_back(widget);
    }

    void HorizontalLayout::putLayout(Layout::Ptr layout) {
        glm::vec2 widgetScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = layout->getScale();
        } else {
            widgetScale = elemScale;
            layout->setScale(elemScale);
        }

        scale.x += widgetScale.x;
        if (scale.y < widgetScale.y) {
            scale.y = widgetScale.y;
        }

        layout->setTransform({position.x, position.y});

        position.x += widgetScale.x + widgetOffset;

        objects.push_back(layout);
    }

    void HorizontalLayout::putWidgetBox(const WidgetBox::Ptr& widgetBox) {
        glm::vec2 widgetScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = widgetBox->getScale();
        } else {
            widgetScale = elemScale;
            widgetBox->setScale(elemScale);
        }

        position.x += widgetScale.x + widgetOffset;
        scale.x += widgetScale.x;
        if (scale.y < widgetScale.y) {
            scale.y = widgetScale.y;
        }

        widgetBox->setTransform({position.x, position.y});

        objects.push_back(widgetBox);
    }

    void HorizontalLayout::clear() {
        position.x -= (scale.x*2 + widgetOffset * (float)objects.size());

        objects.clear();

        scale = {};
    }

    glm::vec2 HorizontalLayout::getScale() {
        return {scale.x, scale.y};
    }
}    //namespace Widgets
