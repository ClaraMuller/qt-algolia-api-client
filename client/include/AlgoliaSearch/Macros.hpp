// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_MACROS_HPP_
#define ALGOLIASEARCH_MACROS_HPP_

#include <memory>

#include <Export.hpp>

#define DECLARE_PRIVATE_POINTER( Class )  \
    public:                               \
        const std::unique_ptr< Class > p;

#endif // ALGOLIASEARCH_MACROS_HPP_
