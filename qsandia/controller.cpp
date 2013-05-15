#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    this->fileSystemModel = new FileSystem();
    this->mainWindow = new MainWindow();
    this->fileSystemView = static_cast<QTableView *>(this->mainWindow->centralWidget());
    this->fileSystemView->setModel( this->fileSystemModel );
}

void
Controller::init(void)
{
    this->connectViewModel();
    this->mainWindow->show();
}

void
Controller::connectViewModel(void)
{
    connect( this->fileSystemView, SIGNAL(doubleClicked(const QModelIndex&)),
             this->fileSystemModel, SLOT(onRowDoubleClicked(const QModelIndex&)) );
}
