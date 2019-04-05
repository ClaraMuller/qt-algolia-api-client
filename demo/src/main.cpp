// Copyright (c) 2019 All Rights Reserved Algolia SAS

#include <memory>

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>
#include <QJsonDocument>

#include <AlgoliaSearch/Client.hpp>
#include <AlgoliaSearch/Index.hpp>
#include <AlgoliaSearch/NetworkResult.hpp>
#include <AlgoliaSearch/Query.hpp>

namespace
{
    const QString DEMO_APPLICATION_ID = "30QT3ZUDR4";
    const QString DEMO_API_KEY = "07cd0c0d939f2153dc54e2b082b19f7e";
    const QString DEMO_INDEX_NAME = "movies";
    const QString DEMO_SEARCH_QUERY = "dica";

    std::unique_ptr< QCommandLineParser > processCommandLine(
        const QCoreApplication& app )
    {
        auto parser = std::make_unique< QCommandLineParser >();

        parser->addHelpOption();

        const QCommandLineOption optApplicationId(
            "application-id",
            "Algolia appication identifier",
            "Id",
            DEMO_APPLICATION_ID );
        parser->addOption( optApplicationId );

        const QCommandLineOption optApiKey(
            "api-key",
            "Algolia api key",
            "Key",
            DEMO_API_KEY );
        parser->addOption( optApiKey );

        const QCommandLineOption optIndexName(
            "index-name",
            "Algolia engine index name",
            "String",
            DEMO_INDEX_NAME );
        parser->addOption( optIndexName );

        const QCommandLineOption optSearchQuery(
            { "search-query", "q" } ,
            "Algolia search query",
            "String",
            DEMO_SEARCH_QUERY );
        parser->addOption( optSearchQuery );

        parser->process( app );

        return parser;
    }
}

int main( int argc, char* argv[] )
{
    QCoreApplication app( argc, argv );

    auto parser = ::processCommandLine( app );

    auto* client = new AlgoliaSearch::Client(
        parser->value( "application-id" ),
        parser->value( "api-key" ),
        & app );

    auto* index = client->createIndex( parser->value( "index-name" ) );
    auto* result = index->search( parser->value( "search-query" ) );

    QObject::connect(
        result,
        & AlgoliaSearch::NetworkResult::finished,
        & app,
        [ & app, result ]()
        {
            if( QNetworkReply::NoError != result->error() )
            {
                qCritical() << result->error() << ":" << result->status();
            }
            else
            {
                const auto document =
                    QJsonDocument::fromJson( result->output() );

                qInfo().noquote() << document.toJson();
            }

            result->deleteLater();

            app.quit();
        } );

    return app.exec();
}
