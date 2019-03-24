# Copyright (c) 2019 All Rights Reserved Algolia SAS

cmake_minimum_required( VERSION 3.1.0 )

### Project ####################################################################

project( AlgoliaSearchDemo CXX )

### Build options ##############################################################

set( CMAKE_CXX_STANDARD 14 )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

### Dependencies ###############################################################

find_package( Qt5Core REQUIRED )
find_package( Qt5Network REQUIRED )

### Target #####################################################################

set( SOURCES src/main.cpp )

add_executable(
    algoliasearch-demo
    ${SOURCES} )

target_link_libraries(
    algoliasearch-demo
    PUBLIC
        Qt5::Core
        Qt5::Network
        algoliasearch-client )
