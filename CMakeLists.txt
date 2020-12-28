cmake_minimum_required(VERSION 3.17)
project(Aircraft-Shooter)

set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "SFML-2.5.1/build")


set(SOURCE  source/main.cpp
            source/Game.cpp
            source/FPSCounter.cpp
            source/Entity.cpp
            source/SceneNode.cpp

            include/ResourceManager.hpp
            include/Game.hpp
            include/FPSCounter.hpp
            include/ResourceManager.inl
            include/Entity.hpp
            include/SceneNode.hpp
            include/ResourceIdentifiers.hpp)


add_executable(${PROJECT_NAME} ${SOURCE})
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)
target_link_libraries (Aircraft-Shooter sfml-graphics sfml-window sfml-system sfml-network sfml-audio)
