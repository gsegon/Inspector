cmake_minimum_required (VERSION 3.10 FATAL_ERROR)


# Setup QT resources
set(RESOURCE_FILES
        View.qrc
)
qt_add_resources(RESOURCES_RCC ${RESOURCE_FILES})

add_library(inspector_view STATIC
        View_Displayer.cxx
        View_DisplayPreview.cxx
        View_PreviewParameters.cxx
        View_ToolBar.cxx
        View_Viewer.cxx
        View_Widget.cxx
        View_Window.cxx
        ${RESOURCES_RCC}
)
target_include_directories(inspector_view PUBLIC include)

foreach (libr ${OpenCASCADE_FoundationClasses_LIBRARIES})
    message("libr: ${libr}")
endforeach ()

# Link OCC targets
target_link_libraries(inspector_view PRIVATE
        TKernel
)

target_link_libraries(inspector_view PUBLIC inspector_view_control)

# Link QT targets
target_link_libraries(inspector_view PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)