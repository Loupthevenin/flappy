cmake_minimum_required(VERSION 3.16)

project(Flappy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver SFML 3 (attention aux majuscules)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window System)

# Créer l'exécutable
add_executable(flappy src/pipe.cpp src/bird.cpp src/game.cpp src/main.cpp)

# Lier SFML (nouvelle syntaxe)
target_link_libraries(flappy
    SFML::Graphics
    SFML::Window
    SFML::System
)
