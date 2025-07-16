# Find OpenCASCADE
if(OpenCASCADE_DIR)
    find_package(OpenCASCADE REQUIRED PATHS ${OpenCASCADE_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCASCADE REQUIRED)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_library(inspector_tinspector_api
        TInspectorAPI_Communicator.cxx
        TInspectorAPI_PluginParameters.cxx
)
target_include_directories(inspector_tinspector_api PUBLIC include)


# Link OCC targets
target_link_libraries(inspector_tinspector_api PRIVATE
        TKernel
)
