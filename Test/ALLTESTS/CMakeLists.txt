project(AllTests LANGUAGES CXX)

cmake_minimum_required(VERSION 3.5)

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

add_executable(AllTests
        AllTests.cpp
        ../ActivityControllerTest/tst_activitycontrollertest.cpp
        ../TestActivity/tst_activitytest.cpp
        ../TestActivityList/tst_testactivitylist.cpp
        ../TestActivityListController/tst_testactivtylistcontroller.cpp
        ../TestCalendar/tst_testcalendar.cpp
        ../TestCalendarController/tst_testcalendarcontroller.cpp
        ../TestEvent/tst_testevent.cpp
        ../TestListOfShoppingList/tst_testlistofshoppinglist.cpp
        ../TestListOfShoppingListController/tst_testlistofshoppinglistcontroller.cpp
        ../TestShoppingList/tst_testshoppinglist.cpp
        ../TestShoppingListController/tst_testshoppinglistcontroller.cpp
        )

add_test(NAME AllTests COMMAND AllTests)

target_link_libraries(AllTests PRIVATE Qt5::Test Qt${QT_VERSION_MAJOR}::Widgets)