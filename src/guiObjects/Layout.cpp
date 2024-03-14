//
// Created by BethsFaith on 29.01.2024.
//

#include "GraphicLib/GuiObjects/Layout.hpp"

namespace GraphicLib::GuiObjects {
    Layout::Layout(LayoutType type) : _type(type) {}

    void Layout::putGuiObject(GuiObject::Ptr guiObject) {
        auto type = guiObject->getGuiType();
        if (type == WIDGET) {
            putWidget(std::dynamic_pointer_cast<Widget>(guiObject));
        } else if (type == LAYOUT){
            putLayout(std::dynamic_pointer_cast<Layout>(guiObject));
        }
    }

    void Layout::removeGuiObject(GuiObject::Ptr guiObject) {
        auto pos = std::find(objects.begin(), objects.end(), guiObject);
        if (pos != objects.end()) {
            scale -= guiObject->getScale();

            objects.erase(pos);
        }
    }

    void Layout::setWidgetOffset(float offset) {
        widgetOffset = offset;
    }

    void Layout::setTransform(glm::vec2 position_, glm::vec2 scale_) {
        elemScale = scale_;
        setTransform(position_);
    }

    void Layout::setTransform(glm::vec2 position_) {
        position = position_;

        auto elements = objects;
        objects.clear();
        for (auto& elem : elements) {
            putGuiObject(elem);
        }
    }

    void Layout::setScale(glm::vec2 elemScale_) {
        elemScale = elemScale_;

        auto elements = objects;
        objects.clear();
        for (auto& elem : elements) {
            putGuiObject(elem);
        }
    }

    glm::vec2 Layout::getScale() {
        return scale;
    }

    glm::vec2 Layout::getPosition() {
        return position;
    }

    std::vector<Widget::Ptr> Layout::getWidgets() const {
        std::vector<Widget::Ptr> widgets;
        for (const auto& object : objects) {
            auto type = object->getGuiType();
            if (type == WIDGET) {
                widgets.push_back(std::dynamic_pointer_cast<Widget>(object));
            } else if (type == LAYOUT){
                auto subWidgets = std::dynamic_pointer_cast<Layout>(object)->getWidgets();
                widgets.insert(widgets.end(), subWidgets.begin(), subWidgets.end());
            }
        }
        return widgets;
    }

    LayoutType Layout::getType() const {
        return _type;
    }

    GuiObjectType Layout::getGuiType() const {
        return LAYOUT;
    }
}    //namespace Widgets
