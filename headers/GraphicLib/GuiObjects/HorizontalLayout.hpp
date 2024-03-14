//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_HORIZONTALLAYOUT_HPP
#define ROLLANDPLAY_HORIZONTALLAYOUT_HPP

#include "Layout.hpp"

namespace GraphicLib::GuiObjects {
    class HorizontalLayout : public Layout {
    public:
        using Ptr = std::shared_ptr<HorizontalLayout>;

        HorizontalLayout();
        ~HorizontalLayout() = default;

        void putWidget(const Widget::Ptr& widget) override;
        void putLayout(Layout::Ptr layout) override;

        void clear() override;

        glm::vec2 getScale() override;
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_HORIZONTALLAYOUT_HPP
