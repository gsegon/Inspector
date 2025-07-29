cmake_minimum_required(VERSION 3.30)
project(SomeInspectedApp)

set(CMAKE_CXX_STANDARD 20)

find_package(Inspector REQUIRED)

add_executable(SomeInspectedApp main.cpp)

target_link_libraries(SomeInspectedApp PUBLIC OCCInspector::inspector)

target_link_libraries(SomeInspectedApp PRIVATE
        ${OpenCASCADE_FoundationClasses_LIBRARIES}
        ${OpenCASCADE_ModelingData_LIBRARIES}
        ${OpenCASCADE_ModelingAlgorithms_LIBRARIES}
        ${OpenCASCADE_DataExchange_LIBRARIES}
        ${OpenCASCADE_ApplicationFramework_LIBRARIES}
)