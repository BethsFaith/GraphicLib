//
// Created by BethsFaith on 08.02.2024.
//

#include "GraphicLib/GuiObjects/ImageBox.hpp"

namespace GraphicLib::GuiObjects {
    ImageBox::ImageBox(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive) : Widget(IMAGE_BOX),
          _form(graphicPrimitive) {}

    bool ImageBox::checkSelecting(unsigned int x, unsigned int y) {
        return false;
    }

    void ImageBox::draw(Shaders::ShaderProgram::Ptr colorShader,
                        Shaders::ShaderProgram::Ptr textureShader,
                        Shaders::ShaderProgram::Ptr textShader,
                        Shaders::ShaderProgram::Ptr pickShader) {
        _form.renderForm(textureShader);
        _form.renderText(textShader);
    }

    void ImageBox::setTransform(glm::vec2 position, glm::vec2 scale) {
        if (!_form.getText().empty()) {
            scale.y += 0.03;
        }

        position = countUniformPosition(position, scale);

        _form.setTransform(position, scale);
        _form.setTextPosition({position.x - scale.x / 2 + 0.01f, position.y + scale.y * 0.7});
    }

    void ImageBox::setTransform(glm::vec2 position) {
        auto scale = getScale();

        position = countUniformPosition(position, scale);

        _form.setTransform(position);
        _form.setTextPosition({position.x - scale.x / 2 + 0.01f, position.y + scale.y * 0.7});
    }

    void ImageBox::setScale(glm::vec2 scale) {
        _form.setScale(scale);
    }

    void ImageBox::setImage(const std::string& texturePath, int textureIndex) {
        _texture = std::make_shared<Objects::Textures::Texture>("", texturePath);
        Objects::Textures::load2d(*_texture,
                                  {{.name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST},
                                   {.name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST},
                                   {.name = GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE},
                                   {.name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE},
                                   {.name = GL_TEXTURE_WRAP_R, .value = GL_CLAMP_TO_EDGE}});
        _texture->setPath(texturePath);

        _form.setTexture(_texture, textureIndex);
    }

    glm::vec2 ImageBox::getScale() {
        return _form.getScale();
    }

    glm::vec2 ImageBox::getPosition() {
        return countOriginalPosition(_form.getPosition(), _form.getScale());
    }

    const Objects::Textures::Texture::Ptr& ImageBox::getTexture() const {
        return _texture;
    }

    void ImageBox::setLabelParams(const Styles::TextParams& text) {
        _form.setTextColor(text.color);
        _form.setTextPosition(text.position);
        _form.setTextSize(text.size);
    }

    void ImageBox::setLabelText(const std::u16string& text) {\
        _form.setText(text);
    }

    void ImageBox::setLabelPosition(glm::vec2 position) {
        _form.setTextPosition(position);
    }

    void ImageBox::setLabelColor(glm::vec3 color) {
        _form.setTextColor(color);
    }

    void ImageBox::setLabelTextSize(float size) {
        _form.setTextSize(size);
    }

    glm::vec2 ImageBox::countUniformPosition(glm::vec2 position, glm::vec2 scale) {
        auto pos = Widget::countUniformPosition(position, scale);

        if (!_form.getText().empty()) {
            pos.y = pos.y - scale.y * 0.7;
        }

        return pos;
    }

    glm::vec2 ImageBox::countOriginalPosition(glm::vec2 position, glm::vec2 scale) {
        auto pos = Widget::countOriginalPosition(position, scale);

        if (!_form.getText().empty()) {
            pos.y = pos.y + scale.y * 0.7;
        }

        return pos;
    }
}    //namespace Widgets
