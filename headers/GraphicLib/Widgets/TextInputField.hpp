//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_TEXTINPUTFIELD_HPP
#define ROLLANDPLAY_TEXTINPUTFIELD_HPP

#include <iostream>
#include <utility>
#ifdef WIN32
#include <codecvt>
#else
#include <uchar.h>
#endif

#include "GraphicLib/Objects/Primitives/Rectangle.hpp"

#include "Button.hpp"
#include "Carriage.hpp"

namespace GraphicLib::Widgets {
    class TextInputField : public Button {
    public:
        using Ptr = std::shared_ptr<TextInputField>;

        explicit TextInputField(const Objects::Primitives::Rectangle::Ptr& graphicPrimitive,
                                Styles::TextParams inputParams);

        ~TextInputField() override = default;

        void draw(Objects::Shaders::ShaderProgram::Ptr colorShader,
                  Objects::Shaders::ShaderProgram::Ptr textureShader,
                  Objects::Shaders::ShaderProgram::Ptr textShader,
                  Objects::Shaders::ShaderProgram::Ptr pickShader) override;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 scale) override;

        glm::vec2 getScale() override;

        void press() override;
        void release() override;

        virtual void putToBuffer(char16_t character);
        virtual void putToBuffer(const std::string& string);

        virtual void putToBuffer(const std::u16string& string);
        virtual void popFromBuffer();

        virtual void popFromBuffer(unsigned int position);

        void hideContent(bool needHide);

        void clear();

        void moveCarriage(int offset);
        void moveCarriageToScreenPosition(float xPos);
        [[nodiscard]] std::string getU8Buf() const;
        [[nodiscard]] const std::u16string& getBuf() const;

    protected:
        explicit TextInputField(const Objects::Primitives::Rectangle::Ptr& graphicPrimitive,
                                Styles::TextParams inputParams, WidgetType type);

        void updateInputField();

        void putToBuffer(char16_t character, unsigned int position);
        void putToBuffer(const std::string& string, unsigned int position);
        void putToBuffer(const std::u16string& string, unsigned int position);
        void updateTextPosition(glm::vec2 position, glm::vec2 scale) override;

        Graphic::Form _textField;

        std::u16string _buf;
    private:
        bool _needHide = false;

        Carriage _carriage{};
    };
}    //namespace Forms
#endif    //ROLLANDPLAY_TEXTINPUTFIELD_HPP
