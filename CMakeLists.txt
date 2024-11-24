cmake_minimum_required(VERSION 3.28)
project(KeyboardProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(KeyboardProject main.cpp
        keyboard.h
        keyboard.cpp
        Sound.cpp
        Sound.h
)

set(CMAKE_PREFIX_PATH SFML "C:/Programming-Gustavo/vcpkg/installed/x64-mingw-dynamic/share/sfml")
find_package(SFML COMPONENTS #[[system]] audio graphics window CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
#[[find_package(GLU REQUIRED)]]
target_link_libraries(KeyboardProject PRIVATE #[[sfml-system sfml-network]] sfml-audio sfml-graphics sfml-window OpenGL::GL
                        #[[GLU::GLU]])

#Not used currently
#set(CMAKE_PREFIX_PATH Im-Gui-SFML "C:/Programming-Gustavo/vcpkg/installed/x64-mingw-dynamic/share/imgui")
#find_package(ImGui-SFML CONFIG REQUIRED)
#target_link_libraries(KeyboardProject PRIVATE ImGui-SFML::ImGui-SFML)
#
#set(CMAKE_PREFIX_PATH assimp "C:/Programming-Gustavo/vcpkg/installed/x64-mingw-dynamic/share/assimp")
#find_package(assimp CONFIG REQUIRED)
#target_link_libraries(KeyboardProject PRIVATE assimp::assimp)
