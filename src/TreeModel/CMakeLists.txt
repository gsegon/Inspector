

# Setup QT resources
set(RESOURCE_FILES_TREE_MODEL
        TreeModel.qrc
)
qt_add_resources(RESOURCES_RCC_TREE_MODEL ${RESOURCE_FILES_TREE_MODEL})

add_library(inspector_tree_model SHARED
        TreeModel_ContextMenu.cxx
        TreeModel_ItemBase.cxx
        TreeModel_ItemProperties.cxx
        TreeModel_ItemStream.cxx
        TreeModel_ModelBase.cxx
        TreeModel_Tools.cxx
        TreeModel_VisibilityState.cxx
        ${RESOURCE_FILES_TREE_MODEL}
        include/inspector/TreeModel_ContextMenu.hxx
)
target_include_directories(inspector_tree_model PUBLIC include)

target_link_libraries(inspector_tree_model PUBLIC view_control_types)
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