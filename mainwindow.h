#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>

#include <algoliasuggest.h>

class MainWindow : public QLineEdit
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    AlgoliaSuggest *completer = nullptr;
};

#endif // MAINWINDOW_H
