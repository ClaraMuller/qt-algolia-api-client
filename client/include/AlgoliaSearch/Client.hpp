// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_CLIENT_HPP_
#define ALGOLIASEARCH_CLIENT_HPP_

#include <memory>

#include <QDebug>
#include <QMap>
#include <QNetworkAccessManager>
#include <QObject>
#include <QString>

#include "Macros.hpp"

namespace AlgoliaSearch {

class ClientPrivate;
class Index;

class ALGOLIASEARCH_EXPORT Client : public QObject
{
    DECLARE_PRIVATE_POINTER( ClientPrivate )

public:
    Client(
        const QString& applicationId,
        const QString& apiKey,
        QNetworkAccessManager& networkManager,
        QObject* parent = nullptr );

    Client(
        const QString& applicationId,
        const QString& apiKey,
        QObject* parent = nullptr );

    ~Client() override;

    int version() const;

    const QString& applicationId() const;
    const QString& apiKey() const;

    Index* createIndex( const QString& indexName );

    Index* index( const QString& indexName ) const;
    QList< Index* > indexes() const;

    bool releaseIndex( const QString& indexName );
    bool releaseIndex( const Index* index );

private:
    bool releaseIndex( const QMap< QString, Index* >::iterator& it );
};

}

ALGOLIASEARCH_EXPORT
QDebug operator<<( QDebug stream, const AlgoliaSearch::Client& client );

#endif // ALGOLIASEARCH_CLIENT_HPP_
