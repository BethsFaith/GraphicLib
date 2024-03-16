//
// Created by BethsFaith on 08.02.2024.
//

#ifndef INC_1_BIN_IMAGEBOX_HPP
#define INC_1_BIN_IMAGEBOX_HPP

#include "../Objects/Textures/Loader.hpp"
#include "../Objects/Textures/Texture.hpp"

#include "Widget.hpp"
#include "graphic/Form.hpp"
#include "styles/TextParams.hpp"

namespace GraphicLib::GuiObjects {
    class ImageBox : public Widget {
    public:
        using Ptr = std::shared_ptr<ImageBox>;

        explicit ImageBox(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive);
        ~ImageBox() override = default;

        bool checkSelecting(unsigned int x, unsigned int y) override;
        void draw(Shaders::ShaderProgram::Ptr colorShader,
                  Shaders::ShaderProgram::Ptr textureShader,
                  Shaders::ShaderProgram::Ptr textShader,
                  Shaders::ShaderProgram::Ptr pickShader) override;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 scale) override;

        void setLabelParams(const Styles::TextParams& text);
        void setLabelText(const std::u16string& text);
        void setLabelPosition(glm::vec2 position);
        void setLabelColor(glm::vec3 color);
        void setLabelTextSize(float size);

        glm::vec2 getScale() override;
        glm::vec2 getPosition() override;

        void setImage(const std::string& texturePath, int textureIndex);

        [[nodiscard]] const Objects::Textures::Texture::Ptr& getTexture() const;
        glm::vec2 getUniformPosition() override;

    protected:
        glm::vec2 countUniformPosition(glm::vec2 position, glm::vec2 scale) override;
        glm::vec2 countOriginalPosition(glm::vec2 position, glm::vec2 scale) override;

    private:
        Graphic::Form _form;

        Objects::Textures::Texture::Ptr _texture;
    };

}    //namespace Widgets

#endif    //INC_1_BIN_IMAGEBOX_HPP
