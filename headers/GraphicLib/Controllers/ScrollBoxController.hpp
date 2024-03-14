//
// Created by BethsFaith on 14.03.2024.
//

#ifndef GRAPHICLIB_SCROLLBOXCONTROLLER_HPP
#define GRAPHICLIB_SCROLLBOXCONTROLLER_HPP

#include "WidgetController.hpp"
#include "GraphicLib/Widgets/ScrollBox.hpp"

namespace GraphicLib::Controllers {
    class ScrollBoxController : public WidgetController {
    public:
        ~ScrollBoxController() override = default;

        void processKeyboardInput(GLFWwindow* window) override;

        void processMouseButton(GLFWwindow* window, int mouseButton, int action, int mods) override;

        void processMouseCursor(GLFWwindow* window, double xPos, double yPos) override;

        void processMouseScroll(double xOffset, double yOffset) override;

        void processCharMods(GLFWwindow* window, unsigned int codepoint, int mods) override;

        void processDrop(GLFWwindow* window, int count, const char** paths) override;

        void clear() override {}

        void addWidget(Widgets::Widget::Ptr widget) override;
        void removeWidget(const Widgets::Widget::Ptr& widget) override;

    private:
        std::vector<Widgets::ScrollBox::Ptr> _scrollBoxes;
        Widgets::ScrollBox::Ptr scrollTarget;
    };
}

#endif    //GRAPHICLIB_SCROLLBOXCONTROLLER_HPP
