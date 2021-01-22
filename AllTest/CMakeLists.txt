cmake_minimum_required(VERSION 3.5)

project(AllTest LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)

add_executable(AllTest
        tst_alltest.cpp
        ../file_h/Activity.h
        ../file_cpp/Activity.cpp
        ../file_h/ActivityList.h
        ../file_cpp/ActivityList.cpp
        ../file_h/ActivityListController.h
        ../file_cpp/ActivityListController.cpp
        ../file_h/Calendar.h
        ../file_cpp/Calendar.cpp
        ../file_h/CalendarController.h
        ../file_cpp/CalendarController.cpp
        ../file_h/Category.h
        ../file_cpp/Category.cpp
        ../file_h/Event.h
        ../file_cpp/Event.cpp
        ../file_h/SubActivity.h
        ../file_cpp/SubActivity.cpp
        )
add_test(NAME AllTest COMMAND AllTest)

target_link_libraries(AllTest PRIVATE Qt5::Test)

