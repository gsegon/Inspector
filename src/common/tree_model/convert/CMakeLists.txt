
cmake_minimum_required (VERSION 3.10 FATAL_ERROR)

# Find OpenCASCADE
if(OpenCASCADE_DIR)
    find_package(OpenCASCADE REQUIRED PATHS ${OpenCASCADE_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCASCADE REQUIRED)
endif()

## Find QT
#find_package(${QtX} REQUIRED COMPONENTS
#        Core
#        Gui
#        Widgets )

# Setup QT MOC, RCC and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_library(convert STATIC
        Convert_Tools.cxx
)
set_target_properties(convert PROPERTIES POSITION_INDEPENDENT_CODE ON)


target_include_directories(convert PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

# Link OCC targets
target_link_libraries(convert PRIVATE
        TKernel
)

# Link QT targets
target_link_libraries(convert PRIVATE
        ${QtX}::Core

)