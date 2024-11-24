cmake_minimum_required(VERSION 3.28)
project(KeyboardProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(KeyboardProject main.cpp
        keyboard.h
        keyboard.cpp
        Sound.cpp
        Sound.h
)

set(CMAKE_PREFIX_PATH SFML "C:/Users/bloop/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/share/sfml")
find_package(SFML COMPONENTS #[[system]] audio graphics window CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
#[[find_package(GLU REQUIRED)]]
target_link_libraries(KeyboardProject PRIVATE #[[sfml-system sfml-network]] sfml-audio sfml-graphics sfml-window OpenGL::GL
        #[[GLU::GLU]])
