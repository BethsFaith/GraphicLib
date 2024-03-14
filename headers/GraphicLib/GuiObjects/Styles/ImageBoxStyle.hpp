//
// Created by BethsFaith on 12.02.2024.
//

#ifndef INC_1_BIN_IMAGEBOXSTYLE_HPP
#define INC_1_BIN_IMAGEBOXSTYLE_HPP

#include "GraphicLib/Objects/Primitives/AbstractPrimitive.hpp"

#include "WidgetStyle.hpp"
#include "TextParams.hpp"

namespace GraphicLib::GuiObjects::Styles {
    struct ImageBoxStyle : public WidgetStyle {
        using Ptr = std::shared_ptr<ImageBoxStyle>;

        ImageBoxStyle() = default;
        ~ImageBoxStyle() override = default;

        TextParams labelParams;

        Objects::Primitives::AbstractPrimitive::Ptr figure;

        std::string defaultTexturePath;
        int defaultTextureIndex = 0;
    };
}

#endif    //INC_1_BIN_IMAGEBOXSTYLE_HPP
