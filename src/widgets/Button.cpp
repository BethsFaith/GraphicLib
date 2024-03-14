//
// Created by VerOchka on 06.10.2023.
//

#include <utility>

#include "GraphicLib/Widgets/Button.hpp"
#include "GraphicLib/Widgets/styles/TextParams.hpp"

namespace GraphicLib::Widgets {
    int Button::IdCounter = 0;

    Button::Button(Objects::Primitives::AbstractPrimitive::Ptr graphicPrimitive)
        : Button(graphicPrimitive, WidgetType::BUTTON) {}

    Button::Button(const Objects::Primitives::AbstractPrimitive::Ptr& graphicPrimitive, WidgetType type) : Widget(type),
          _form(graphicPrimitive, (float)++IdCounter),
          _tracing(graphicPrimitive) {

        id = IdCounter;

        _tracing.setColor({1.0f, 1.0f, 1.0f});
    }

    void Button::draw(Shaders::ShaderProgram::Ptr colorShader,
                      Shaders::ShaderProgram::Ptr textureShader,
                      Shaders::ShaderProgram::Ptr textShader,
                      Shaders::ShaderProgram::Ptr pickShader) {
        if (isUnderCursor()) {
            glStencilMask(0xFF);
            glStencilFunc(GL_ALWAYS, 1, 0xFF);
            glEnable(GL_DEPTH_TEST);
            glDisable(GL_STENCIL_TEST);

            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

            glStencilFunc(GL_ALWAYS, 1, 0xFF);    // все фрагменты должны пройти тест трафарета
            glStencilMask(0xFF);    // включаем запись в буфер трафарета

            _form.renderForm(colorShader);

            glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
            glStencilMask(0x00);
            glDisable(GL_STENCIL_TEST);

            _form.renderText(textShader);
            _form.renderPick(pickShader, canvas);

            glDisable(GL_DEPTH_TEST);
            glEnable(GL_STENCIL_TEST);

            _tracing.renderForm(colorShader);

            glStencilMask(0xFF);
            glStencilFunc(GL_ALWAYS, 1, 0xFF);
            glEnable(GL_DEPTH_TEST);
            glDisable(GL_STENCIL_TEST);
        } else {
            _form.renderForm(colorShader);
            _form.renderText(textShader);
            _form.renderPick(pickShader, canvas);
        }
    }

    void Button::press() {
        _pressCallback();

        _isPressed = true;
    }

    void Button::release() {
        _releaseCallback();

        _isPressed = false;
    }

    bool Button::isUnderCursor() const {
        return _isUnderCursor;
    }

    bool Button::isPressed() const {
        return _isPressed;
    }

    bool Button::checkSelecting(unsigned int x, unsigned int y) {
        if (canvas == nullptr) {
            return false;
        }

        auto info = canvas->readPixel(x, y);

        return id == (int)info.ObjectID;
    }

    bool Button::checkId(int id_) const {
        return id == id_;
    }

    void Button::setUnderCursor(bool isUnderCursor) {
        _isUnderCursor = isUnderCursor;
    }

    void Button::setPressCallback(const std::function<void()>& function) {
        _pressCallback = function;
    }

    void Button::setReleaseCallback(const std::function<void()>& function) {
        _releaseCallback = function;
    }

    void Button::setTransform(glm::vec2 position) {
        _form.setTransform(position);

        auto scale = getScale();

        _tracing.setTransform(position, {scale.x * 1.05f, scale.y * 1.1f});

        updateTextPosition(position, scale);
    }

    void Button::setTransform(glm::vec2 position, glm::vec2 scale) {
        _form.setTransform(position, scale);
        _tracing.setTransform(position, {scale.x * 1.05f, scale.y * 1.1f});

        updateTextPosition(position, scale);
    }

    void Button::setScale(glm::vec2 scale) {
        _form.setScale(scale);
        _tracing.setScale({scale.x * 1.05f, scale.y * 1.1f});

        updateTextPosition(getPosition(), scale);
    }

    void Button::updateTextPosition(glm::vec2 position, glm::vec2 scale) {
        _form.setTextPosition({position.x - scale.x / 2.0f + 0.01f, position.y});
    }

    void Button::setLabelPosition(glm::vec2 position) {
        _form.setTextPosition({position.x, position.y});
    }

    void Button::setLabelParams(const Styles::TextParams& text) {
        _form.setTextColor(text.color);
        _form.setTextPosition(text.position);
        _form.setTextSize(text.size);
    }

    void Button::setLabelColor(glm::vec3 color) {
        _form.setTextColor(color);
    }

    void Button::setLabelText(const std::u16string& text) {
        _form.setText(text);
    }

    void Button::setLabelTextSize(float size) {
        _form.setTextSize(size);
    }

    void Button::setColor(glm::vec3 color) {
        _form.setColor(color);
    }

    void Button::setTraceColor(glm::vec3 traceColor) {
        _tracing.setColor(traceColor);
    }

    glm::vec2 Button::getPosition() {
        return _form.getPosition();
    }

    glm::vec2 Button::getScale() {
        return _form.getScale();
    }

    std::u16string Button::getTextLabelContent() {
        return _form.getText();
    }

    glm::vec2 Button::getTextLabelPosition() {
        return _form.getTextPosition();
    }

    glm::vec3 Button::getColor() {
        return _form.getColor();
    }
}    //namespace Forms
