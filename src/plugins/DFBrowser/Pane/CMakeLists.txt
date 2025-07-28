
file(GLOB_RECURSE INSPECTOR_HEADERS
        "include/inspector/*.hxx"
)

add_library(dfbrowser_pane
        DFBrowserPane_AttributePane.cxx
        DFBrowserPane_AttributePaneCreator.cxx
        DFBrowserPane_AttributePaneModel.cxx
        DFBrowserPane_AttributePaneSelector.cxx
        DFBrowserPane_HelperArray.cxx
        DFBrowserPane_HelperExport.cxx
        DFBrowserPane_ItemDelegateButton.cxx
        DFBrowserPane_TableView.cxx
        DFBrowserPane_TDataStdReferenceArray.cxx
        DFBrowserPane_TDataStdReferenceList.cxx
        DFBrowserPane_TDataStdTreeNode.cxx
        DFBrowserPane_TDataStdTreeNodeItem.cxx
        DFBrowserPane_TDataStdTreeNodeModel.cxx
        DFBrowserPane_TDFReference.cxx
        DFBrowserPane_TNamingNamedShape.cxx
        DFBrowserPane_TNamingNaming.cxx
        DFBrowserPane_TNamingUsedShapes.cxx
        DFBrowserPane_Tools.cxx
        ${INSPECTOR_HEADERS}            # Added to force MOC processing the headers
)


target_include_directories(dfbrowser_pane PUBLIC include)

target_link_libraries(dfbrowser_pane PRIVATE plugin_api)
target_link_libraries(dfbrowser_pane PRIVATE inspector_tree_model)


# Link OCC targets
target_link_libraries(dfbrowser_pane PRIVATE
        TKernel
)

# Link QT targets
target_link_libraries(dfbrowser_pane PRIVATE
        Qt5::Core
        Qt5::Widgets
)