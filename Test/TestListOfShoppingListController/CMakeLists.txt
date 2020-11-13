cmake_minimum_required(VERSION 3.5)

project(TestListOfShoppingListController LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)

add_executable(TestListOfShoppingListController
        tst_testlistofshoppinglistcontroller.cpp
        ../../ListOfShoppingListController.cpp
        ../../ListOfShoppingListController.h
        ../../ShoppingList.cpp
        ../../ShoppingList.h
        ../../ListOfShoppingList.cpp
        ../../ListOfShoppingList.h)
add_test(NAME TestListOfShoppingListController COMMAND TestListOfShoppingListController)

target_link_libraries(TestListOfShoppingListController PRIVATE Qt5::Test)

