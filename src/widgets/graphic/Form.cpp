//
// Created by BethsFaith on 28.01.2024.
//

#include "GraphicLib/Widgets/Graphic/Form.hpp"

namespace GraphicLib::Widgets::Graphic {
    Form::Form(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive) {
        _object.setPrimitive(graphicPrimitive);
    }

    void Form::setTransform(glm::vec2 position) {
        auto technique =  _object.getTechnique(Objects::Techniques::TRANSFORM);
        Objects::Techniques::TransformTechnique::Ptr transformTechnique;
        if (technique == nullptr) {
            transformTechnique = std::make_shared<Objects::Techniques::TransformTechnique>();
            transformTechnique->enableTransform({position, -0.1f});

            _object.addTechnique(Objects::Techniques::TRANSFORM, transformTechnique);
            _object.disableTechnique(Objects::Techniques::TRANSFORM);
        } else {
            transformTechnique = std::dynamic_pointer_cast<Objects::Techniques::TransformTechnique>(technique);
            transformTechnique->enableTransform({position, -0.1f});
        }
    }

    void Form::setTransform(glm::vec2 position, glm::vec2 scale) {
        auto technique =  _object.getTechnique(Objects::Techniques::TRANSFORM);
        Objects::Techniques::TransformTechnique::Ptr transformTechnique;
        if (technique == nullptr) {
            transformTechnique = std::make_shared<Objects::Techniques::TransformTechnique>();
            transformTechnique->enableScale({scale, 0.0f});
            transformTechnique->enableTransform({position, -0.1f});

            _object.addTechnique(Objects::Techniques::TRANSFORM, transformTechnique);
            _object.disableTechnique(Objects::Techniques::TRANSFORM);
        } else {
            transformTechnique = std::dynamic_pointer_cast<Objects::Techniques::TransformTechnique>(technique);
            transformTechnique->enableScale({scale, 0.0f});
            transformTechnique->enableTransform({position, -0.1f});
        }
    }

    void Form::setScale(glm::vec2 scale) {
        auto technique =  _object.getTechnique(Objects::Techniques::TRANSFORM);
        Objects::Techniques::TransformTechnique::Ptr transformTechnique;
        if (technique == nullptr) {
            transformTechnique = std::make_shared<Objects::Techniques::TransformTechnique>();
            transformTechnique->enableScale({scale, 0.0f});

            _object.addTechnique(Objects::Techniques::TRANSFORM, transformTechnique);
            _object.disableTechnique(Objects::Techniques::TRANSFORM);
        } else {
            transformTechnique = std::dynamic_pointer_cast<Objects::Techniques::TransformTechnique>(technique);
            transformTechnique->enableScale({scale, 0.0f});
        }
    }

    void Form::setTextPosition(glm::vec2 position) {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        Objects::Techniques::TextTechnique::Ptr textTechnique;

        if (technique == nullptr) {
            textTechnique = std::make_shared<Objects::Techniques::TextTechnique>();
            _object.addTechnique(Objects::Techniques::TEXT, textTechnique);
            _object.disableTechnique(Objects::Techniques::TEXT);
        } else {
            textTechnique = std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique);
        }

