# Find OpenCASCADE
if(OpenCASCADE_DIR)
    find_package(OpenCASCADE REQUIRED PATHS ${OpenCASCADE_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCASCADE REQUIRED)
endif()

# Setup QT resources
set(RESOURCE_FILES_TINSPECTOR
        TInspector.qrc
)
qt_add_resources(RESOURCES_RCC_TINSPECTOR ${RESOURCE_FILES_TINSPECTOR})



add_library(inspector SHARED
        TInspector_Communicator.cxx
        TInspector_OpenButton.cxx
        TInspector_OpenFileDialog.cxx
        TInspector_OpenFileViewModel.cxx
        TInspector_PluginParameters.cxx
        TInspector_Preferences.cxx
        TInspector_Shortcut.cxx
        TInspector_Window.cxx
        ${RESOURCES_RCC_TINSPECTOR}
        include/inspector/TInspector_OpenButton.hxx
        include/inspector/TInspector_Window.hxx
        include/inspector/TInspector_OpenFileDialog.hxx

)

# Set RPATH for the build tree
set_target_properties(inspector PROPERTIES
        BUILD_WITH_INSTALL_RPATH FALSE
        SKIP_BUILD_RPATH FALSE
)

target_include_directories(inspector PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_link_libraries(inspector PUBLIC plugin_api)
target_link_libraries(inspector PRIVATE view)

install(DIRECTORY include/
        DESTINATION include)


# Link OCC targets
target_link_libraries(inspector PRIVATE
        ${OpenCASCADE_FoundationClasses_LIBRARIES}
        ${OpenCASCADE_ModelingData_LIBRARIES}
        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
)

# Link QT targets
target_link_libraries(inspector PUBLIC
        ${QtX}::Core
        ${QtX}::Gui
        ${QtX}::Widgets
        ${QtX}::Xml
)


