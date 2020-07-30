if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the source code and call cmake from there")
endif ()

cmake_minimum_required(VERSION 3.12)

project(glad)

set(HEADER_FILES
	include/glad/glad.h
	include/KHR/khrplatform.h
	)
set(SOURCE_FILES 
	src/glad.c
	)

add_library(glad ${HEADER_FILES} ${SOURCE_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

IF (INTERNAL_ADD_POSTFIX_EXECUTABLE_NAMES)
			SET_TARGET_PROPERTIES(entt_test PROPERTIES  DEBUG_POSTFIX "_Debug")
			SET_TARGET_PROPERTIES(entt_test PROPERTIES  MINSIZEREL_POSTFIX "_MinsizeRel")
			SET_TARGET_PROPERTIES(entt_test PROPERTIES  RELWITHDEBINFO_POSTFIX "_RelWithDebugInfo")
ENDIF(INTERNAL_ADD_POSTFIX_EXECUTABLE_NAMES)