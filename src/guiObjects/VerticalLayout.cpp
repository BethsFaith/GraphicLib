//
// Created by BethsFaith on 29.01.2024.
//

#include "GraphicLib/GuiObjects/VerticalLayout.hpp"

#include "GraphicLib/GuiObjects/GuiObject.hpp"

namespace GraphicLib::GuiObjects {
    VerticalLayout::VerticalLayout() : Layout(VERTICAL) {}

    void VerticalLayout::putWidget(const Widget::Ptr& widget) {
        glm::vec2 widgetScale;

        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            widgetScale = widget->getScale();
        } else {
            widgetScale = elemScale;
            widget->setScale(elemScale);
        }

        //        if (objects.empty()) {
        //            position.y -= widgetScale.y/2;
        //        }

        scale.y += widgetScale.y;
        if (scale.x < widgetScale.x) {
            scale.x = widgetScale.x;
        }

        widget->setTransform({position.x, position.y});

        position.y -= widgetOffset + widgetScale.y;

        objects.push_back(widget);
    }

    void VerticalLayout::putLayout(Layout::Ptr layout) {
        glm::vec2 layoutScale;

        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            layoutScale = layout->getScale();
        } else {
            layoutScale = elemScale;
            layout->setScale(elemScale);
        }

        //        if (objects.empty()) {
        //            position.y -= layoutScale.y/2;
        //        }

        scale.y += layoutScale.y;
        if (scale.x < layoutScale.x) {
            scale.x = layoutScale.x;
        }

        layout->setTransform({position.x, position.y});

        position.y -= widgetOffset + layoutScale.y;

        objects.push_back(layout);
    }

    void VerticalLayout::putWidgetBox(const WidgetBox::Ptr& widgetBox) {
        glm::vec2 layoutScale;
        if (elemScale.x == 0.0f && elemScale.y == 0.0f) {
            layoutScale = widgetBox->getScale();
        } else {
            layoutScale = elemScale;
            widgetBox->setScale(elemScale);
        }

        if (!objects.empty()) {
            position.y -= layoutScale.y/2;
        }

        scale.y += layoutScale.y;
        if (scale.x < layoutScale.x) {
            scale.x = layoutScale.x;
        }

        widgetBox->setTransform({position.x + layoutScale.x/2, position.y - layoutScale.y/2});

        position.y -= widgetOffset + layoutScale.y;

        objects.push_back(widgetBox);
    }

    void VerticalLayout::clear() {
        position.y += (scale.y*2 + widgetOffset * (float)objects.size());

        objects.clear();

        scale = {};
    }
}