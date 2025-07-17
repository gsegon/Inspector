# Find OpenCASCADE
if(OpenCASCADE_DIR)
    find_package(OpenCASCADE REQUIRED PATHS ${OpenCASCADE_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCASCADE REQUIRED)
endif()

## Find QT
#find_package(Qt5 REQUIRED COMPONENTS
#        Core
#        Gui
#        Widgets
#        Xml)
#
## Setup QT MOC, RCC and UIC
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

# Setup QT resources
set(RESOURCE_FILES
        TInspector.qrc
)
qt_add_resources(RESOURCES_RCC ${RESOURCE_FILES})

add_library(inspector_tinspector SHARED
        TInspector_Communicator.cxx
        TInspector_OpenButton.cxx
        TInspector_OpenFileDialog.cxx
        TInspector_OpenFileViewModel.cxx
        TInspector_PluginParameters.cxx
        TInspector_Preferences.cxx
        TInspector_Shortcut.cxx
        TInspector_Window.cxx
        ${RESOURCE_FILES}
        include/inspector/TInspector_OpenButton.hxx
        include/inspector/TInspector_Window.hxx
        include/inspector/TInspector_OpenFileDialog.hxx

)

target_include_directories(inspector_tinspector PUBLIC include)

target_link_libraries(inspector_tinspector PUBLIC inspector_tinspector_api)
target_link_libraries(inspector_tinspector PRIVATE inspector_view)



# Link OCC targets
target_link_libraries(inspector_tinspector PRIVATE
        ${OpenCASCADE_FoundationClasses_LIBRARIES}
        ${OpenCASCADE_ModelingData_LIBRARIES}
        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}

)

# Link QT targets
target_link_libraries(inspector_tinspector PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Xml
)


