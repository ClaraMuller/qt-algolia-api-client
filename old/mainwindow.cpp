#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QLineEdit(parent)
{
    completer = new AlgoliaSuggest(this);

    setWindowTitle("Search with Algolia");

    adjustSize();
    resize(400, height());
    setFocus();
}

MainWindow::~MainWindow()
{
}
