//
// Created by BethsFaith on 29.01.2024.
//

#ifndef ROLLANDPLAY_LAYOUT_HPP
#define ROLLANDPLAY_LAYOUT_HPP

#include "Widget.hpp"
#include "WidgetBox.hpp"
#include "LayoutType.hpp"

namespace GraphicLib::GuiObjects {
    class Layout : public GuiObject {
    public:
        using Ptr = std::shared_ptr<Layout>;

        explicit Layout(LayoutType type);
        ~Layout() = default;

        virtual void putGuiObject(GuiObject::Ptr guiObject);
        virtual void removeGuiObject(GuiObject::Ptr guiObject);

        virtual void clear() = 0;

        void setTransform(glm::vec2 position, glm::vec2 scale) override;
        void setTransform(glm::vec2 position) override;
        void setScale(glm::vec2 elemScale) override;
        void setWidgetOffset(float offset);

        glm::vec2 getScale() override;
        glm::vec2 getPosition() override;

        [[nodiscard]] LayoutType getType() const;

        [[nodiscard]] std::vector<Widget::Ptr> getWidgets() const;

        [[nodiscard]] GuiObjectType getGuiType() const override;

    protected:
        virtual void beforePuttingGuiObject(GuiObject::Ptr guiObject) = 0;
        virtual void beforeDeletingGuiObject(GuiObject::Ptr guiObject) = 0;

        float widgetOffset = 0.1f;

        glm::vec2 position{};
        glm::vec2 elemScale{};
        glm::vec2 scale{};

        std::vector<GuiObject::Ptr> objects;
    private:
        LayoutType _type;
    };
}    //namespace Widgets

#endif    //ROLLANDPLAY_LAYOUT_HPP
