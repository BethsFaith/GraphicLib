//
// Created by VerOchka on 06.01.2024.
//

#include "GraphicLib/GuiObjects/TextBox.hpp"

namespace GraphicLib::GuiObjects {
    TextBox::TextBox() : Widget(WidgetType::TEXT_BOX) {
        Objects::Primitives::AbstractPrimitive::Ptr rectangle =
            std::make_shared<Objects::Primitives::Rectangle>(
                Objects::Primitives::Primitive::Settings{.with_normals = false,
                                                         .with_texture_coords = false,
                                                         .with_tangent = false,
                                                         .with_bitangent = false});
        rectangle->bindData(GL_STATIC_DRAW);

        _form = std::make_unique<Graphic::Form>(rectangle);
    }

    void TextBox::setTransform(glm::vec2 position, glm::vec2 scale) {
        position = countUniformPosition(position, scale);

        _form->setTransform(position, scale);
        _form->setTextPosition({position.x - scale.x / 2.0f + 0.01f, position.y});
    }

    void TextBox::setTransform(glm::vec2 position) {
        position = countUniformPosition(position, getScale());

        _form->setTransform(position);
        _form->setTextPosition({position.x - _form->getScale().x / 2.0f + 0.01f, position.y});
    }

    void TextBox::setScale(glm::vec2 scale) {
        _form->setScale(scale);

        auto position = _form->getPosition();
        _form->setTextPosition({position.x - _form->getScale().x / 2.0f + 0.01f, position.y});
    }

    void TextBox::setColor(glm::vec3 color) {
        _form->setColor(color);
    }

    void TextBox::setTextParams(const Styles::TextParams& text) {
        _form->setTextColor(text.color);
        _form->setTextSize(text.size);
    }

    void TextBox::setTextColor(glm::vec3 color) {
        _form->setTextColor(color);
    }

    void TextBox::setText(const std::u16string& content) {
        _form->setText(content);
    }

    void TextBox::setTextSize(float size) {
        _form->setTextSize(size);
    }

    void TextBox::draw(Shaders::ShaderProgram::Ptr colorShader,
                       Shaders::ShaderProgram::Ptr textureShader,
                       Shaders::ShaderProgram::Ptr textShader,
                       Shaders::ShaderProgram::Ptr pickShader) {
        _form->renderForm(colorShader);
        _form->renderText(textShader);
    }

    bool TextBox::checkSelecting(unsigned int x, unsigned int y) {
        return false;
    }

    void TextBox::clear() {
        setText(u"");
    }

    glm::vec2 TextBox::getScale() {
        return _form->getScale();
    }

    glm::vec2 TextBox::getPosition() {
        return countOriginalPosition(_form->getPosition(), _form->getScale());
    }
}