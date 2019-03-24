#include "algoliasearch.h"

AlgoliaSearch::AlgoliaSearch(const QString& appId, const QString& apiKey, QObject* parent)
    : QObject (parent)
    , appId(appId)
    , apiKey(apiKey)
{
}

std::unique_ptr<AlgoliaIndex> AlgoliaSearch::initIndex(
    const QString& indexName,
    std::shared_ptr<QNetworkAccessManager> networkManagerPtr)
{
    return std::make_unique<AlgoliaIndex>(appId, apiKey, indexName, networkManagerPtr);
}
