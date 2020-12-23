cmake_minimum_required(VERSION 3.17)
project(SFML_ShootEmUp)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "./SFML-2.5.1/build")


set(SOURCE ${CMAKE_SOURCE_DIR}/source/main.cpp
           ${CMAKE_SOURCE_DIR}/source/Game.cpp
           ${CMAKE_SOURCE_DIR}/source/Game.hpp)


add_executable(${PROJECT_NAME} ${SOURCE})
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
target_link_libraries (SFML_ShootEmUp sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
