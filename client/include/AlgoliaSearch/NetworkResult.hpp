// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_NETWORKRESULT_HPP_
#define ALGOLIASEARCH_NETWORKRESULT_HPP_

#include <QByteArray>
#include <QNetworkReply>
#include <QObject>

#include "Macros.hpp"

namespace AlgoliaSearch {

class NetworkRequest;
class NetworkResultPrivate;

class ALGOLIASEARCH_EXPORT NetworkResult : public QObject
{
    Q_OBJECT

    DECLARE_PRIVATE_POINTER( NetworkResultPrivate )

public:
    explicit NetworkResult(
        NetworkRequest* request,
        QObject* parent = nullptr );
    ~NetworkResult() override;

    bool isFinished() const;

    bool hasError() const;
    QNetworkReply::NetworkError error() const;

    int status() const;
    const QByteArray& output() const;

signals:
    void finished() const;
};

}

#endif // ALGOLIASEARCH_NETWORKRESULT_HPP_
