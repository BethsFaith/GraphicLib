//
// Created by BethsFaith on 14.03.2024.
//

#include "GraphicLib/Controllers/ScrollBoxController.hpp"

namespace GraphicLib::Controllers {
    void ScrollBoxController::processKeyboardInput(GLFWwindow* window) {}

    void ScrollBoxController::processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) {}

    void ScrollBoxController::processMouseCursor(GLFWwindow* window, double xPos, double yPos) {
        glfwGetCursorPos(window, &xPos, &yPos);

        int width, height;
        glfwGetWindowSize(window, &width, &height);

        for (const auto& scrollBox : _scrollBoxes) {
            if (scrollBox->checkSelecting((int)xPos, int(height - yPos - 1))) {
                scrollTarget = scrollBox;
                break;
            } else if (scrollBox == scrollTarget) {
                scrollTarget = nullptr;
            }
        }
    }

    void ScrollBoxController::processMouseScroll(double xOffset, double yOffset) {
        if (scrollTarget != nullptr) {
            scrollTarget->scroll(xOffset, yOffset);
        }
    }

    void ScrollBoxController::processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) {}

    void ScrollBoxController::processDrop(GLFWwindow* window, int count, const char** paths) {}

    void ScrollBoxController::addWidget(GuiObjects::Widget::Ptr widget) {
        _scrollBoxes.push_back(std::dynamic_pointer_cast<GuiObjects::ScrollBox>(widget));
    }

    void ScrollBoxController::removeWidget(const GuiObjects::Widget::Ptr& widget) {
        _scrollBoxes.push_back(std::dynamic_pointer_cast<GuiObjects::ScrollBox>(widget));
    }
}    //namespace GraphicLib::Controllers
