//
// Created by BethsFaith on 31.01.2024.
//

#ifndef ROLLANDPLAY_BUTTONSTYLE_HPP
#define ROLLANDPLAY_BUTTONSTYLE_HPP

#include "GraphicLib/Objects/Primitives/AbstractPrimitive.hpp"

#include "WidgetStyle.hpp"
#include "TextParams.hpp"

namespace GraphicLib::Widgets::Styles {
    struct ButtonStyle : public WidgetStyle {
        using Ptr = std::shared_ptr<ButtonStyle>;

        ButtonStyle() = default;
        ~ButtonStyle() override = default;

        Objects::Primitives::AbstractPrimitive::Ptr figure;

        TextParams labelParams;

        glm::vec3 color{};
        glm::vec3 traceColor{};
        glm::vec3 pressColor{};
    };
}    //namespace widgets

#endif    //ROLLANDPLAY_BUTTONSTYLE_HPP
