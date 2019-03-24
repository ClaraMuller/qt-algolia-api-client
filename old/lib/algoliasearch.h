#ifndef ALGOLIASEARCH_H
#define ALGOLIASEARCH_H

#include <memory>
#include <QString>

#include "algoliaindex.h"

class AlgoliaSearch: public QObject
{
    Q_OBJECT

public:
    AlgoliaSearch(const QString& appId, const QString& apiKey, QObject* parent = nullptr);
    virtual ~AlgoliaSearch() = default;

    std::unique_ptr<AlgoliaIndex> initIndex(const QString& indexName,
                                            std::shared_ptr<QNetworkAccessManager> networkManagerPtr);

private:
    const QString apiKey;
    const QString appId;

};

#endif // ALGOLIASEARCH_H
