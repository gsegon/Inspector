
cmake_minimum_required (VERSION 3.10 FATAL_ERROR)

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
        Widgets )

# Setup QT MOC, RCC and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_library(inspector_convert STATIC
        Convert_Tools.cxx
)

target_include_directories(inspector_convert PUBLIC include)

# Link OCC targets
target_link_libraries(inspector_convert PRIVATE
        TKernel

)

# Link QT targets
target_link_libraries(inspector_convert PRIVATE
        Qt5::Core
#        Qt5::Gui
#        Qt5::Widgets
)