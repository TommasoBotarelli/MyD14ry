cmake_minimum_required(VERSION 3.5)

project(TestCalendarController LANGUAGES CXX)


find_package(Qt5Test REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)

add_executable(TestCalendarController
        tst_testcalendarcontroller.cpp
        ../../Event.h
        ../../Event.cpp
        ../../Calendar.h
        ../../Calendar.cpp
        ../../CalendarController.h
        ../../CalendarController.cpp
        ../../QListWidgetEvent.h
        ../../QListWidgetEvent.cpp
        )




add_test(NAME TestCalendarController COMMAND TestCalendarController)

target_link_libraries(TestCalendarController PRIVATE Qt5::Test Qt${QT_VERSION_MAJOR}::Widgets)

