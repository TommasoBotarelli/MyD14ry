cmake_minimum_required(VERSION 3.5)

project(TestListOfShoppingList LANGUAGES CXX)


find_package(Qt5Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing(true)

add_executable(TestListOfShoppingList tst_testlistofshoppinglist.cpp
        ../../file_cpp/ListOfShoppingList.cpp
        ../../file_h/ListOfShoppingList.h
        ../../file_h/ShoppingList.h
        ../../file_cpp/ShoppingList.cpp
        ../../file_h/ShoppingProduct.h
        ../../file_cpp/ShoppingProduct.cpp)



add_test(NAME TestListOfShoppingList COMMAND TestListOfShoppingList)

target_link_libraries(TestListOfShoppingList PRIVATE Qt5::Test)

