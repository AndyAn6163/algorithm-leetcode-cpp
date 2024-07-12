cmake_minimum_required(VERSION 3.22)
project(algorithm_leetcode_cpp)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281) # 10.2.1
FetchContent_MakeAvailable(fmt)

add_executable(LC0001TwoSum array/LC0001TwoSum.cpp)
