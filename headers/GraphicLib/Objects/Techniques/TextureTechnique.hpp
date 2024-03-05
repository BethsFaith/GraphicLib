//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_TEXTURETECHNIQUE_HPP
#define ROLLANDPLAY_TEXTURETECHNIQUE_HPP

#include "GraphicLib/Objects/Textures/Texture.hpp"
#include "Technique.hpp"

namespace GraphicLib::Objects::Techniques {
    class TextureTechnique : public Technique {
    public:
        using Ptr = std::shared_ptr<TextureTechnique>;

        TextureTechnique() = default;
        ~TextureTechnique() override = default;

        void execute() override;

        void setTexture(const Textures::Texture::Ptr &texture);
        void setTextureIndex(int textureIndex);

        [[nodiscard]] const Textures::Texture::Ptr& getTexture() const;
        [[nodiscard]] int getTextureIndex() const;
    private:
        Textures::Texture::Ptr _texture;
        int _textureIndex{};
    };
}

#endif //ROLLANDPLAY_TEXTURETECHNIQUE_HPP