        textTechnique->setWidth(position.x);
        textTechnique->setHeight(position.y);
    }

    void Form::setTextSize(float scale) {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        Objects::Techniques::TextTechnique::Ptr textTechnique;

        if (technique == nullptr) {
            textTechnique = std::make_shared<Objects::Techniques::TextTechnique>();
            _object.addTechnique(Objects::Techniques::TEXT, textTechnique);
            _object.disableTechnique(Objects::Techniques::TEXT);
        } else {
            textTechnique = std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique);
        }
        textTechnique->setScale(scale);
    }

    void Form::setText(std::u16string content) {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        Objects::Techniques::TextTechnique::Ptr textTechnique;
        if (technique == nullptr) {
            textTechnique = std::make_shared<Objects::Techniques::TextTechnique>();
            _object.addTechnique(Objects::Techniques::TEXT, textTechnique);
            _object.disableTechnique(Objects::Techniques::TEXT);
        } else {
            textTechnique = std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique);
        }
        textTechnique->setText(content);
    }

    void Form::setText(std::u16string content, glm::vec3 color) {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        Objects::Techniques::TextTechnique::Ptr textTechnique;
        if (technique == nullptr) {
            textTechnique = std::make_shared<Objects::Techniques::TextTechnique>();
            _object.addTechnique(Objects::Techniques::TEXT, textTechnique);
            _object.disableTechnique(Objects::Techniques::TEXT);
        } else {
            textTechnique = std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique);
        }
        textTechnique->setText(content);
        textTechnique->setColor(color);
    }

    void Form::setTextColor(glm::vec3 color) {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        Objects::Techniques::TextTechnique::Ptr textTechnique;
        if (technique == nullptr) {
            textTechnique = std::make_shared<Objects::Techniques::TextTechnique>();
            _object.addTechnique(Objects::Techniques::TEXT, textTechnique);
            _object.disableTechnique(Objects::Techniques::TEXT);
        } else {
            textTechnique = std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique);
        }
        textTechnique->setColor(color);
    }

    void Form::setColor(glm::vec3 color) {
        auto technique =  _object.getTechnique(Objects::Techniques::COLOR);
        if (technique == nullptr) {
            auto colorTechnique = std::make_shared<Objects::Techniques::ColorTechnique>();
            colorTechnique->setColor(color);

            _object.addTechnique(Objects::Techniques::COLOR, colorTechnique);
            _object.disableTechnique(Objects::Techniques::COLOR);
        } else {
            auto colorTechnique = std::dynamic_pointer_cast<Objects::Techniques::ColorTechnique>(technique);
            colorTechnique->setColor(color);
        }
    }

    void Form::setTexture(Objects::Textures::Texture::Ptr texture, int textureIndex) {
        auto technique =  _object.getTechnique(Objects::Techniques::TEXTURE);
        Objects::Techniques::TextureTechnique::Ptr textureTechnique;
        if (technique == nullptr) {
            textureTechnique = std::make_shared<Objects::Techniques::TextureTechnique>();

            _object.addTechnique(Objects::Techniques::TEXTURE, textureTechnique);
            _object.disableTechnique(Objects::Techniques::TEXTURE);
        } else {
            textureTechnique = std::dynamic_pointer_cast<Objects::Techniques::TextureTechnique>(technique);
        }

        textureTechnique->setTexture(texture);
        textureTechnique->setTextureIndex(textureIndex);
    }

    void Form::renderText(Objects::Shaders::ShaderProgram::Ptr shader) {
        _object.enableTechnique(Objects::Techniques::TEXT);

        _object.render(std::move(shader));

        _object.disableTechnique(Objects::Techniques::TEXT);
    }

    void Form::renderForm(Objects::Shaders::ShaderProgram::Ptr shader) {
        if (_object.hasTechnique(Objects::Techniques::TEXTURE)) {
            _object.enableTechnique(Objects::Techniques::TEXTURE);
            _object.enableTechnique(Objects::Techniques::TRANSFORM);

            _object.render(std::move(shader));

            _object.disableTechnique(Objects::Techniques::TEXTURE);
            _object.disableTechnique(Objects::Techniques::TRANSFORM);
        } else {
            _object.enableTechnique(Objects::Techniques::COLOR);
            _object.enableTechnique(Objects::Techniques::TRANSFORM);

            _object.render(std::move(shader));

            _object.disableTechnique(Objects::Techniques::COLOR);
            _object.disableTechnique(Objects::Techniques::TRANSFORM);
        }
    }

    glm::vec2 Form::getScale() {
        auto technique =  _object.getTechnique(Objects::Techniques::TRANSFORM);
        if (technique != nullptr) {
            return std::dynamic_pointer_cast<Objects::Techniques::TransformTechnique>(technique)->getScaleValue();
        } else
            return {};
    }

    glm::vec2 Form::getPosition() {
        auto technique =  _object.getTechnique(Objects::Techniques::TRANSFORM);
        if (technique != nullptr) {
            return std::dynamic_pointer_cast<Objects::Techniques::TransformTechnique>(technique)->getTransformValue();
        } else
            return {};
    }

    std::u16string Form::getText() {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        if (technique != nullptr) {
            return std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique)->getText();
        } else
            return {};
    }

    glm::vec2 Form::getTextPosition() {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        if (technique != nullptr) {
            auto textTechnique = std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique);
            return {textTechnique->getWidth(), textTechnique->getHeight()};
        } else
            return {};
    }

    float Form::getTextScale() {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        if (technique != nullptr) {
            return std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique)->getScale();
        } else
            return {};
    }

    glm::vec3 Form::getTextColor() {
        auto technique = _object.getTechnique(Objects::Techniques::TEXT);
        if (technique != nullptr) {
            return std::dynamic_pointer_cast<Objects::Techniques::TextTechnique>(technique)->getColor();
        } else
            return {};
    }

    glm::vec3 Form::getColor() {
        auto technique =  _object.getTechnique(Objects::Techniques::COLOR);
        if (technique != nullptr) {
            return std::dynamic_pointer_cast<Objects::Techniques::ColorTechnique>(technique)->getRgb();
        } else
            return {};
    }

    Objects::Textures::Texture::Ptr Form::getTexture() {
        auto technique =  _object.getTechnique(Objects::Techniques::TEXTURE);
        if (technique != nullptr) {
            return std::dynamic_pointer_cast<Objects::Techniques::TextureTechnique>(technique)->getTexture();
        } else
            return {};
    }
}    //namespace Widgets::Graphic
