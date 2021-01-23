cmake_minimum_required(VERSION 3.5)

project(MyD14ry LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if (ANDROID)
  add_library(MyD14ry SHARED
          main.cpp
          file_cpp/mainwindow.cpp
          file_h/mainwindow.h
          file_ui/mainwindow.ui
          )
else ()
  add_executable(MyD14ry
          main.cpp
          file_cpp/mainwindow.cpp
          file_h/mainwindow.h
          file_ui/mainwindow.ui
          file_cpp/Activity.cpp
          file_h/Activity.h
          file_h/Subject.h
          file_h/Observer.h
          file_cpp/SubActivity.cpp
          file_h/SubActivity.h
          file_cpp/Event.cpp
          file_h/Event.h
          file_cpp/ShoppingList.cpp
          file_h/ShoppingList.h
          file_cpp/ShoppingProduct.cpp
          file_h/ShoppingProduct.h
          file_cpp/ActivityListController.cpp
          file_h/ActivityListController.h
          file_cpp/ActivityList.cpp
          file_h/ActivityList.h
          file_cpp/ListOfShoppingList.cpp
          file_h/ListOfShoppingList.h
          file_cpp/Calendar.cpp
          file_h/Calendar.h
          file_h/addactivityview.h
          file_cpp/addactivityview.cpp
          file_cpp/CalendarController.cpp
          file_h/CalendarController.h
          file_h/addsubactivitydialog.h
          file_cpp/addsubactivitydialog.cpp
          file_h/activityview.h
          file_cpp/activityview.cpp
          file_h/addeventdialog.h
          file_cpp/addeventdialog.cpp
          file_h/eventview.h
          file_cpp/eventview.cpp
          file_cpp/ListOfShoppingListController.cpp
          file_h/ListOfShoppingListController.h
          file_h/addshoppingproductdialog.h
          file_cpp/addshoppingproductdialog.cpp
          file_h/addshoppinglistdialog.h
          file_cpp/addshoppinglistdialog.cpp
          file_h/shoppinglistview.h
          file_cpp/shoppinglistview.cpp
          file_h/QListWidgetTemplate.h
          file_cpp/Category.cpp
          file_h/Category.h
          file_cpp/addcategory.cpp
          file_h/addcategory.h
          file_h/finddialog.h
          file_cpp/finddialog.cpp
          file_h/alertwindow.h
          file_cpp/alertwindow.cpp)
endif ()

target_link_libraries(MyD14ry PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
