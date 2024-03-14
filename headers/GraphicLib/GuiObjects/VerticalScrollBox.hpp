//
// Created by BethsFaith on 14.03.2024.
//

#ifndef GRAPHICLIB_VERTICALSCROLLBOX_HPP
#define GRAPHICLIB_VERTICALSCROLLBOX_HPP

#include "ScrollBox.hpp"
#include "VerticalLayout.hpp"

namespace GraphicLib::GuiObjects {
    class VerticalScrollBox : public ScrollBox {
    public:
        using Ptr = std::shared_ptr<VerticalScrollBox>;

        VerticalScrollBox();
        ~VerticalScrollBox() override = default;

        void scroll(double xOffset, double yOffset) override;

        void setBorders(const glm::vec2& start, const glm::vec2& end) override;

    private:
        float _start{};
        float _end{};
    };
}    //namespace Widgets

#endif    //GRAPHICLIB_VERTICALSCROLLBOX_HPP
