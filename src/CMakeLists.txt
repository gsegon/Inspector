cmake_minimum_required (VERSION 3.10 FATAL_ERROR)
project(Inspector)

# Find OpenCASCADE
if(OpenCASCADE_DIR)
    find_package(OpenCASCADE REQUIRED PATHS ${OpenCASCADE_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCASCADE REQUIRED)
endif()

# Find QT
find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        Xml)

# Setup QT MOC, RCC and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(TInspector)
add_subdirectory(TInspectorAPI)
add_subdirectory(Convert)
add_subdirectory(TreeModel)
add_subdirectory(View)
add_subdirectory(ViewControl)

add_subdirectory(TInspectorEXE)

add_subdirectory(DFBrowserPane)
add_subdirectory(DFBrowser)