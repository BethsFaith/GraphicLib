//
// Created by VerOchka on 17.08.2023.
//
#include "GraphicLib/Objects/Buffers/RaiiBuffer.hpp"

namespace GraphicLib::Objects::Buffers {
    RaiiBuffer::RaiiBuffer(const int& priority) : _priority(priority) {}

    unsigned int RaiiBuffer::getPriority() const {
        return _priority;
    }
}    //namespace GraphicLib::Buffers
