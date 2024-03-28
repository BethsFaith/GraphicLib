//
// Created by BethsFaith on 14.03.2024.
//

#include "GraphicLib/GuiObjects/VerticalScrollBox.hpp"

namespace GraphicLib::GuiObjects {
    VerticalScrollBox::VerticalScrollBox() : ScrollBox(std::make_shared<VerticalLayout>()) {}

    void VerticalScrollBox::scroll(double xOffset, double yOffset) {
        auto widgets = getLayout()->getWidgets();
        auto offset = (-1 * yOffset * getSpeed());

        if (offset > 0) {
            auto it = widgets.end()-1;
            auto pos = (*it)->getPosition();
            pos.y += offset;
            if (pos.y > _end) {
                return;
            } else {
                (*it)->setTransform(pos);
                do {
                    --it;

                    pos = (*it)->getPosition();
                    pos.y += offset;

                    (*it)->setTransform(pos);

                } while (it != widgets.begin());
            }
        } else {
            auto it = widgets.begin();
            auto pos = (*it)->getPosition();
            pos.y += offset;

            if (pos.y < _start) {
                return;
            } else {
                (*it)->setTransform(pos);

                ++it;

                while (it != widgets.end()) {
                    pos = (*it)->getPosition();
                    pos.y += offset;

                    (*it)->setTransform(pos);

                    ++it;
                }
            }
        }
//        for (auto& widget : widgets) {
//            auto pos = widget->getPosition();
//
//            widget->setTransform({pos.x, pos.y + offset});
//            //            if (y <= _end && y >= _start) {
//            //                widget->setTransform({pos.x, pos.y + yOffset * getSpeed()});
//            //            } else {
//            //                break;
//            //            }
//        }
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
