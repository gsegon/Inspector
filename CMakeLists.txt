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


# Set RPATH settings at the beginning of your top-level CMakeLists.txt
# Make sure executables can find libraries after installation
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# Add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Add src
add_subdirectory(src)

# Add app
add_subdirectory(app)

# Install config
include(Install.cmake)