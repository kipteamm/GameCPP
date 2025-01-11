cmake_minimum_required(VERSION 3.20)
project(InleidingProgrammerenGame)


# Stel het pad naar SFML in
set(SFML_DIR "C:/SFML-2.6.2/lib/cmake/SFML")


find_package(SFML 2.6.2 REQUIRED COMPONENTS graphics window system)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
    main.cpp
    Game.cpp
    Game.h
    Room.cpp
    Room.h
    Entity.cpp
    Entity.h
)
add_executable(InleidingProgrammerenGame ${SOURCE_FILES})
target_link_libraries(InleidingProgrammerenGame sfml-graphics sfml-window sfml-system)