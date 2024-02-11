//
// Created by VerOchka on 23.10.2023.
//

#include "../../headers/GraphicLib/Techniques/TransformTechnique.hpp"

namespace GraphicLib::Techniques {
    void TransformTechnique::enableTransform(const glm::vec3& transformValue) {
        _transformValue = transformValue;
        _needTransform = true;
    }

    void TransformTechnique::enableTransform() {
        _needTransform = true;
    }

    void TransformTechnique::disableTransform() {
        _needTransform = false;
    }

    void TransformTechnique::enableScale(const glm::vec3& scaleValue) {
        _scaleValue = scaleValue;
        _needScale = true;
    }

    void TransformTechnique::enableScale() {
        _needScale = true;
    }

    void TransformTechnique::disableScale() {
        _needScale = false;
    }

    void TransformTechnique::enableRotate(const Rotate& rotateValue) {
        _rotateValue = rotateValue;
        _needRotate = true;
    }

    void TransformTechnique::enableRotate() {
        _needRotate = true;
    }

    void TransformTechnique::disableRotate() {
        _needRotate = false;
    }

    void TransformTechnique::enableProjection(float minX, float maxX, float minY, float maxY) {
        _projectionValue = glm::ortho(minX, maxX, minY, maxY);
        _needProjection = true;
    }

    void TransformTechnique::enableProjection() {
        _needProjection = true;
    }

    void TransformTechnique::disableProjection() {
        _needProjection = false;
    }

    void TransformTechnique::execute() {
        glm::mat4 trans = glm::mat4(1.0f);
        if (_needTransform) {
            trans = glm::translate(trans, _transformValue);
        }
        if (_needRotate) {
            trans = glm::rotate(trans, glm::radians(_rotateValue.angle), _rotateValue.coordinates);
        }
        if (_needScale) {
            trans = glm::scale(trans, _scaleValue);
        }

        shader->set4FloatMat("Transform", glm::value_ptr(trans));

        if (_needProjection) {
            shader->set4FloatMat("Projection", glm::value_ptr(_projectionValue));
        }
    }

    const glm::vec3& TransformTechnique::getTransformValue() const {
        return _transformValue;
    }

    const glm::vec3& TransformTechnique::getScaleValue() const {
        return _scaleValue;
    }

    const TransformTechnique::Rotate& TransformTechnique::getRotateValue() const {
        return _rotateValue;
    }

    void TransformTechnique::setTransformValue(const glm::vec3& transformValue) {
        _transformValue = transformValue;
    }

    void TransformTechnique::setScaleValue(const glm::vec3& scaleValue) {
        _scaleValue = scaleValue;
    }

    void TransformTechnique::setRotateValue(const TransformTechnique::Rotate& rotateValue) {
        _rotateValue = rotateValue;
    }

    void TransformTechnique::setProjectionValue(float minX, float maxX, float minY, float maxY) {
        _projectionValue = glm::ortho(minX, maxX, minY, maxY);
    }
}    //namespace GraphicLib::Techniques
