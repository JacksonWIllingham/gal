project(3rdparty)

set(HEADER_FILES
	imgui/imconfig.h
	imgui/imgui.h
	imgui/imgui_internal.h
	imgui/imstb_rectpack.h
	imgui/imstb_textedit.h
	imgui/imstb_truetype.h
	imgui/examples/imgui_impl_opengl3.h
	imgui/examples/imgui_impl_glfw.h
	)
set(SOURCE_FILES 
	imgui/imgui.cpp
	imgui/imgui_draw.cpp
	imgui/imgui_widgets.cpp
	imgui/examples/imgui_impl_opengl3.cpp
	imgui/examples/imgui_impl_glfw.cpp
	imgui/imgui_demo.cpp
	)

add_library(imgui ${HEADER_FILES} ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/imgui)

set(IMGUI_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR} CACHE STRING "imgui include directory")
