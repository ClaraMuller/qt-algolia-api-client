// Copyright (c) 2019 All Rights Reserved Algolia SAS

#include <NetworkRequest.hpp>
#include <NetworkResult.hpp>
#include <NetworkResultPrivate.hpp>

using namespace AlgoliaSearch;

NetworkResult::NetworkResult( NetworkRequest* request, QObject* parent )
    : p( std::make_unique< NetworkResultPrivate >() )
{
    connect(
        request,
        & NetworkRequest::finished,
        this,
        [ this, request ]( auto error, auto status, const auto& data )
        {
            request->deleteLater();

            p->error = error;
            p->status = status;
            p->output = data;
            p->isFinished = true;

            emit finished();
        } );
}

NetworkResult::~NetworkResult() = default;

bool NetworkResult::isFinished() const
{
    return p->isFinished;
}

bool NetworkResult::hasError() const
{
    return QNetworkReply::NoError != error();
}

QNetworkReply::NetworkError NetworkResult::error() const
{
    return p->error;
}

int NetworkResult::status() const
{
    return p->status;
}

const QByteArray& NetworkResult::output() const
{
    return p->output;
}
