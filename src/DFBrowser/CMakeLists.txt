cmake_minimum_required (VERSION 3.10 FATAL_ERROR)

# Setup QT resources
set(RESOURCE_FILES
        DFBrowser.qrc
)
qt_add_resources(RESOURCES_RCC ${RESOURCE_FILES})

add_library(dfbrowser SHARED
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
)
target_include_directories(dfbrowser PUBLIC include)

target_link_libraries(dfbrowser PUBLIC inspector_tinspector_api)
target_link_libraries(dfbrowser PRIVATE inspector_tree_model)

target_link_libraries(dfbrowser PRIVATE dfbrowser_pane)
target_link_libraries(dfbrowser PRIVATE inspector_view_control)
target_link_libraries(dfbrowser PRIVATE inspector_view)

# Link OCC targets
target_link_libraries(dfbrowser PRIVATE
        TKernel
)

# Link QT targets
target_link_libraries(dfbrowser PRIVATE
        Qt5::Core
        Qt5::Widgets
)