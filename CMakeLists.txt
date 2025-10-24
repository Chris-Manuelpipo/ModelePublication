cmake_minimum_required(VERSION 3.16)

project(ModelePublicationn VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    src/Ressource.cpp
    src/Publication.cpp
    main.cpp
    mainwindow.cpp
    mainwindow.ui
)

add_executable(ModelePublicationn ${PROJECT_SOURCES})
target_include_directories(ModelePublicationn PRIVATE include)
target_link_libraries(ModelePublicationn PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ModelePublicationn)
endif()
