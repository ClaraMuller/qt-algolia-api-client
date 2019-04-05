// Copyright (c) 2019 All Rights Reserved Algolia SAS

#include <Hosts.hpp>

using namespace AlgoliaSearch;

namespace
{
    const QString READ_URL_PATTERN =
        QStringLiteral( "%1-dsn.algolia.net" );

    const QString WRITE_URL_PATTERN =
        QStringLiteral( "%1.algolia.net" );

    const QString FALLBACK_1_URL_PATTERN =
        QStringLiteral( "%1-1.algolianet.com" );

    const QString FALLBACK_2_URL_PATTERN =
        QStringLiteral( "%1-2.algolianet.com" );

    const QString FALLBACK_3_URL_PATTERN =
        QStringLiteral( "%1-3.algolianet.com" );

    QString buildHost(
        const QString& applicationId,
        const QString& pattern )
    {
        return pattern.arg( applicationId );
    }

    QStringList buildFallbackHosts( const QString& applicationId )
    {
        const QStringList hosts
        {
            ::buildHost( applicationId, FALLBACK_1_URL_PATTERN ),
            ::buildHost( applicationId, FALLBACK_2_URL_PATTERN ),
            ::buildHost( applicationId, FALLBACK_3_URL_PATTERN )
        };

        return hosts;
    }
}

Hosts::Hosts( const QString& applicationId )
    : _readHost( ::buildHost( applicationId, READ_URL_PATTERN ) )
    , _writeHost( ::buildHost( applicationId, WRITE_URL_PATTERN ) )
    , _fallbackHosts( ::buildFallbackHosts( applicationId ) )
{
}

const QString& Hosts::readHost() const
{
    return _readHost;
}

const QString& Hosts::writeHost() const
{
    return _writeHost;
}

const QStringList& Hosts::fallbackHosts() const
{
    return _fallbackHosts;
}
