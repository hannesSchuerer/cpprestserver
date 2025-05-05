cmake_minimum_required(VERSION 3.25)

project(
    Restserver
    VERSION 0.1.0
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_CLANG_FORMAT "Enable to add clang-format." ON)
option(ENABLE_CMAKE_FORMAT "Enable to add cmake-format." ON)

# CMAKE MODULES
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

set(APP_NAME app)
set(LIB_RESTSERVER_NAME restserver)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
find_package(spdlog REQUIRED)
find_package(cxxopts REQUIRED)
find_package(cpprestsdk REQUIRED)

add_subdirectory(src)
add_subdirectory(app)
