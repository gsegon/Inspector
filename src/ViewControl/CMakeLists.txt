
add_library(inspector_view_control STATIC
        ViewControl_ColorSelector.cxx
        ViewControl_MessageDialog.cxx
        ViewControl_PropertyView.cxx
        ViewControl_Table.cxx
        ViewControl_TableItemDelegate.cxx
        ViewControl_TableModel.cxx
        ViewControl_TableModelValues.cxx
        ViewControl_Tools.cxx
)
target_include_directories(inspector_view_control PUBLIC include)

target_link_libraries(inspector_view_control PUBLIC inspector_tree_model)

# Link OCC targets
target_link_libraries(inspector_view_control PRIVATE
        TKernel
#        ${OpenCASCADE_ModelingData_LIBRARIES}
#        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
#        ${OpenCASCADE_DataExchange_LIBRARIES}
#        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
)

# Link QT targets
target_link_libraries(inspector_view_control PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)