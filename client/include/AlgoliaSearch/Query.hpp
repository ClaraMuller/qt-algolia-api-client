// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_QUERY_HPP_
#define ALGOLIASEARCH_QUERY_HPP_

#include <memory>

#include <QDebug>
#include <QString>

#include "Macros.hpp"

namespace AlgoliaSearch {

class QueryPrivate;

class ALGOLIASEARCH_EXPORT Query
{
    DECLARE_PRIVATE_POINTER( QueryPrivate )

public:
    Query( const QString& query );
    ~Query();
};

}

ALGOLIASEARCH_EXPORT
QDebug operator<<( QDebug stream, const AlgoliaSearch::Query& query );

#endif // ALGOLIASEARCH_QUERY_HPP_
