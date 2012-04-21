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

# Find Boost
#set(Boost_ADDITIONAL_VERSIONS "1.44" "1.44.0" "1.42" "1.42.0" "1.41.0" "1.41" "1.40.0" "1.40" "1.39.0" "1.39" "1.38.0" "1.38" "1.37.0" "1.37" )
# Components that need linking (NB does not include header-only components like bind)
if (NOT Boost_FOUND)
        # Try again with the other type of libs
        set(Boost_USE_STATIC_LIBS NOT ${Boost_USE_STATIC_LIBS})
endif()
find_package(Boost QUIET)

# Set up referencing of Boost
#include_directories(${Boost_INCLUDE_DIR})
include_directories("~/programming/boost/boost_1_46_1/")
add_definitions(-DBOOST_ALL_NO_LIB)
 
set(HDRS
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
