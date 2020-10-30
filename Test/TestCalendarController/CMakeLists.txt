cmake_minimum_required(VERSION 3.5)

project(TestCalendarController LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(TestCalendarController
        tst_testcalendarcontroller.cpp
        ../../Event.h
        ../../Event.cpp
        ../../Calendar.h
        ../../Calendar.cpp
        ../../CalendarController.h
        ../../CalendarController.cpp
        )




add_test(NAME TestCalendarController COMMAND TestCalendarController)

target_link_libraries(TestCalendarController PRIVATE Qt5::Test)

