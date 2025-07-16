add_executable(TInspector_EXE TInspectorEXE.cxx)

target_link_libraries(TInspector_EXE PRIVATE inspector_tinspector)

# Link OCC targets
target_link_libraries(TInspector_EXE PRIVATE
        TKernel
)

# Link QT targets
target_link_libraries(TInspector_EXE PRIVATE
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
)




