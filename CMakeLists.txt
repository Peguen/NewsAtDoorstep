cmake_minimum_required(VERSION 3.16)

project(
    LudumDareGame
    VERSION 0.1
    DESCRIPTION "First (GAME JAM) Game"
    LANGUAGES CXX
)

set(BUILD_SHARED_LIBS TRUE)
set(SFML_STATIC_LIBRARIES FALSE)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

add_subdirectory(src)