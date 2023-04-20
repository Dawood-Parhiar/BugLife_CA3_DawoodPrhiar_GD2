cmake_minimum_required(VERSION 3.24)
project(BugLife_CA3_DawoodParhiar_GD2)

set(CMAKE_CXX_STANDARD 17)

add_executable(BugLife_CA3_DawoodParhiar_GD2 main.cpp Bug.cpp Bug.h Board.cpp Board.h Crawler.cpp Crawler.h Hopper.cpp Hopper.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "C:/SFML/lib/cmake/SFML")
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(BugLife_CA3_DawoodParhiar_GD2 sfml-graphics sfml-window sfml-system)
