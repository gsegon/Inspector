cmake_minimum_required(VERSION 3.30)
project(Inspector VERSION 0.1.0 LANGUAGES CXX)

# Find OpenCASCADE
if(OpenCASCADE_DIR)
    find_package(OpenCASCADE REQUIRED PATHS ${OpenCASCADE_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCASCADE REQUIRED)
endif()

# Find QT
set(QtX "Qt6" CACHE STRING "Qt version to use (Qt5, or Qt6)")
set_property(CACHE QtX PROPERTY STRINGS "Qt5" "Qt6")
message(STATUS "Using Qt version: ${QtX}")

find_package(${QtX} REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        Xml
)

set(CMAKE_CXX_STANDARD 17)
# Setup QT MOC, RCC and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_EXTENSIONS ".h;.hh;.hpp;.hxx;.cxx;.cpp;.cc")
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC_DEPENDENCY_SCAN ON)


set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

# Avoid CMake automatically appending link directories into install RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH FALSE)


# Add src
add_subdirectory(src)

# Add app
add_subdirectory(app)

# RPATH setup
set_target_properties(inspector PROPERTIES
        INSTALL_RPATH "\$ORIGIN"
        BUILD_RPATH "\$ORIGIN"
)


# Install config
include(Install.cmake)