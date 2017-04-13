cmake_minimum_required(VERSION 2.8.11)

project(ukuleleFactory)

# Version info
set (ukuleleFactory_VERSION_MAJOR 1)
set (ukuleleFactory_VERSION_MINOR 0)

# set project directories
set(UKULELE_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(UKULELE_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/includes")
set(UKULELE_LIBRARY_DIR "${PROJECT_SOURCE_DIR}/libs")
set(UKULELE_TEST_DIR "${PROJECT_SOURCE_DIR}/tests")

# Avoid in-source builds
if ("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "Warning: In-source build! Aborting. Call cmake .. from a build folder.")
endif()

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${UKULELE_INCLUDE_DIR}/ukuleleFactoryConfig.h"
  "${UKULELE_BINARY_DIR}/ukuleleFactoryConfig.h.in"
  )

# add the binary tree to the search path for include files
# so that we will find ukuleleFactoryConfig.h
include_directories("${PROJECT_BINARY_DIR}")
add_subdirectory (libs)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# compiler options
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(SOURCE_FILES *.cpp)
set (EXTRA_LIBS Qt5Widgets)

# Qt coniguration
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "E:/qt install/5.8/msvc2013_64/lib/cmake/Qt5")
FIND_PACKAGE(Qt5 COMPONENTS Widgets Core)
#if (Qt5_FOUND)
#else()
#    if (WIN32)
#        message("Couldn't find Qt in the default location. Go to qt installation folder.")
#        set(POWERSHELL_CMD ./get_module_dir.ps1)
# TODO: Fix execution of powershell from cmake
#        execute_process(
#                COMMAND powershell ${POWERSHELL_CMD}
#        )
#        FIND_PACKAGE(Qt5 COMPONENTS Widgets Core)
#    endif()
#endif()
include_directories(${INCLUDE_DIRECTORIES} ${QT_INCLUDE_DIR})
# include(${QT_USE_FILE})


# add the install targets
# install (TARGETS ukuleleFactory DESTINATION bin)
# install (FILES "${PROJECT_BINARY_DIR}/ukuleleFactoryConfig.h"
#        DESTINATION include)

#qt_wrap_ui(UKULELE_FACTORY_UI_H
#           ${PROJECT_SOURCE_DIR}/mainwindow.ui
#        )

# project source files
# TODO: Fix SOURCE_FILES problem!
set(SOURCE_FILES ${UKULELE_SOURCE_DIR}/main.cpp
                ${UKULELE_SOURCE_DIR}/mainwindow.cpp)


# TODO: fix qt_wrap_ui problems, Probable cause: Usage
#qt_wrap_ui(UKULELE_UI_FILES
#        ${UKULELE_SOURCE_DIR}/ukulele_main.ui)

add_executable(ukuleleFactory $(SOURCE_FILES) includes/ukuleleFactoryConfig.h)
target_link_libraries(ukuleleFactory libs)