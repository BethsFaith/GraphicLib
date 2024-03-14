//
// Created by BethsFaith on 15.03.2024.
//

#ifndef GRAPHICLIB_SCROLLBOXSTYLE_HPP
#define GRAPHICLIB_SCROLLBOXSTYLE_HPP

#include "GraphicLib/Objects/Primitives/Rectangle.hpp"

#include "WidgetStyle.hpp"

namespace GraphicLib::GuiObjects::Styles {
    struct ScrollBoxStyle : public WidgetStyle {
        using Ptr = std::shared_ptr<ScrollBoxStyle>;

        ScrollBoxStyle() = default;
        ~ScrollBoxStyle() override = default;

        glm::vec3 backgroundColor{};
        float speed{};
    };
}

#endif    //GRAPHICLIB_SCROLLBOXSTYLE_HPP
