
add_executable(AppInspector
        AppInspector.cxx)

# Set RPATH for the build tree
set_target_properties(AppInspector PROPERTIES
        BUILD_WITH_INSTALL_RPATH FALSE
        SKIP_BUILD_RPATH FALSE
)

target_link_libraries(AppInspector PUBLIC inspector)

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
        ${QtX}::Core
        ${QtX}::Gui
        ${QtX}::Widgets
)




