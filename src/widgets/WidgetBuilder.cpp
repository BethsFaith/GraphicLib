//
// Created by BethsFaith on 01.02.2024.
//

#include "GraphicLib/Widgets/WidgetBuilder.hpp"

namespace GraphicLib::Widgets {
    void WidgetBuilder::addWidgetStyle(WidgetType type, const Styles::WidgetStyle::Ptr& style) {
        addWidgetStyle(type, DEFAULT_STYLE, style);
    }

    void WidgetBuilder::addWidgetStyle(WidgetType type, std::string styleClass, const Styles::WidgetStyle::Ptr& style) {
        styles[std::to_string(type)+styleClass] = style;
    }

    Widget::Ptr WidgetBuilder::createWidget(WidgetType type) {
        return createWidget(type, DEFAULT_STYLE);
    }

    Widget::Ptr WidgetBuilder::createWidget(WidgetType type, std::string styleClass) {
        return WidgetFactory::create(type, styles[std::to_string(type)+styleClass]);
    }

    void WidgetBuilder::addLayoutStyle(LayoutType type, const Styles::LayoutStyle::Ptr& style) {
        layoutStyles[type] = style;
    }

    Layout::Ptr WidgetBuilder::createLayout(LayoutType type) {
        return WidgetFactory::create(type, layoutStyles[type]);
    }
}
