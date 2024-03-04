//
// Created by VerOchka on 24.10.2023.
//

#ifndef ROLLANDPLAY_TEXTRENDER_HPP
#define ROLLANDPLAY_TEXTRENDER_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include <map>

#include "GraphicLib/FT2.hpp"
#include "GraphicLib/GlagGlfw.hpp"
#include "GraphicLib/Shaders/ShaderProgram.hpp"
#include "GraphicLib/Objects/Buffers/Vao.hpp"
#include "GraphicLib/Objects/Buffers/Vbo.hpp"
#include "GraphicLib/Objects/Textures/Texture.hpp"

namespace GraphicLib::Objects {
    class TextRender {
    public:
        using Ptr = std::shared_ptr<TextRender>;

        struct Character {
            Textures::Texture::Ptr texture; // IdCounter текстуры глифа
            glm::ivec2 size;                // размер глифа
            glm::ivec2 bearing;             // смещение от линии шрифта до верхнего левого угла глифа
            unsigned int advance;           // горизонтальное смещение для перехода к следующему глифу
        };

        TextRender(unsigned int width, unsigned int height);

        void load(const std::string& font, unsigned int fontSize);

        void render(std::string text, float x, float y, float scale, glm::vec3 color);

        void render(std::u16string text, float x, float y, float scale, glm::vec3 color);

        Character getCharacter(char16_t code);
    private:
        // Список предварительно скомпилированных символов
        std::map<char16_t, Character> characters;

        // Состояние рендеринга
        Buffers::VAO::Ptr _vao;
        Buffers::VBO<glm::vec4>::Ptr _vbo;
    };
}

#endif //ROLLANDPLAY_TEXTRENDER_HPP
