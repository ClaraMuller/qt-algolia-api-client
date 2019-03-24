#ifndef ALGOLIAINDEX_H
#define ALGOLIAINDEX_H

#include <QtCore>
#include <QtNetwork>

class AlgoliaIndex: public QObject
{
    Q_OBJECT

public:
    AlgoliaIndex(const QString& appId,
                 const QString& apiKey,
                 const QString& indexName,
                 std::shared_ptr<QNetworkAccessManager> networkManagerPtr,
                 QObject* parent = nullptr);
    virtual ~AlgoliaIndex();

    void search(const QString& query);

signals:
    void searchResult(QJsonObject);

private:
    const QString appId;
    const QString apiKey;
    const QString indexName;

    std::shared_ptr<QNetworkAccessManager> networkManagerPtr;

private slots:
    void searchRequestFinished();
};

#endif // ALGOLIAINDEX_H
