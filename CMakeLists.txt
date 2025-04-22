cmake_minimum_required(VERSION 3.25)
project(EditorImagem)

include(${CMAKE_BINARY_DIR}/conan/conan_toolchain.cmake)

set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_STANDARD 17)

include(srcfiles.cmake)

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)
find_package(imgui 1.91.8)
find_package(ImGui-SFML)
find_package(Qt6 COMPONENTS OpenGLWidgets UiTools Gui Core Widgets  REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE 
                        ${CMAKE_SOURCE_DIR}/dependencies
                        ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(${PROJECT_NAME} 
sfml-graphics sfml-window 
sfml-system imgui::imgui
ImGui-SFML::ImGui-SFML
Qt6::Widgets
Qt6::OpenGL
Qt6::Core
Qt6::Gui
Qt6::UiTools
Qt6::OpenGLWidgets
)
