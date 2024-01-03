cmake_minimum_required(VERSION 3.0)

project(CricketSim)

add_executable(${PROJECT_NAME} main.cpp)

set(CORE_DIRECTORY CoreCricket)

target_include_directories(${PROJECT_NAME} PUBLIC ${CORE_DIRECTORY}/include)