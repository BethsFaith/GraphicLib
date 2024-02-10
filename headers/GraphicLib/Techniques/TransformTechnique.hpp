//
// Created by VerOchka on 23.10.2023.
//

#ifndef ROLLANDPLAY_TRANSFORMTECHNIQUE_HPP
#define ROLLANDPLAY_TRANSFORMTECHNIQUE_HPP

#include "Technique.hpp"

namespace GraphicLib::Techniques {
    class TransformTechnique : public Technique {
    public:
        using Ptr = std::shared_ptr<TransformTechnique>;

        struct Rotate {
            float angle{360.0f};
            glm::vec3 coordinates{0.0f};
        };

        TransformTechnique() = default;
        ~TransformTechnique() override = default;

        void execute() override;

        void enableTransform(const glm::vec3 &transformValue);
        void enableTransform();
        void disableTransform();

        void enableScale(const glm::vec3 &scaleValue);
        void enableScale();
        void disableScale();

        void enableRotate(const Rotate& rotateValue);
        void enableRotate();
        void disableRotate();

        void enableProjection(float angle, float width, float height);
        void enableProjection();
        void disableProjection();

        [[nodiscard]] const glm::vec3 &getTransformValue() const;
        [[nodiscard]] const glm::vec3 &getScaleValue() const;
        [[nodiscard]] const Rotate &getRotateValue() const;
        void setTransformValue(const glm::vec3& transformValue);
        void setProjectionValue(float angle, float width, float height);
        void setScaleValue(const glm::vec3& scaleValue);
        void setRotateValue(const Rotate& rotateValue);

    private:
        bool _needRotate = false;
        bool _needScale = false;
        bool _needTransform = false;
        bool _needProjection = false;

        glm::vec3 _transformValue{0.0f};
        glm::vec3 _scaleValue{0.0f};
        Rotate _rotateValue{};
        glm::mat4 _projectionValue{0.0f};
    };

} // Techiques

#endif //ROLLANDPLAY_TRANSFORMTECHNIQUE_HPP
