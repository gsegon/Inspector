# Setup QT resources
set(RESOURCE_FILES_MESSAGE_MODEL
        MessageModel.qrc
)
qt_add_resources(RESOURCES_RCC_MESSAGE_MODEL ${RESOURCE_FILES_MESSAGE_MODEL})

file(GLOB_RECURSE MESSAGE_MODEL_HEADERS
        "include/inspector/*.hxx"
)

add_library(TKMessageModel SHARED
        MessageModel_Actions.cxx
        MessageModel_ItemAlert.cxx
        MessageModel_ItemBase.cxx
        MessageModel_ItemReport.cxx
        MessageModel_ItemRoot.cxx
        MessageModel_TreeModel.cxx
        ${MESSAGE_MODEL_HEADERS}    # Added to force MOC processing headers
        ${RESOURCES_RCC_MESSAGE_MODEL}
)
target_include_directories(TKMessageModel PUBLIC include)

target_link_libraries(TKMessageModel PUBLIC plugin_api)
target_link_libraries(TKMessageModel PRIVATE inspector_tree_model)
#target_link_libraries(TKMessageModel PRIVATE view)

# Link OCC targets
target_link_libraries(TKMessageModel PRIVATE
        TKernel
#        ${OpenCASCADE_ModelingData_LIBRARIES}
#        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
        TKOpenGl

)

#target_link_libraries(TKDFBrowser PUBLIC OpenGL)

# Link QT targets
target_link_libraries(TKMessageModel PRIVATE
        Qt5::Core
        Qt5::Widgets
)