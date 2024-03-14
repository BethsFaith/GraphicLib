cmake_minimum_required(VERSION 3.25)
project(GraphicLib)

set(CMAKE_CXX_STANDARD 20)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE
        conanfile.txt
        INSTALL_FOLDER ${CMAKE_BINARY_DIR}
        BASIC_SETUP
        BUILD missing)

add_library(GraphicLib
        libs/stb_image.cpp
        src/objects/Object.cpp
        src/objects/TextRender.cpp
        src/objects/PickableTexture.cpp
        src/objects/primitives/Primitive.cpp
        src/objects/primitives/Rectangle.cpp
        src/shaders/ShaderProgram.cpp
        src/objects/buffers/Vertex.cpp
        src/objects/buffers/Vbo.cpp
        src/objects/buffers/VboT.cpp
        src/objects/buffers/Vao.cpp
        src/objects/buffers/RaiiBuffer.cpp
        src/objects/buffers/Ebo.cpp
        src/objects/buffers/Fbo.cpp
        src/objects/textures/Loader.cpp
        src/objects/textures/Texture.cpp
        src/objects/techniques/Technique.cpp
        src/objects/techniques/TextTechnique.cpp
        src/objects/techniques/TransformTechnique.cpp
        src/objects/techniques/PickTechnique.cpp
        src/objects/techniques/ColorTechnique.cpp
        src/objects/techniques/TextureTechnique.cpp
        src/guiObjects/Widget.cpp
        src/guiObjects/WidgetBuilder.cpp
        src/guiObjects/WidgetFactory.cpp
        src/guiObjects/Gui.cpp
        src/guiObjects/Button.cpp
        src/guiObjects/Carriage.cpp
        src/guiObjects/HorizontalLayout.cpp
        src/guiObjects/ImageBox.cpp
        src/guiObjects/ImageButton.cpp
        src/guiObjects/Layout.cpp
        src/guiObjects/MenuBar.cpp
        src/guiObjects/NumericInputField.cpp
        src/guiObjects/TextBox.cpp
        src/guiObjects/TextInputField.cpp
        src/guiObjects/ScrollBox.cpp
        src/guiObjects/VerticalScrollBox.cpp
        src/guiObjects/WidgetBox.cpp
        src/guiObjects/VerticalLayout.cpp
        src/guiObjects/graphic/Form.cpp
        src/guiObjects/graphic/PickableForm.cpp
        src/controllers/GuiController.cpp
        src/controllers/ButtonController.cpp
        src/controllers/CommonController.cpp
        src/controllers/ImageButtonController.cpp
        src/controllers/MenuBarController.cpp
        src/controllers/TextInputFieldController.cpp
        src/controllers/ScrollBoxController.cpp
        src/controllers/WidgetControllerFactory.cpp
        )

target_link_libraries(GraphicLib ${CONAN_LIBS})
target_include_directories(GraphicLib PUBLIC headers)
