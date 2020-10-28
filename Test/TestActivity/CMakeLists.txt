cmake_minimum_required(VERSION 3.5)

project(ActivityTest LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)

add_executable(ActivityTest
        tst_activitytest.cpp
        /Users/tommaso/CLionProjects/MyD14ry/Activity.h
        /Users/tommaso/CLionProjects/MyD14ry/Activity.cpp
        /Users/tommaso/CLionProjects/MyD14ry/SubActivity.h
        /Users/tommaso/CLionProjects/MyD14ry/SubActivity.cpp
        )
add_test(NAME ActivityTest COMMAND ActivityTest)

target_link_libraries(ActivityTest PRIVATE Qt5::Test)

