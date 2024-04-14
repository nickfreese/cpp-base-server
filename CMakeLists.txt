cmake_minimum_required(VERSION 3.26.3)

project(cpp-base-server)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(httplib URL https://github.com/yhirose/cpp-httplib/archive/refs/tags/v0.12.6.tar.gz)
FetchContent_MakeAvailable(httplib)

SET(CMAKE_CXX_FLAGS  "-std=c++17 -v")
add_executable(${PROJECT_NAME} cpp-base-server.cpp)

target_link_libraries(${PROJECT_NAME}  PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(${PROJECT_NAME}  PUBLIC httplib)
