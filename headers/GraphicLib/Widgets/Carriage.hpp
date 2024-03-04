//
// Created by VerOchka on 05.01.2024.
//

#ifndef ROLLANDPLAY_CARRIAGE_HPP
#define ROLLANDPLAY_CARRIAGE_HPP

#include "GraphicLib/Objects/Object.hpp"
#include "GraphicLib/Objects/Primitives/Rectangle.hpp"
#include "GraphicLib/Objects/Techniques/ColorTechnique.hpp"
#include "GraphicLib/Objects/Techniques/TransformTechnique.hpp"
#include "GraphicLib/Objects/TextRender.hpp"

#include "styles/Color.hpp"

namespace GraphicLib::Widgets {
    class Carriage {
    public:
        struct CharacterOffset {
            glm::ivec2 bearing;
            unsigned int advance;
        };

        Carriage();

        void init(Styles::Color color, const glm::vec2& scale, const glm::vec2& position, float textSize);

        void render(const Objects::Shaders::ShaderProgram::Ptr& shader);

        void show();
        void hide();

        void move(int indexOffset);
        void moveToIndex(unsigned int index);
        void moveToScreenPosition(float xPos);

        void addCharacterData(const CharacterOffset& character);
        void releaseCharacterData(unsigned int index);
        void releaseBackCharacterData();
        void clearAllCharacterData();

        [[nodiscard]] uint8_t getPosition() const;

        static inline int WindowHeight = 1440;
        static inline int WindowWidth = 720;
    private:
        Objects::Object::Ptr _object;
        uint8_t _position = 0;
        float _initXPosition{};
        std::vector<CharacterOffset> _characterOffsets{};
        float _textSize = 1.0f;
    };
}    //namespace Forms

#endif    //ROLLANDPLAY_CARRIAGE_HPP
