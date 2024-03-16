//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_VERTICALLAYOUT_HPP
#define ROLLANDPLAY_VERTICALLAYOUT_HPP

#include "Layout.hpp"

namespace GraphicLib::GuiObjects {
    class VerticalLayout : public Layout {
    public:
        using Ptr = std::shared_ptr<VerticalLayout>;

        explicit VerticalLayout();
        ~VerticalLayout() = default;

        void clear() override;

    protected:
        void beforePuttingGuiObject(GuiObject::Ptr guiObject) override;
        void beforeDeletingGuiObject(GuiObject::Ptr guiObject) override;
    };
}
#endif    //ROLLANDPLAY_VERTICALLAYOUT_HPP
