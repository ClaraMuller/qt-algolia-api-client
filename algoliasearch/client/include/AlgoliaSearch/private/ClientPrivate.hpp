// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_PRIVATE_CLIENTPRIVATE_HPP_
#define ALGOLIASEARCH_PRIVATE_CLIENTPRIVATE_HPP_

#include <QMap>
#include <QNetworkAccessManager>
#include <QString>

#include <Export.hpp>

#include "Hosts.hpp"

namespace AlgoliaSearch {

class Index;

struct ALGOLIASEARCH_NO_EXPORT ClientPrivate
{
    ClientPrivate(
        const QString& applicationId_,
        const QString& apiKey_,
        QNetworkAccessManager& networkManager_ )
        : networkManager( networkManager_ )
        , applicationId( applicationId_ )
        , apiKey( apiKey_ )
        , hosts( applicationId )
    {
    }

    QNetworkAccessManager& networkManager;
    const QString applicationId;
    const QString apiKey;
    QMap< QString, Index* > indexes;
    const Hosts hosts;
};

}

#endif // ALGOLIASEARCH_PRIVATE_CLIENTPRIVATE_HPP_
