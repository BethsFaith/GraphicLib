//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_IMAGEBUTTONCONTROLLER_HPP
#define ROLLANDPLAY_IMAGEBUTTONCONTROLLER_HPP

#include "GraphicLib/GuiObjects/ImageButton.hpp"
#include "WidgetController.hpp"

namespace GraphicLib::Controllers {
    class ImageButtonController : public WidgetController {
    public:
        ~ImageButtonController() override = default;

        void addWidget(GuiObjects::Widget::Ptr widget) override;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

        void clear() override;
        void processDrop(GLFWwindow* window, int count, const char** paths) override;
        void removeWidget(const GuiObjects::Widget::Ptr& widget) override;

    private:
        std::vector<GuiObjects::ImageButton::Ptr> _buttons;
    };
}    //namespace Controllers

#endif    //ROLLANDPLAY_IMAGEBUTTONCONTROLLER_HPP
