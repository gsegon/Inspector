# Setup QT resources
set(RESOURCE_FILES_SHAPE_VIEW
        ShapeView.qrc
)
qt_add_resources(RESOURCES_RCC_SHAPE_VIEW ${RESOURCE_FILES_SHAPE_VIEW})

file(GLOB_RECURSE SHAPE_VIEW_HEADERS
        "include/inspector/*.hxx"
)


add_library(TKShapeView SHARED
        ShapeView_Communicator.cxx
        ShapeView_ItemRoot.cxx
        ShapeView_ItemShape.cxx
        ShapeView_OpenFileDialog.cxx
        ShapeView_OpenFileViewModel.cxx
        ShapeView_Tools.cxx
        ShapeView_TreeModel.cxx
        ShapeView_VisibilityState.cxx
        ShapeView_Window.cxx
        ${RESOURCES_RCC_SHAPE_VIEW}
        ${SHAPE_VIEW_HEADERS}    # Added to force MOC processing headers

)
target_include_directories(TKShapeView PUBLIC include)

target_link_libraries(TKShapeView PUBLIC plugin_api)
target_link_libraries(TKShapeView PRIVATE tree_model)
target_link_libraries(TKShapeView PRIVATE view)

# Link OCC targets
target_link_libraries(TKShapeView PRIVATE
        TKernel
#        ${OpenCASCADE_ModelingData_LIBRARIES}
#        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
        TKOpenGl

)

#target_link_libraries(TKDFBrowser PUBLIC OpenGL)

# Link QT targets
target_link_libraries(TKShapeView PRIVATE
        Qt5::Core
        Qt5::Widgets
)