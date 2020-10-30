cmake_minimum_required(VERSION 3.5)

project(ActivityControllerTest LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)

add_executable(ActivityControllerTest
        tst_activitycontrollertest.cpp
        ../../Activity.h
        ../../Activity.cpp
        ../../SubActivity.h
        ../../SubActivity.cpp
        ../../ActivityController.h
        ../../ActivityController.cpp
        )
add_test(NAME ActivityControllerTest COMMAND ActivityControllerTest)

target_link_libraries(ActivityControllerTest PRIVATE Qt5::Test)

