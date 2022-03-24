cmake_minimum_required(VERSION 3.21)

project(SkySpecServer VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_library(SkySpecServer SHARED include/SkySpec/Server.h src/Server.cpp src/plugin.cpp src/server.cpp)
target_include_directories(SkySpecServer PRIVATE include)
set_target_properties(SkySpecServer PROPERTIES OUTPUT_NAME "!SkySpec.Server")

find_package(CommonLibSSE CONFIG REQUIRED)
target_link_libraries(SkySpecServer PRIVATE CommonLibSSE::CommonLibSSE)

find_package(websocketpp CONFIG REQUIRED)
target_link_libraries(SkySpecServer PRIVATE websocketpp::websocketpp)
