
find_package(GTest REQUIRED)

add_executable(test_View

        test_View_Window.cxx
)

target_link_libraries(test_View PRIVATE GTest::gtest_main view view_control tree_model)

target_link_libraries(test_View PRIVATE
        TKernel
        #        ${OpenCASCADE_ModelingData_LIBRARIES}
        #        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
        TKOpenGl

)