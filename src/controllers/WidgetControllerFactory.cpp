//
// Created by VerOchka on 26.10.2023.
//

#include "GraphicLib/Controllers/WidgetControllerFactory.hpp"

namespace GraphicLib::Controllers {
    WidgetController::Ptr WidgetControllerFactory::create(GuiObjects::WidgetType type) {
        switch (type) {
            case GuiObjects::BUTTON:
                return std::make_shared<Controllers::ButtonController>();
            case GuiObjects::NUM_INPUT_FIELD:
            case GuiObjects::TEXT_INPUT_FIELD:
                return std::make_shared<Controllers::TextInputFieldController>();
            case GuiObjects::IMAGE_BUTTON:
                return std::make_shared<Controllers::ImageButtonController>();
            case GuiObjects::MENU_BAR:
                return std::make_shared<Controllers::MenuBarController>();
            case GuiObjects::SCROLL_BOX:
                return std::make_shared<Controllers::ScrollBoxController>();
            default:
                return nullptr;
        }
    }
}    //namespace Controllers
