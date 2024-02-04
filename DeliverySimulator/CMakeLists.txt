cmake_minimum_required(VERSION 3.0)

project(DeliverySimulator)

# Add the source file
# add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/delivery_simulator.cpp)
add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCE_DIR}/src/delivery_simulator.cpp)



# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
