add_subdirectory(view_control)

# Setup QT resources
set(RESOURCE_FILES_VIEW
        View.qrc
)
qt_add_resources(RESOURCES_RCC_VIEW ${RESOURCE_FILES_VIEW})

file(GLOB_RECURSE INSPECTOR_HEADERS
        "include/inspector/*.hxx"
)

message("RESOURCES_RCC_VIEW: ${RESOURCES_RCC_VIEW}")

add_library(view SHARED
        ${RESOURCES_RCC_VIEW}
        ${INSPECTOR_HEADERS}    # Added to force MOC processing headers
        View_Displayer.cxx
        View_DisplayPreview.cxx
        View_PreviewParameters.cxx
        View_ToolBar.cxx
        View_Viewer.cxx
        View_Widget.cxx
        View_Window.cxx

)

target_include_directories(view PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

foreach (libr ${OpenCASCADE_FoundationClasses_LIBRARIES})
    message("libr: ${libr}")
endforeach ()

# Link OCC targets
target_link_libraries(view PUBLIC
        TKernel
)

target_link_libraries(view PUBLIC view_control)

# Link QT targets
target_link_libraries(view PUBLIC
        ${QtX}::Core
        ${QtX}::Gui
        ${QtX}::Widgets
        ${QtX}::Xml
)

add_subdirectory(GTest)