//
// Created by BethsFaith on 14.03.2024.
//

#include "GraphicLib/GuiObjects/VerticalScrollBox.hpp"

namespace GraphicLib::GuiObjects {
    VerticalScrollBox::VerticalScrollBox() : ScrollBox(std::make_shared<VerticalLayout>()) {}

    void VerticalScrollBox::scroll(double xOffset, double yOffset) {
        auto widgets = getLayout()->getWidgets();
        for (auto& widget : widgets) {
            auto pos = widget->getPosition();
            auto y = pos.y + yOffset * getSpeed();

            widget->setTransform({pos.x, pos.y + yOffset * getSpeed()});
            //            if (y <= _end && y >= _start) {
            //                widget->setTransform({pos.x, pos.y + yOffset * getSpeed()});
            //            } else {
            //                break;
            //            }
        }
    }

    void VerticalScrollBox::setBorders(const glm::vec2& start, const glm::vec2& end) {
        ScrollBox::setBorders(start, end);

        _start = start.y;
        _end = end.y;
    }

    glm::vec2 VerticalScrollBox::getUniformPosition() {
        return glm::vec2();
    }
}    //namespace GraphicLib::GuiObjects
