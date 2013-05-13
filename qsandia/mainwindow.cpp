#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setPositionToScreenCenter();
    this->setWindowTitle( "QSandia" );

    this->createActions();
    this->configureToolBar();

    this->createFileSystemView();
    this->configureFileSystemViewAppearance();
}

MainWindow::~MainWindow()
{
}

void
MainWindow::setPositionToScreenCenter(void)
{
    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth = desktop->width();
    int screenHeight = desktop->height();

    int screenCenterX = (screenWidth - MainWindow::initialWidth) / 2;
    int screenCenterY = (screenHeight - MainWindow::initialHeight) / 2;

    this->resize( MainWindow::initialWidth, MainWindow::initialHeight );
    this->move( screenCenterX, screenCenterY );
}

void
MainWindow::createFileSystemView(void)
{
    this->fileSystemView = new QTableView( this );
    this->setCentralWidget( this->fileSystemView );
}

void
MainWindow::configureFileSystemViewAppearance(void)
{
    this->fileSystemView->verticalHeader()->hide();
    this->fileSystemView->horizontalHeader()->setStretchLastSection( true );
    this->fileSystemView->setSelectionBehavior( QAbstractItemView::SelectRows );
}

void
MainWindow::createActions(void)
{
    this->goHomeAction = new QAction(QIcon::fromTheme("go-home"), tr("&Home"), this);
    this->goHomeAction->setStatusTip( tr("Display HOME contents") );
    connect( this->goHomeAction, SIGNAL(triggered()), this, SLOT(onGoHome()) );
}

void
MainWindow::configureToolBar(void)
{
    QToolBar *addressToolBar = this->addToolBar( tr("Address") );
    addressToolBar->addAction( goHomeAction );
}

void
MainWindow::onGoHome(void)
{
}
