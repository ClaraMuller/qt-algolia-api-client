# Copyright (c) 2019 All Rights Reserved Algolia SAS

cmake_minimum_required (VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 14) # Because we want unique_ptr

set(QT_SOURCES                $ENV{HOME}/SourcesCode/Qt5/5.12.1)
set(CMAKE_PREFIX_PATH         ${QT_SOURCES}/clang_64)
set(CMAKE_AUTOMOC             ON)
set(CMAKE_AUTOUIC             ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

project (algolia-suggest)

find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

ADD_LIBRARY( SearchStaticLib STATIC
             lib/algoliaindex.cpp
             lib/algoliasearch.cpp
             lib/algoliasuggest.cpp
)

target_link_libraries(SearchStaticLib
                      Qt5::Core
                      Qt5::Network
                      Qt5::Widgets)

target_include_directories(SearchStaticLib INTERFACE
                           ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(algolia-suggest
               mainwindow.cpp
               main.cpp
)

# Use the QtCore module from Qt 5
target_link_libraries(algolia-suggest
                      Qt5::Core
                      Qt5::Widgets
                      Qt5::Gui)

target_link_libraries(algolia-suggest
                      SearchStaticLib)

