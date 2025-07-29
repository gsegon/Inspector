cmake_minimum_required(VERSION 3.30)
project(Inspector VERSION 0.1.0 LANGUAGES CXX)

# Find OpenCASCADE
if(OpenCASCADE_DIR)
    find_package(OpenCASCADE REQUIRED PATHS ${OpenCASCADE_DIR} NO_DEFAULT_PATH)
else()
    find_package(OpenCASCADE REQUIRED)
endif()

# Find QT
find_package(Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        Xml)

set(CMAKE_CXX_STANDARD 20)
# Setup QT MOC, RCC and UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_EXTENSIONS ".h;.hh;.hpp;.hxx;.cxx;.cpp;.cc")
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC_DEPENDENCY_SCAN ON)


# Set RPATH settings at the beginning of your top-level CMakeLists.txt
# Make sure executables can find libraries after installation
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# Add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# Add src
add_subdirectory(src)

# Add app
add_subdirectory(app)

# Install
# Define output directories for build files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(GNUInstallDirs)
install(
        TARGETS TKDFBrowser view plugin_api tree_model view_control view_control_types convert inspector
        EXPORT ${PROJECT_NAME}Targets
        ARCHIVE PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        INCLUDES DESTINATION include)

install(EXPORT ${PROJECT_NAME}Targets
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
        NAMESPACE OCCInspector::
)

include(CMakePackageConfigHelpers)
set(LIB_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR})
configure_package_config_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake
        PATH_VARS LIB_INSTALL_DIR
)

write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        COMPATIBILITY AnyNewerVersion
)

install(FILES   "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake)