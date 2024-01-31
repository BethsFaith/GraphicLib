//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_PICKTECHNIQUE_HPP
#define ROLLANDPLAY_PICKTECHNIQUE_HPP

#include "Technique.hpp"

namespace GraphicLib::Techniques  {
    class PickTechnique : public Technique {
    public:
        using Ptr = std::shared_ptr<PickTechnique>;

        PickTechnique() = default;
        ~PickTechnique() override = default;

        void setDrawId(float drawId);
        void setObjectId(float objectId);

        void execute() override;

    private:
        void setId(const std::string& name, float id);

        float _drawId = 0.0f;
        float _objectId = 0.0f;
    };
}

#endif //ROLLANDPLAY_PICKTECHNIQUE_HPP
