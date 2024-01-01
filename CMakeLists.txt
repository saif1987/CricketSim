cmake_minimum_required(VERSION 3.0)

project(CricketSim)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC CoreStatistics)