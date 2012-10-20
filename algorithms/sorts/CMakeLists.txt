set(TARGET_FILE_NAME "x")
#define_property(VARIABLE "TARGET_FILE_NAME")

cmake_minimum_required(VERSION 2.6)

project(${TARGET_FILE_NAME})

if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

set(CMAKE_DEBUG_POSTFIX "_d")

set(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_BINARY_DIR}")

include_directories("./")

set(HDRS
    heap.h
    heap_sort.h
    quick_sort.h
    radix_sort.h
)

set(SRCS
    ./main.cpp
)

add_executable(${TARGET_FILE_NAME} WIN32 ${HDRS} ${SRCS})

set_target_properties(${TARGET_FILE_NAME} PROPERTIES DEBUG_POSTFIX _d)

target_link_libraries(${TARGET_FILE_NAME})

#file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../bin)

if(UNIX)
	set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})
endif(UNIX)

if(UNIX)

	install(TARGETS ${TARGET_FILE_NAME}
		RUNTIME DESTINATION bin
		CONFIGURATIONS All)

	ADD_CUSTOM_TARGET (distclean @echo cleaning for source distribution)
	SET(DISTCLEANED
        CMakeFiles
		cmake.depends
		cmake.check_depends
		CMakeCache.txt
		cmake.check_cache
		*.cmake
		Makefile
		core core.*
		gmon.out
		*~
	)

	ADD_CUSTOM_COMMAND(
		DEPENDS clean
		COMMENT "distribution clean"
		COMMAND rm
		ARGS -Rf CMakeTmp ${DISTCLEANED}
		TARGET distclean
	)

endif(UNIX)
