//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_IMAGEBUTTON_HPP
#define ROLLANDPLAY_IMAGEBUTTON_HPP

#include "GraphicLib/Objects/Textures/Loader.hpp"
#include "GraphicLib/Objects/Textures/Texture.hpp"

#include "Button.hpp"

namespace GraphicLib::Widgets {
    class ImageButton : public Button {
    public:
        using Ptr = std::shared_ptr<ImageButton>;

        explicit ImageButton(Objects::Primitives::AbstractPrimitive::Ptr graphicPrimitive);

        void draw(Objects::Shaders::ShaderProgram::Ptr colorShader,
                  Objects::Shaders::ShaderProgram::Ptr textureShader,
                  Objects::Shaders::ShaderProgram::Ptr textShader,
                  Objects::Shaders::ShaderProgram::Ptr pickShader) override;

        void setColor(Styles::Color color) override;
        void setImage(const std::string& texturePath, int textureIndex);
        void setDefaultImage(const std::string& texturePath, int textureIndex);

        void resetImage(int defaultTextureIndex);

        [[nodiscard]] const Objects::Textures::Texture::Ptr& getTexture() const;
        glm::vec2 getScale() override;

    protected:
        void updateTextPosition(glm::vec2 position, glm::vec2 scale) override;

    private:
        Objects::Textures::Texture::Ptr _texture;
        Objects::Textures::Texture::Ptr _defaultTexture;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_IMAGEBUTTON_HPP
