// Copyright (c) 2019 All Rights Reserved Algolia SAS

#include <algorithm>

#include <Client.hpp>
#include <ClientPrivate.hpp>
#include <Index.hpp>

using namespace AlgoliaSearch;

namespace
{
    constexpr int ALGOLIA_SEARCH_CLIENT_VERSION = 1;
}

Client::Client(
    const QString& applicationId,
    const QString& apiKey,
    QNetworkAccessManager& networkManager,
    QObject* parent )
    : QObject( parent )
    , p(
        std::make_unique< ClientPrivate >(
            applicationId,
            apiKey,
            networkManager ) )
{
}

Client::Client(
    const QString& applicationId,
    const QString& apiKey,
    QObject* parent )
    : QObject( parent )
    , p(
        std::make_unique< ClientPrivate >(
            applicationId,
            apiKey,
            *( new QNetworkAccessManager( this ) ) ) )
{
}

Client::~Client() = default;

int Client::version() const
{
    return ALGOLIA_SEARCH_CLIENT_VERSION;
}

const QString& Client::applicationId() const
{
    return p->applicationId;
}

const QString& Client::apiKey() const
{
    return p->apiKey;
}

Index* Client::createIndex( const QString& indexName )
{
    auto* index = p->indexes.value( indexName );

    if( nullptr == index )
    {
        index = new Index( *this, indexName );
        p->indexes.insert( indexName, index );
    }

    return index;
}

Index* Client::index( const QString& indexName ) const
{
    return p->indexes.value( indexName );
}

QList< Index* > Client::indexes() const
{
    return p->indexes.values();
}

bool Client::releaseIndex( const QString& indexName )
{
    const auto it = p->indexes.find( indexName );
    return releaseIndex( it );
}

bool Client::releaseIndex( const Index* index )
{
    const auto it = std::find_if(
        p->indexes.begin(),
        p->indexes.end(),
        [ index ]( const Index* ptr ) { return index == ptr; } );
    return releaseIndex( it );
}

bool Client::releaseIndex( const QMap< QString, Index* >::iterator& it )
{
    if( p->indexes.end() == it )
    {
        return false;
    }

    p->indexes.erase( it );

    auto* index = it.value();
    delete index;

    return true;
}

QDebug operator<<( QDebug stream, const Client& client )
{
    stream << client.applicationId();

    return stream;
}
