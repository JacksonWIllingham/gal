cmake_minimum_required(VERSION 3.5)

project(main)

add_subdirectory(3rdparty)

add_library(gal STATIC
	include/gal/gal.hpp
	src/gal.cpp
	include/gal/inputs.hpp
	include/gal/window.hpp
	src/window.cpp
	include/gal/shader.hpp
	src/shader.cpp
	include/gal/context.hpp
	src/context.cpp
	include/gal/gui/components.hpp
	src/components.cpp
	include/gal/gui/guicontroller.hpp
	src/guicontroller.cpp
	include/gal/gui/guiwindow.hpp
	src/guiwindow.cpp
	include/gal/mesh.hpp
	src/mesh.cpp
	include/gal/framebuffer.hpp
	src/framebuffer.cpp
	include/gal/texture.hpp
	src/texture.cpp
	include/gal/camera.hpp
	src/camera.cpp
)
set_property(TARGET gal PROPERTY CXX_STANDARD 17)
set_property(TARGET gal PROPERTY CXX_STANDARD_REQUIRED ON)

target_include_directories(gal
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
        ${GLAD_INCLUDES}
        ${GLFW_INCLUDES}
        ${IMGUI_INCLUDES}
        ${GLM_INCLUDES}
)

target_link_libraries(gal glfw glad opengl32 imgui glm_static) 

#tests
add_executable(gal_tests tests/window.cpp) #${PROJECT_SOURCE_DIR}/3rd_party/catch2/catch.hpp)
set_property(TARGET gal_tests PROPERTY CXX_STANDARD 17)
set_property(TARGET gal_tests PROPERTY CXX_STANDARD_REQUIRED ON)
target_link_libraries(gal_tests gal)
target_include_directories(gal_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/3rdparty/catch2/single_include
        ${PROJECT_SOURCE_DIR}/include
        ${GLAD_INCLUDES}
        ${GLFW_INCLUDES}
        ${IMGUI_INCLUDES}
        ${GLM_INCLUDES}
        ${STB_INCLUDES}
)