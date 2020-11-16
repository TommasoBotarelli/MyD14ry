cmake_minimum_required(VERSION 3.5)

project(TestShoppingList LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)

add_executable(TestShoppingList tst_testshoppinglist.cpp
        ../../ShoppingProduct.h
        ../../ShoppingProduct.cpp
        ../../ShoppingList.h
        ../../ShoppingList.cpp
        )

add_test(NAME TestShoppingList COMMAND TestShoppingList)

target_link_libraries(TestShoppingList PRIVATE Qt5::Test)

