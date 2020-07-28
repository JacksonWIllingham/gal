cmake_minimum_required(VERSION 3.5)

project(main)

add_subdirectory(3rdparty)

add_library(gal STATIC
	include/gal/gal.hpp
	src/gal.cpp
)

target_include_directories(gal
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
        #${GLAD_INCLUDES}
        #${GLFW_INCLUDES}
        ${IMGUI_INCLUDES}
        #${GLM_INCLUDES}
)

#enable_testing()