cmake_minimum_required(VERSION 3.16)

project(daytime)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Boost REQUIRED COMPONENTS system thread)
file(GLOB SOURCES "src/*.cpp")

include_directories(${Boost_INCLUDE_DIR})
add_executable(client src/client.cpp)
add_executable(iterativeServer src/iterativeServer.cpp)
target_link_libraries(client ${Boost_LIBRARIES})
target_link_libraries(iterativeServer ${Boost_LIBRARIES})