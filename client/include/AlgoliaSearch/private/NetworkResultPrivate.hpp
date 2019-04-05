// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_PRIVATE_NETWORKRESULTPRIVATE_HPP_
#define ALGOLIASEARCH_PRIVATE_NETWORKRESULTPRIVATE_HPP_

#include <QByteArray>
#include <QNetworkReply>

#include <Export.hpp>

namespace AlgoliaSearch {

struct ALGOLIASEARCH_NO_EXPORT NetworkResultPrivate
{
    NetworkResultPrivate()
        : error( QNetworkReply::NoError )
        , status( 0 )
        , isFinished( false )
    {
    }

    QByteArray output;
    QNetworkReply::NetworkError error;
    int status;
    bool isFinished;
};

}

#endif // ALGOLIASEARCH_PRIVATE_NETWORKRESULTPRIVATE_HPP_
