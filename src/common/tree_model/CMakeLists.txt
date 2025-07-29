
add_subdirectory(convert)

# Setup QT resources
set(RESOURCE_FILES_TREE_MODEL
        TreeModel.qrc
)
qt_add_resources(RESOURCES_RCC_TREE_MODEL ${RESOURCE_FILES_TREE_MODEL})

add_library(tree_model SHARED
        TreeModel_ContextMenu.cxx
        TreeModel_ItemBase.cxx
        TreeModel_ItemProperties.cxx
        TreeModel_ItemStream.cxx
        TreeModel_ModelBase.cxx
        TreeModel_Tools.cxx
        TreeModel_VisibilityState.cxx
        ${RESOURCES_RCC_TREE_MODEL}
        include/inspector/TreeModel_ContextMenu.hxx
)
target_include_directories(tree_model PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_link_libraries(tree_model PUBLIC view_control_types)
target_link_libraries(tree_model PUBLIC convert)

# Link OCC targets
target_link_libraries(tree_model PRIVATE
        TKernel
)

# Link QT targets
target_link_libraries(tree_model PRIVATE
        Qt5::Core
        Qt5::Widgets
)