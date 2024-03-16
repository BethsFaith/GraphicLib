//
// Created by VerOchka on 26.10.2023.
//

#include "GraphicLib/GuiObjects/ImageButton.hpp"

namespace GraphicLib::GuiObjects {
    ImageButton::ImageButton(Objects::Primitives::AbstractPrimitive::Ptr graphicPrimitive)
        : Button(graphicPrimitive, WidgetType::IMAGE_BUTTON) {}

    void ImageButton::setImage(const std::string& texturePath, int textureIndex) {
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

    void ImageButton::setDefaultImage(const std::string& texturePath, int textureIndex) {
        _defaultTexture = std::make_shared<Objects::Textures::Texture>("", texturePath);
        Objects::Textures::load2d(*_defaultTexture,
                                  {{.name = GL_TEXTURE_MIN_FILTER, .value = GL_NEAREST},
                                   {.name = GL_TEXTURE_MAG_FILTER, .value = GL_NEAREST},
                                   {.name = GL_TEXTURE_WRAP_S, .value = GL_CLAMP_TO_EDGE},
                                   {.name = GL_TEXTURE_WRAP_T, .value = GL_CLAMP_TO_EDGE},
                                   {.name = GL_TEXTURE_WRAP_R, .value = GL_CLAMP_TO_EDGE}});
        _defaultTexture->setPath(texturePath);

        if (_texture == nullptr) {
            _form.setTexture(_defaultTexture, textureIndex);
        }
    }

    void ImageButton::draw(Shaders::ShaderProgram::Ptr colorShader,
                           Shaders::ShaderProgram::Ptr textureShader,
                           Shaders::ShaderProgram::Ptr textShader,
                           Shaders::ShaderProgram::Ptr pickShader) {
        Button::draw(textureShader, textureShader, textShader, pickShader);
    }

    void ImageButton::updateTextPosition(glm::vec2 position, glm::vec2 scale) {
        _form.setTextPosition({position.x - scale.x / 2 + 0.01f, position.y + scale.y * 0.7});
    }

    void ImageButton::setColor(glm::vec3 color) {}

    const Objects::Textures::Texture::Ptr& ImageButton::getTexture() const {
        return _texture;
    }

    glm::vec2 ImageButton::getScale() {
        auto scale = Button::getScale();
        if (!_form.getText().empty()) {
            scale.y *= 1.3f;
        }
        return scale;
    }

    void ImageButton::resetImage(int defaultTextureIndex) {
        _texture.reset();

        _form.setTexture(_defaultTexture, defaultTextureIndex);
    }

    glm::vec2 ImageButton::countUniformPosition(glm::vec2 position, glm::vec2 scale) {
        auto pos = Widget::countUniformPosition(position, scale);

        if (!_form.getText().empty()) {
            pos.y = pos.y - scale.y * 0.3;
        }

        return pos;
    }

    glm::vec2 ImageButton::countOriginalPosition(glm::vec2 position, glm::vec2 scale) {
        auto pos = Widget::countOriginalPosition(position, scale);

        if (!_form.getText().empty()) {
            pos.y = pos.y + scale.y * 0.3;
        }

        return pos;
    }
}    //namespace Forms
