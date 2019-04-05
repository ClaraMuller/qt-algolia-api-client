# Copyright (c) 2019 All Rights Reserved Algolia SAS

cmake_minimum_required( VERSION 3.1.0 )

### Project ####################################################################

project( AlgoliaSearchClient CXX )

### Build options ##############################################################

set( CMAKE_CXX_STANDARD 14 )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )

### Dependencies ###############################################################

find_package( Qt5Core REQUIRED )
find_package( Qt5Network REQUIRED )

### Target #####################################################################

set(
    PRIVATE_HEADERS
        include/AlgoliaSearch/private/ClientPrivate.hpp
        include/AlgoliaSearch/private/Hosts.hpp
        include/AlgoliaSearch/private/IndexPrivate.hpp
        include/AlgoliaSearch/private/NetworkRequest.hpp
        include/AlgoliaSearch/private/NetworkResultPrivate.hpp
        include/AlgoliaSearch/private/QueryPrivate.hpp
        include/AlgoliaSearch/private/SearchRequest.hpp )

set(
    PUBLIC_HEADERS
        include/AlgoliaSearch/Client.hpp
        include/AlgoliaSearch/Index.hpp
        include/AlgoliaSearch/Macros.hpp
        include/AlgoliaSearch/Query.hpp
        include/AlgoliaSearch/NetworkResult.hpp )

set(
    SOURCES
        src/Client.cpp
        src/Hosts.cpp
        src/Index.cpp
        src/Query.cpp
        src/NetworkRequest.cpp
        src/NetworkResult.cpp
        src/SearchRequest.cpp )

add_library(
    algoliasearch-client
    ${PUBLIC_HEADERS}
    ${PRIVATE_HEADERS}
    ${SOURCES} )

target_link_libraries(
    algoliasearch-client
    PUBLIC
        Qt5::Core
        Qt5::Network )

target_include_directories(
    algoliasearch-client
    PUBLIC
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/AlgoliaSearch
        ${CMAKE_CURRENT_SOURCE_DIR}/include/AlgoliaSearch/private )

set_target_properties(
    algoliasearch-client
    PROPERTIES
        PUBLIC_HEADER "${PUBLIC_HEADERS}" )

### Generate export header #####################################################

include( GenerateExportHeader )

generate_export_header(
    algoliasearch-client
    DEFINE_NO_DEPRECATED
    BASE_NAME ALGOLIASEARCH
    EXPORT_FILE_NAME Export.hpp )
