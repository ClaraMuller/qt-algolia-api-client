// Copyright (c) 2019 All Rights Reserved Algolia SAS

#include <algorithm>
#include <random>

#include <NetworkRequest.hpp>

using namespace AlgoliaSearch;

NetworkRequest::NetworkRequest(
    const QStringList& fallbackHosts,
    QNetworkAccessManager& networkManager,
    QObject* parent )
    : QObject( parent )
    , _networkManager( networkManager )
    , _reply( nullptr )
    , _fallbackHosts( fallbackHosts )
    , _shuffleFallbackHosts( true )
{
}

NetworkRequest::~NetworkRequest()
{
    if( nullptr != _reply )
    {
        _reply->abort();
        _reply->deleteLater();
    }
}

bool NetworkRequest::get( const QNetworkRequest& request )
{
    if( QNetworkRequest() != _request )
    {
        return false;
    }

    _request = request;
    return getNextRequest();
}

bool NetworkRequest::getNextRequest()
{
    _reply = _networkManager.get( _request );

    connect(
        _reply,
        & QNetworkReply::finished,
        this,
        [ this ]()
        {
            _reply->deleteLater();

            const auto error = _reply->error();

            const bool isFinished =
                QNetworkReply::NoError == error || _fallbackHosts.isEmpty();

            if( ! isFinished )
            {
                _request.setUrl( getNextUrl() );
                getNextRequest();
                return;
            }

            if( QNetworkReply::NoError != error )
            {
                emit finished( error, 0, {} );
                return;
            }

            const auto data = _reply->readAll();
            const auto status =
                _reply->attribute( QNetworkRequest::HttpStatusCodeAttribute );

            _reply = nullptr;

            emit finished( error, status.toInt(), data );
        } );

    return true;
}

QUrl NetworkRequest::getNextUrl()
{
    QUrl url = _request.url();
    url.setHost( getNextHost() );

    return url;
}

QString NetworkRequest::getNextHost()
{
    Q_ASSERT( ! _fallbackHosts.isEmpty() );

    if( _shuffleFallbackHosts )
    {
        _shuffleFallbackHosts = false;

        std::shuffle(
            _fallbackHosts.begin(),
            _fallbackHosts.end(),
            std::default_random_engine() );
    }

    return _fallbackHosts.takeFirst();
}
