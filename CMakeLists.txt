cmake_minimum_required(VERSION 3.25)
project(EditorImagem)

include(${CMAKE_BINARY_DIR}/conan/conan_toolchain.cmake)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)
find_package(imgui 1.91.8)
find_package(ImGui-SFML)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window 
                                    sfml-system imgui::imgui
                                    ImGui-SFML::ImGui-SFML)

