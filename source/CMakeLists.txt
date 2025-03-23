cmake_minimum_required(VERSION 3.10)
project(nlohmann_json_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

# Include FetchContent module
include(FetchContent)

# Download and include nlohmann_json library
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.0
)

FetchContent_MakeAvailable(nlohmann_json)

add_executable(nlohmann_json_example 
                src/main.cpp
                src/AllFilesOnDir.cpp)

target_link_libraries(nlohmann_json_example nlohmann_json::nlohmann_json)