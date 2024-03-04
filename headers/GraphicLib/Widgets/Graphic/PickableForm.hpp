//
// Created by BethsFaith on 28.01.2024.
//

#ifndef ROLLANDPLAY_PICKABLEFORM_HPP
#define ROLLANDPLAY_PICKABLEFORM_HPP

#include "Form.hpp"

namespace GraphicLib::Widgets::Graphic {
    class PickableForm : public Form {
    public:
        using Ptr = std::shared_ptr<PickableForm>;

        PickableForm(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, float identifier);

        void renderPick(Objects::Shaders::ShaderProgram::Ptr shader, const Objects::PickableTexture::Ptr& canvas);
    };
}

#endif    //ROLLANDPLAY_PICKABLEFORM_HPP
