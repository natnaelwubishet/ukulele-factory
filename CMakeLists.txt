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
#if ("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
#    message(FATAL_ERROR "Warning: In-source build! Aborting. Call cmake .. from a build folder.")
#endif("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")

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
# set (EXTRA_LIBS Qt5Widgets Qt5Core QtTest)

# Qt coniguration
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

FIND_PACKAGE(Qt5 COMPONENTS Widgets Core Test Gui)
if (NOT Qt5_FOUND)
    message(FATAL_ERROR "Couldn't find an installed version of Qt
     or qt is not in the default directory.")
endif(NOT Qt5_FOUND)

include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

if(WIN32)
    # Check if we are on Windows
    if(MSVC)
        # Check if we are using the Visual Studio compiler
        set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE YES LINK_FLAGS "/ENTRY:mainCRTStartup" )
    elseif(CMAKE_COMPILER_IS_GNUCXX)
        # SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mwindows") # Not tested
    else()
        message(SEND_ERROR "You are using an unsupported Windows compiler! (Not MSVC or GCC)")
endif(MSVC)
elseif(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES MACOSX_BUNDLE YES )
elseif(UNIX) # Nothing special required
else()
    message(SEND_ERROR "You are on an unsupported platform! (Not Win32, Mac OS X or Unix)")
endif(WIN32)

# project source files
set(SOURCE_FILES ${UKULELE_SOURCE_DIR}/main.cpp
                 ${UKULELE_SOURCE_DIR}/ui/mainwindow.cpp
                 #${UKULELE_LIBRARY_DIR}/ukuleleFactory.cpp ${UKULELE_LIBRARY_DIR}/ukuleleSuppliers.cpp
            )

# setup GUI library
qt_wrap_ui(UKULELE_UI_FILES ${UKULELE_SOURCE_DIR}/ukulele_main.ui)

add_executable(ukuleleFactory ${SOURCE_FILES} includes/ukuleleFactoryConfig.h ${UKULELE_UI_FILES} ${MOC_SRCS})
target_link_libraries(ukuleleFactory ukuleleLib ${QT_LIBRARIES})