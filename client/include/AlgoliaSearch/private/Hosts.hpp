// Copyright (c) 2019 All Rights Reserved Algolia SAS

#ifndef ALGOLIASEARCH_HOSTS_HPP_
#define ALGOLIASEARCH_HOSTS_HPP_

#include <QString>
#include <QStringList>

#include <Export.hpp>

namespace AlgoliaSearch {

class HostsPrivate;

class ALGOLIASEARCH_NO_EXPORT Hosts
{
public:
    explicit Hosts( const QString& applicationId );

    const QString& readHost() const;
    const QString& writeHost() const;

    const QStringList& fallbackHosts() const;

private:
    const QString _readHost;
    const QString _writeHost;
    const QStringList _fallbackHosts;
};

}

#endif // ALGOLIASEARCH_HOSTS_HPP_
