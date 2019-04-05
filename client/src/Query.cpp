// Copyright (c) 2019 All Rights Reserved Algolia SAS

#include <Query.hpp>
#include <QueryPrivate.hpp>

using namespace AlgoliaSearch;

Query::Query( const QString& query )
    : p( std::make_unique< QueryPrivate >( query ) )
{
}

Query::~Query() = default;

QDebug operator<<( QDebug stream, const Query& query )
{
    stream << query.p->data;

    return stream;
}
