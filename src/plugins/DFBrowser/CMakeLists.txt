
add_subdirectory(Pane)

# Setup QT resources
set(RESOURCE_FILES
        DFBrowser.qrc
)
qt_add_resources(RESOURCES_RCC ${RESOURCE_FILES})

file(GLOB_RECURSE INSPECTOR_HEADERS
        "include/inspector/*.hxx"
)

add_library(TKDFBrowser SHARED
        DFBrowser_AttributePaneStack.cxx
        DFBrowser_Communicator.cxx
        DFBrowser_DumpView.cxx
        DFBrowser_HighlightDelegate.cxx
        DFBrowser_Item.cxx
        DFBrowser_ItemApplication.cxx
        DFBrowser_ItemBase.cxx
        DFBrowser_ItemDocument.cxx
        DFBrowser_Module.cxx
        DFBrowser_OpenApplication.cxx
        DFBrowser_PropertyPanel.cxx
        DFBrowser_SearchLine.cxx
        DFBrowser_SearchLineModel.cxx
        DFBrowser_SearchView.cxx
        DFBrowser_Tools.cxx
        DFBrowser_TreeLevelLine.cxx
        DFBrowser_TreeLevelLineDelegate.cxx
        DFBrowser_TreeLevelLineModel.cxx
        DFBrowser_TreeLevelView.cxx
        DFBrowser_TreeLevelViewModel.cxx
        DFBrowser_TreeModel.cxx
        DFBrowser_Window.cxx
        ${RESOURCES_RCC}
        ${INSPECTOR_HEADERS}    # Added to force MOC processing headers

)
#target_include_directories(TKDFBrowser PUBLIC include)

target_link_libraries(TKDFBrowser PUBLIC plugin_api)
target_link_libraries(TKDFBrowser PRIVATE tree_model)

target_link_libraries(TKDFBrowser PRIVATE dfbrowser_pane)
target_link_libraries(TKDFBrowser PRIVATE view_control)
target_link_libraries(TKDFBrowser PRIVATE view)

## Set RPATH for the build tree
#set_target_properties(TKDFBrowser PROPERTIES
#        BUILD_WITH_INSTALL_RPATH FALSE
#        SKIP_BUILD_RPATH FALSE
#)

target_include_directories(TKDFBrowser PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

# Link OCC targets
target_link_libraries(TKDFBrowser PRIVATE
        TKernel
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
        TKOpenGl
)



# Link QT targets
target_link_libraries(TKDFBrowser PRIVATE
        ${QtX}::Core
        ${QtX}::Widgets
)