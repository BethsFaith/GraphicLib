//
// Created by VeraTag on 25.10.2023.
//

#ifndef ROLLANDPLAY_TEXTINPUTFIELDCONTROLLER_HPP
#define ROLLANDPLAY_TEXTINPUTFIELDCONTROLLER_HPP

#include <chrono>
#include <thread>

#include "GraphicLib/GuiObjects/TextInputField.hpp"
#include "WidgetController.hpp"

namespace GraphicLib::Controllers {
    class TextInputFieldController : public WidgetController {
    public:
        ~TextInputFieldController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void clear() override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

        void addWidget(GuiObjects::Widget::Ptr widget) override;
        void processDrop(GLFWwindow* window, int count, const char** paths) override;
        void removeWidget(const GuiObjects::Widget::Ptr& widget) override;

    private:
        std::vector<GuiObjects::TextInputField::Ptr> _buttons;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_TEXTINPUTFIELDCONTROLLER_HPP
