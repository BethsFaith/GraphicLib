//
// Created by BethsFaith on 28.01.2024.
//

#include "GraphicLib/Widgets/Graphic/PickableForm.hpp"

namespace GraphicLib::Widgets::Graphic {

    PickableForm::PickableForm(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive,
                               float identifier) : Form(graphicPrimitive) {

        auto picking = std::make_shared<Objects::Techniques::PickTechnique>();

        picking->setObjectId(identifier);

        _object.addTechnique(Objects::Techniques::PICK, picking);
        _object.disableTechnique(Objects::Techniques::PICK);
    }

    void PickableForm::renderPick(Objects::Shaders::ShaderProgram::Ptr shader,
                                  const Objects::PickableTexture::Ptr& canvas) {
        canvas->enableWriting();

        _object.enableTechnique(Objects::Techniques::PICK);
        _object.enableTechnique(Objects::Techniques::TRANSFORM);

        _object.render(std::move(shader));

        canvas->disableWriting();

        _object.disableTechnique(Objects::Techniques::PICK);
        _object.disableTechnique(Objects::Techniques::TRANSFORM);
    }
}