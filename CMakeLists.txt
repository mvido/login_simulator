cmake_minimum_required(VERSION 3.20)

project(login_simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# fetch dependency - libcpr
include(FetchContent)
FetchContent_Declare(cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 1.10.5
)
FetchContent_MakeAvailable(cpr)

# add main executable
add_executable(${PROJECT_NAME} main.cpp LoginSimulator.cpp)

# set path for resulting binary location
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# add library
target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)

# add include directory
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})