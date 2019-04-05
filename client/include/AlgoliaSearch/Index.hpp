// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_INDEX_HPP_
#define ALGOLIASEARCH_INDEX_HPP_

#include <memory>

#include <QDebug>
#include <QObject>
#include <QString>

#include "Macros.hpp"

namespace AlgoliaSearch {

class Client;
class IndexPrivate;
class Query;
class NetworkResult;

class ALGOLIASEARCH_EXPORT Index : public QObject
{
    DECLARE_PRIVATE_POINTER( IndexPrivate )

public:
    Index( Client& client, const QString& indexName );
    ~Index() override;

    const QString& name() const;

    NetworkResult* search( const Query& query );
};

}

ALGOLIASEARCH_EXPORT
QDebug operator<<( QDebug stream, const AlgoliaSearch::Index& index );

#endif // ALGOLIASEARCH_INDEX_HPP_
