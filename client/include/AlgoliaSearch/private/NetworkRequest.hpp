// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_NETWORKREQUEST_HPP_
#define ALGOLIASEARCH_NETWORKREQUEST_HPP_

#include <memory>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <QStringList>

#include <Export.hpp>

namespace AlgoliaSearch {

class RequestPrivate;

class ALGOLIASEARCH_NO_EXPORT NetworkRequest : public QObject
{
    Q_OBJECT

public:
    NetworkRequest(
        const QStringList& fallbackHosts,
        QNetworkAccessManager& networkManager,
        QObject* parent = nullptr );

    ~NetworkRequest() override;

    bool get( const QNetworkRequest& request );

signals:
    void finished(
        QNetworkReply::NetworkError error,
        int status,
        const QByteArray& data ) const;

private:
    bool getNextRequest();

    QUrl getNextUrl();
    QString getNextHost();

    QNetworkAccessManager& _networkManager;
    QNetworkReply* _reply;
    QNetworkRequest _request;
    QStringList _fallbackHosts;
    bool _shuffleFallbackHosts;
};

}

#endif // ALGOLIASEARCH_NETWORKREQUEST_HPP_
