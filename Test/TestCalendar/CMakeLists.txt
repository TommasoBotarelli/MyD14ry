cmake_minimum_required(VERSION 3.5)

project(TestCalendar LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(TestCalendar
        tst_testcalendar.cpp
        ../../Event.h
        ../../Event.cpp
        ../../Calendar.h
        ../../Calendar.cpp)





add_test(NAME TestCalendar COMMAND TestCalendar)

target_link_libraries(TestCalendar PRIVATE Qt5::Test)

