add_executable(TInspector_EXE TInspectorEXE.cxx)
add_definitions (-DHAVE_XLIB)
target_link_libraries(TInspector_EXE PRIVATE inspector_tinspector)

# Link OCC targets
target_link_libraries(TInspector_EXE PRIVATE
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
target_link_libraries(TInspector_EXE PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)




