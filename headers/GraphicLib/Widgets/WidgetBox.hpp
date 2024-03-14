//
// Created by BethsFaith on 14.03.2024.
//

#ifndef GRAPHICLIB_WIDGETBOX_HPP
#define GRAPHICLIB_WIDGETBOX_HPP

#include "Widget.hpp"

namespace GraphicLib::Widgets {
    class WidgetBox : public Widget {
    public:
        explicit WidgetBox(WidgetType type);

        virtual std::vector<Widget::Ptr> getWidgets() = 0;
    };
}

#endif    //GRAPHICLIB_WIDGETBOX_HPP
