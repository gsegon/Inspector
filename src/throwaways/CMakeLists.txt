add_executable(tw_AIS
        OCCTOpenGLViewer.cpp
)

# Link OCC targets
target_link_libraries(tw_AIS PRIVATE
        TKernel
        #        ${OpenCASCADE_ModelingData_LIBRARIES}
        #        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
        TKOpenGl

)

#target_link_libraries(TKDFBrowser PUBLIC OpenGL)

# Link QT targets
target_link_libraries(tw_AIS PRIVATE
        Qt5::Core
        Qt5::Widgets
)