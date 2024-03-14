//
// Created by VerOchka on 26.10.2023.
//

#ifndef ROLLANDPLAY_TEXTPARAMS_HPP
#define ROLLANDPLAY_TEXTPARAMS_HPP

#include <iostream>

namespace GraphicLib::GuiObjects::Styles {
    struct TextParams {
        glm::vec3 color = {0.0f, 0.0f, 0.0f};

        float size;
        glm::vec2 position;
    };
}

#endif    //ROLLANDPLAY_TEXTPARAMS_HPP
