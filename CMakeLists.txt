cmake_minimum_required(VERSION 3.0)

project(CricketSim)

# Add the source file
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/main.cpp)



add_subdirectory(DeliverySimulator)

# set(CORE_DIRECTORY CoreCricket)

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/SimulateCricket/ )#${CORE_DIRECTORY}/include)

target_link_libraries(${PROJECT_NAME}  DeliverySimulator)
