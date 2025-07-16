cmake_minimum_required (VERSION 3.10 FATAL_ERROR)

# Setup QT resources
set(RESOURCE_FILES
        TreeModel.qrc
)
qt_add_resources(RESOURCES_RCC ${RESOURCE_FILES})

add_library(inspector_tree_model STATIC
        TreeModel_ContextMenu.cxx
        TreeModel_ItemBase.cxx
        TreeModel_ItemProperties.cxx
        TreeModel_ItemStream.cxx
        TreeModel_ModelBase.cxx
        TreeModel_Tools.cxx
        TreeModel_VisibilityState.cxx
        ${RESOURCES_RCC}
)
target_include_directories(inspector_tree_model PUBLIC include)

target_link_libraries(inspector_tree_model PRIVATE inspector_view_control)
target_link_libraries(inspector_tree_model PUBLIC inspector_convert)

# Link OCC targets
target_link_libraries(inspector_tree_model PRIVATE
        TKernel
)

# Link QT targets
target_link_libraries(inspector_tree_model PRIVATE
        Qt5::Core
        Qt5::Widgets
)