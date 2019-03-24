#ifndef ALGOLIASUGGEST_H
#define ALGOLIASUGGEST_H


#include <memory>
#include "algoliasearch.h"
#include "algoliaindex.h"

#include <QtWidgets>
#include <QtNetwork>
#include <QtCore>

class AlgoliaSuggest : public QObject
{
    Q_OBJECT

public:
    explicit AlgoliaSuggest(QLineEdit *parent = nullptr);
    virtual ~AlgoliaSuggest();

    void initAlgolia();
    bool eventFilter(QObject *obj, QEvent *ev) override;
    void showResults(const QVector<QString>& choices);

public slots:

    void doneCompletion();
    void searchResultReceived(QJsonObject result);

private slots:
    void search();

private:
    QLineEdit *editor = nullptr;
    QTreeWidget *popup = nullptr;

    std::shared_ptr<QNetworkAccessManager> networkManagerPtr;
    std::unique_ptr<AlgoliaIndex> index;
};
#endif // ALGOLIASUGGEST_H
