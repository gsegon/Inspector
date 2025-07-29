
# Create the interface library
add_library(view_control_types INTERFACE)
target_include_directories(view_control_types INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>/include")

file(GLOB_RECURSE INSPECTOR_HEADERS
        "include/inspector/*.hxx"
)

add_library(view_control STATIC
        ViewControl_ColorSelector.cxx
        ViewControl_MessageDialog.cxx
        ViewControl_PropertyView.cxx
        ViewControl_Table.cxx
        ViewControl_TableItemDelegate.cxx
        ViewControl_TableModel.cxx
        ViewControl_TableModelValues.cxx
        ViewControl_Tools.cxx
        ${INSPECTOR_HEADERS}    # Added to force MOC processing headers
)
target_include_directories(view_control INTERFACE
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_link_libraries(view_control INTERFACE view_control_types)
target_link_libraries(view_control PUBLIC tree_model)

# Link OCC targets
target_link_libraries(view_control PUBLIC
        TKernel
#        ${OpenCASCADE_ModelingData_LIBRARIES}
#        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
#        ${OpenCASCADE_DataExchange_LIBRARIES}
#        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
)

# Link QT targets


message("QtX: ${QtX}")
target_link_libraries(view_control PUBLIC
        ${QtX}::Core
        ${QtX}::Gui
        ${QtX}::Widgets
)