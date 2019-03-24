// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_PRIVATE_QUERYPRIVATE_HPP_
#define ALGOLIASEARCH_PRIVATE_QUERYPRIVATE_HPP_

#include <QString>

#include <Export.hpp>

namespace AlgoliaSearch {

struct ALGOLIASEARCH_NO_EXPORT QueryPrivate
{
    explicit QueryPrivate( const QString& query )
        : data( query )
    {
    }

    const QString data;
};

}

#endif // ALGOLIASEARCH_PRIVATE_QUERYPRIVATE_HPP_
