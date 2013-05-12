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
    this->mainWindow->show();
}
