//
// Created by VerOchka on 10.10.2023.
//

#include "GraphicLib/GuiObjects/Gui.hpp"

namespace GraphicLib::GuiObjects {
    GraphicLib::Shaders::ShaderProgram::Ptr Gui::colorShader = nullptr;
    GraphicLib::Shaders::ShaderProgram::Ptr Gui::textureShader = nullptr;
    GraphicLib::Shaders::ShaderProgram::Ptr Gui::selectableShader = nullptr;
    GraphicLib::Shaders::ShaderProgram::Ptr Gui::textShader = nullptr;

    Gui::Gui(GraphicLib::Objects::PickableTexture::Ptr canvas) : _canvas(std::move(canvas)) {
        _controller = std::make_shared<Controllers::GuiController>();
    }

    void Gui::draw() {
        for (auto& widget : _widgets) {
            widget->draw(colorShader, textureShader, textShader, selectableShader);
        }
    }

    void Gui::addWidget(const GuiObjects::Widget::Ptr& widget) {
        widget->setCanvas(_canvas);

        _controller->addWidget(widget);

        _widgets.push_back(widget);
    }

    void Gui::removeWidget(const GuiObjects::Widget::Ptr& widget) {
        _controller->removeWidget(widget);

        auto end = std::remove(_widgets.begin(), _widgets.end(), widget);
        _widgets.erase(end, _widgets.end());
    }

    void Gui::clear() {
        _widgets.clear();
        //    _controller->clear();
    }

    const Controllers::GuiController::Ptr& Gui::getController() const {
        return _controller;
    }

    void Gui::setColorShader(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        colorShader = std::move(shader);
    }

    void Gui::setTextureShader(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        textureShader = std::move(shader);
    }

    void Gui::setSelectableShader(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        selectableShader = std::move(shader);
    }

    void Gui::setTextShader(GraphicLib::Shaders::ShaderProgram::Ptr shader) {
        textShader = std::move(shader);
    }
}