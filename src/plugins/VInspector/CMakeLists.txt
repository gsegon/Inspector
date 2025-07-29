# Setup QT resources
set(RESOURCE_FILES_VINSPECTOR
        VInspector.qrc
)
qt_add_resources(RESOURCES_RCC_VINSPECTOR ${RESOURCE_FILES_VINSPECTOR})

file(GLOB_RECURSE INSPECTOR_HEADERS_VINSPECTOR
        "include/inspector/*.hxx"
)

add_library(TKVInspector SHARED

        VInspector_Communicator.cxx
        VInspector_ItemBase.cxx
        VInspector_ItemContext.cxx
        VInspector_ItemContextProperties.cxx
        VInspector_ItemGraphic3dCLight.cxx
        VInspector_ItemPresentableObject.cxx
        VInspector_ItemSelectMgrViewerSelector.cxx
        VInspector_ItemV3dViewer.cxx
        VInspector_ToolBar.cxx
        VInspector_Tools.cxx
        VInspector_ViewModel.cxx
        VInspector_Window.cxx

        ${RESOURCES_RCC_VINSPECTOR}
        ${INSPECTOR_HEADERS_VINSPECTOR}    # Added to force MOC processing headers
)

target_include_directories(TKVInspector PUBLIC include)

target_link_libraries(TKVInspector PUBLIC plugin_api)
target_link_libraries(TKVInspector PRIVATE view)

# Link OCC targets
target_link_libraries(TKVInspector PRIVATE
        TKernel
#        ${OpenCASCADE_ModelingData_LIBRARIES}
#        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
        TKOpenGl

)

#target_link_libraries(TKDFBrowser PUBLIC OpenGL)

# Link QT targets
target_link_libraries(TKVInspector PRIVATE
        Qt6::Core
        Qt6::Widgets
)