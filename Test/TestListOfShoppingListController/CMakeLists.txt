cmake_minimum_required(VERSION 3.5)

project(TestListOfShoppingListController LANGUAGES CXX)


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

add_executable(TestListOfShoppingListController
        tst_testlistofshoppinglistcontroller.cpp
        ../../QListWidgetShoppingList.cpp
        ../../QListWidgetShoppingList.h
        ../../QListWidgetProduct.cpp
        ../../QListWidgetProduct.h
        ../../ListOfShoppingListController.cpp
        ../../ListOfShoppingListController.h
        ../../ShoppingList.cpp
        ../../ShoppingList.h
        ../../ShoppingProduct.cpp
        ../../ShoppingProduct.h
        ../../ListOfShoppingList.cpp
        ../../ListOfShoppingList.h)
add_test(NAME TestListOfShoppingListController COMMAND TestListOfShoppingListController)

target_link_libraries(TestListOfShoppingListController PRIVATE Qt5::Test Qt${QT_VERSION_MAJOR}::Widgets)

