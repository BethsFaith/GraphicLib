//
// Created by BethsFaith on 14.03.2024.
//

#include "GraphicLib/Widgets/VerticalScrollBox.hpp"

namespace GraphicLib::Widgets {
    VerticalScrollBox::VerticalScrollBox() : ScrollBox(std::make_shared<VerticalLayout>()){}

    bool VerticalScrollBox::scrollForward() {
        auto pos = getPosition();
        setTransform({pos.x, pos.y-getSpeed()});

        return true;
    }

    bool VerticalScrollBox::scrollBack() {
        auto pos = getPosition();
        setTransform({pos.x, pos.y+getSpeed()});

        return false;
    }
}