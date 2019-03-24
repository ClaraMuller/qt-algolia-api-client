// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_PRIVATE_INDEXPRIVATE_HPP_
#define ALGOLIASEARCH_PRIVATE_INDEXPRIVATE_HPP_

#include <QString>

#include <Export.hpp>

namespace AlgoliaSearch {

class Client;

struct ALGOLIASEARCH_NO_EXPORT IndexPrivate
{
    IndexPrivate( Client& client_, const QString& indexName )
        : client( client_ )
        , name( indexName )
    {
    }

    Client& client;
    const QString name;
};

}

#endif // ALGOLIASEARCH_PRIVATE_INDEXPRIVATE_HPP_
