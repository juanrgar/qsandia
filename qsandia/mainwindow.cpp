#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->pathLine = new QLineEdit( this );
}

MainWindow::~MainWindow()
{
}

void
MainWindow::init(void)
{
    this->setPositionToScreenCenter();
    this->setWindowTitle( "QSandia" );
    this->setUnifiedTitleAndToolBarOnMac( true );

    this->createActions();
    this->configureToolBar();
}

void
MainWindow::setWindowController(Controller *controller)
{
    this->controller = controller;
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
MainWindow::createActions(void)
{
    this->goHomeAction = new QAction( QIcon(":/icons/go-home.png"), tr("&Home"), this );
    this->goHomeAction->setStatusTip( tr("Display HOME contents") );

    this->goUpAction = new QAction( QIcon(":/icons/go-up.png"), tr("&Up"), this );
    this->goHomeAction->setStatusTip( tr("Go one level up") );
}

void
MainWindow::connectActions(void)
{
    connect( this->goHomeAction, SIGNAL(triggered()), this->controller, SLOT(onGoHome()) );
    connect( this->goUpAction, SIGNAL(triggered()), this->controller, SLOT(onGoUp()) );
}

void
MainWindow::configureToolBar(void)
{
    QToolBar *addressToolBar = this->addToolBar( tr("Address tool bar") );
    addressToolBar->addAction( goHomeAction );
    addressToolBar->addAction( goUpAction );

    addressToolBar->addWidget( this->pathLine );
}

void
MainWindow::setCurrentDirectory(QString& dirPath)
{
    this->pathLine->setText( dirPath );
}
