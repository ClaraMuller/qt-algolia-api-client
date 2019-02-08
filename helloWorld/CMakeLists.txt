# Copyright (c) 2019 All Rights Reserved Algolia SAS

cmake_minimum_required (VERSION 3.1.0)
set(CMAKE_CXX_STANDARD 14) # Because we want unique_ptr

set(QT_SOURCES          $ENV{HOME}/SourcesCode/Qt5/5.12.1)
set(CMAKE_PREFIX_PATH   ${QT_SOURCES}/clang_64)

#set(CMAKE_MODULE_PATH   ${QT_SOURCES}/clang_64/lib/cmake)
#set(Qt5Core_DIR         ${QT_SOURCES}/clang_64/lib/cmake/Qt5Core)
#set(Qt5_DIR             ${QT_SOURCES}/clang_64/lib/cmake/Qt5)
#set(QT_QMAKE_EXECUTABLE ${QT_SOURCES}/clang_64/bin/qmake)

project (HelloWorld)

find_package(Qt5Core REQUIRED)

# Tell CMake to create the helloworld executable
add_executable(HelloWorld
               main.cpp)

# Use the QtCore module from Qt 5
target_link_libraries(HelloWorld Qt5::Core)

