// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_PRIVATE_SEARCHREQUEST_HPP_
#define ALGOLIASEARCH_PRIVATE_SEARCHREQUEST_HPP_

#include <QObject>
#include <QString>

#include <Export.hpp>

#include "NetworkRequest.hpp"

namespace AlgoliaSearch {

class Client;
class Index;
class Query;

class ALGOLIASEARCH_NO_EXPORT SearchRequest : public NetworkRequest
{
protected:
    SearchRequest(
        const Client& client,
        const QString& path,
        QObject* parent = nullptr );

public:
    explicit SearchRequest( const Index& index, QObject* parent = nullptr );
    ~SearchRequest() override;

    bool get( const Query& query /* , const RequestOptions& options */ );

private:
    const Client& _client;
    QString _path;
};

}

#endif // ALGOLIASEARCH_PRIVATE_SEARCHREQUEST_HPP_
