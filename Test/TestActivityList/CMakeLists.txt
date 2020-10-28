cmake_minimum_required(VERSION 3.5)

project(TestActivityList LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)

add_executable(TestActivityList
        tst_testactivitylist.cpp
        /home/tommaso/Scrivania/MyD14ry/Activity.h
        /home/tommaso/Scrivania/MyD14ry/Activity.cpp
        /home/tommaso/Scrivania/MyD14ry/ActivityList.h
        /home/tommaso/Scrivania/MyD14ry/ActivityList.cpp
        /home/tommaso/Scrivania/MyD14ry/SubActivity.h
        /home/tommaso/Scrivania/MyD14ry/SubActivity.cpp
        )
add_test(NAME TestActivityList COMMAND TestActivityList)

target_link_libraries(TestActivityList PRIVATE Qt5::Test)

