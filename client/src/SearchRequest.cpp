// Copyright (c) 2019 All Rights Reserved Algolia SAS

#include <QUrlQuery>

#include <Client.hpp>
#include <ClientPrivate.hpp>
#include <Hosts.hpp>
#include <Index.hpp>
#include <IndexPrivate.hpp>
#include <Query.hpp>
#include <QueryPrivate.hpp>
#include <SearchRequest.hpp>

using namespace AlgoliaSearch;

namespace
{
    const QString INDEXES_PATTERN = QStringLiteral( "/%1/indexes/%2" );

    QString buildPath( const Index& index )
    {
        const int version = index.p->client.version();
        return INDEXES_PATTERN.arg( version ).arg( index.name() );
    }
}

SearchRequest::SearchRequest(
    const Client& client,
    const QString& path,
    QObject* parent )
    : NetworkRequest(
        client.p->hosts.fallbackHosts(),
        client.p->networkManager,
        parent )
    , _client( client )
    , _path( path )
{
}

SearchRequest::SearchRequest( const Index& index, QObject* parent )
    : SearchRequest( index.p->client, ::buildPath( index ), parent )
{
}

SearchRequest::~SearchRequest() = default;

bool SearchRequest::get( const Query& query )
{
    QUrlQuery urlQuery;
    urlQuery.addQueryItem( "query", query.p->data );

    QUrl url;
    url.setScheme( "https" );
    url.setHost( _client.p->hosts.readHost() );
    url.setPath( _path );
    url.setQuery( urlQuery );

    QNetworkRequest request( url );

    request.setRawHeader(
        "X-Algolia-API-Key",
        _client.apiKey().toUtf8() );

    request.setRawHeader(
        "X-Algolia-Application-Id",
        _client.applicationId().toUtf8() );

    return NetworkRequest::get( request );
}
