//
// Created by BethsFaith on 14.03.2024.
//

#ifndef GRAPHICLIB_VERTICALSCROLLBOX_HPP
#define GRAPHICLIB_VERTICALSCROLLBOX_HPP

#include "ScrollBox.hpp"
#include "VerticalLayout.hpp"

namespace GraphicLib::Widgets {
    class VerticalScrollBox : public ScrollBox {
    public:
        using Ptr = std::shared_ptr<VerticalScrollBox>;

        VerticalScrollBox();
        ~VerticalScrollBox() override = default;

        bool scrollForward() override;
        bool scrollBack() override;
    };
}    //namespace Widgets

#endif    //GRAPHICLIB_VERTICALSCROLLBOX_HPP
