//
// Created by VerOchka on 26.10.2023.
//

#include "GraphicLib/Objects/Techniques/TextureTechnique.hpp"

namespace GraphicLib::Objects::Techniques {
    void TextureTechnique::execute() {
        shader->setInt("Texture", _textureIndex);
        _texture->activate(GL_TEXTURE0 + _textureIndex);
    }

    void TextureTechnique::setTexture(const Textures::Texture::Ptr& texture) {
        _texture = texture;
    }

    void TextureTechnique::setTextureIndex(int textureIndex) {
        _textureIndex = textureIndex;
    }

    const Textures::Texture::Ptr& TextureTechnique::getTexture() const {
        return _texture;
    }

    int TextureTechnique::getTextureIndex() const {
        return _textureIndex;
    }
}    //namespace GraphicLib::Techniques
