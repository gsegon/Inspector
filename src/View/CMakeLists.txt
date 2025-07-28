# Setup QT resources
set(RESOURCE_FILES
        View.qrc
)
qt_add_resources(RESOURCES_RCC ${RESOURCE_FILES})

file(GLOB_RECURSE INSPECTOR_HEADERS
        "include/inspector/*.hxx"
)

add_library(view

        View_Displayer.cxx
        View_DisplayPreview.cxx
        View_PreviewParameters.cxx
        View_ToolBar.cxx
        View_Viewer.cxx
        View_Widget.cxx
        View_Window.cxx
        ${RESOURCES_RCC}
        ${INSPECTOR_HEADERS}    # Added to force MOC processing headers
)
target_include_directories(view PUBLIC include)

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
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)


add_subdirectory(GTest)