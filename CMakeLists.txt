cmake_minimum_required(VERSION 2.8.11)

project(ukuleleFactory)

# Version info
set (ukuleleFactory_VERSION_MAJOR 1)
set (ukuleleFactory_VERSION_MINOR 0)

# set project directories
set(UKULELE_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(UKULELE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/includes")
set(UKULELE_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/libs")

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${UKULELE_INCLUDE_DIR}/ukuleleFactoryConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find ukuleleFactoryConfig.h
include_directories("${PROJECT_BINARY_DIR}")
add_subdirectory (libs)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

# compiler options
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES *.cpp)
set (EXTRA_LIBS Qt5Widgets)

# windows configuration
if (WIN32)
    # set qt directory
    message(CMAKE_PREFIX_PATH)
endif(WIN32)
FIND_PACKAGE(Qt5Widgets)

# add the install targets
# install (TARGETS ukuleleFactory DESTINATION bin)
# install (FILES "${PROJECT_BINARY_DIR}/ukuleleFactoryConfig.h"
        DESTINATION include)

qt_wrap_ui(UKULELE_FACTORY_UI_H
           ${PROJECT_SOURCE_DIR}/mainwindow.ui
        )

add_executable(ukuleleFactory $(SOURCE_FILES) includes/ukuleleFactoryConfig.h)
target_link_libraries(ukuleleFactory libs)