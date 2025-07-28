# Find OpenCASCADE
if(OpenCASCADE_DIR)
    find_package(OpenCASCADE REQUIRED PATHS ${OpenCASCADE_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCASCADE REQUIRED)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(plugin_api
        PluginAPI_Communicator.cxx
        PluginAPI_PluginParameters.cxx
)
target_include_directories(plugin_api PUBLIC include)

# Link OCC targets
target_link_libraries(plugin_api PRIVATE
        TKernel
)
