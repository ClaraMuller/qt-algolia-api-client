#include "algoliaindex.h"

const QString searchUrl(QStringLiteral("https://%1-dsn.algolia.net/1/indexes/%2?query=%3&hitsPerPage=10"));

AlgoliaIndex::AlgoliaIndex(const QString& appId,
                           const QString& apiKey,
                           const QString& indexName,
                           std::shared_ptr<QNetworkAccessManager> networkManagerPtr,
                           QObject* parent)
    : QObject (parent)
    , appId(appId)
    , apiKey(apiKey)
    , indexName(indexName)
    , networkManagerPtr(networkManagerPtr)
{
}

void AlgoliaIndex::search(const QString& query)
{
    const QString url = searchUrl.arg(appId, indexName, query);
    QNetworkRequest request(url);
    request.setRawHeader("X-Algolia-API-Key", apiKey.toUtf8());
    request.setRawHeader("X-Algolia-Application-Id", appId.toUtf8());
    QNetworkReply *reply = networkManagerPtr->get(request);
    connect(reply, SIGNAL(finished()), this, SLOT(searchRequestFinished()));
}

AlgoliaIndex::~AlgoliaIndex()
{
}

// SLOTS

void AlgoliaIndex::searchRequestFinished()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->errorString();
        reply->deleteLater();
        return;
    }

    QByteArray response(reply->readAll());
    qInfo() << response;
    QJsonDocument doc = QJsonDocument::fromJson(response);
    emit searchResult(doc.object());

    reply->deleteLater();
}
