add_subdirectory(MessageModel)

file(GLOB_RECURSE MESSAGE_VIEW_HEADERS
        "include/inspector/*.hxx"
)

add_library(TKMessageView SHARED
        MessageView_ActionsTest.cxx
        MessageView_Communicator.cxx
        MessageView_MetricStatisticModel.cxx
        MessageView_VisibilityState.cxx
        MessageView_Window.cxx
        ${MESSAGE_VIEW_HEADERS}    # Added to force MOC processing headers
)
target_include_directories(TKMessageView PUBLIC include)

target_link_libraries(TKMessageView PUBLIC plugin_api)
target_link_libraries(TKMessageView PRIVATE tree_model)
target_link_libraries(TKMessageView PRIVATE TKMessageModel)
target_link_libraries(TKMessageView PRIVATE view)

# Link OCC targets
target_link_libraries(TKMessageView PRIVATE
        TKernel
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
        TKOpenGl

)

# Link QT targets
target_link_libraries(TKMessageView PRIVATE
        ${QtX}::Core
        ${QtX}::Widgets
)