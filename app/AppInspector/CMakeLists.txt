
add_executable(AppInspector
        AppInspector.cxx)

add_definitions (-DHAVE_XLIB)
target_link_libraries(AppInspector PRIVATE inspector)

# Link OCC targets
target_link_libraries(AppInspector PRIVATE
        TKernel
        TKService
        TKOpenGl
        ${OpenCASCADE_FoundationClasses_LIBRARIES}
        ${OpenCASCADE_ModelingData_LIBRARIES}
        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}

)

# Link QT targets
target_link_libraries(AppInspector PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)




