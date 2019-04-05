// Copyright (c) 2019 All Rights Reserved Algolia SAS

#include <Client.hpp>
#include <Index.hpp>
#include <IndexPrivate.hpp>
#include <NetworkResult.hpp>
#include <Query.hpp>
#include <SearchRequest.hpp>

using namespace AlgoliaSearch;

Index::Index( Client& client, const QString& indexName )
    : QObject( & client )
    , p( std::make_unique< IndexPrivate >( client, indexName ) )
{
}

Index::~Index() = default;

const QString& Index::name() const
{
    return p->name;
}

NetworkResult* Index::search( const Query& query )
{
    auto* request = new SearchRequest( *this, this );

    const bool result = request->get( query );
    Q_ASSERT( result );

    return new NetworkResult( request, this );
}

QDebug operator<<( QDebug stream, const Index& index )
{
    stream << index.name();
    return stream;
}
