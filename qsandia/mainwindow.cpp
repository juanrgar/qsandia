#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    int screenCenterX = (screenWidth - MainWindow::initialWidth) / 2;
    int screenCenterY = (screenHeight - MainWindow::initialHeight) / 2;

    this->resize( MainWindow::initialWidth, MainWindow::initialHeight );
    this->move( screenCenterX, screenCenterY );
    this->setWindowTitle( "QSandia" );

    this->fileSystemModel = new FileSystem( this );

    this->fileSystemView = new QListView( this );
    this->fileSystemView->setModel( this->fileSystemModel );

    this->setCentralWidget( this->fileSystemView );
}

MainWindow::~MainWindow()
{
}
