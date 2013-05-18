#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    this->mainWindow = new MainWindow();

    this->fileSystemModel = new QFileSystemModel;

    this->fileSystemView = new QTableView( this->mainWindow );
    this->mainWindow->setCentralWidget( this->fileSystemView );
}

void
Controller::init(void)
{
    this->changeDirectory( QDir::homePath() );
    this->fileSystemView->setModel( fileSystemModel );
    this->configureFileSystemViewAppearance();

    this->connectViewModel();

    this->mainWindow->init();
    this->mainWindow->setWindowController( this );
    this->mainWindow->connectActions();
    this->mainWindow->show();
}

void
Controller::connectViewModel(void)
{
    connect( this->fileSystemView, SIGNAL(doubleClicked(const QModelIndex&)),
             this, SLOT(onRowDoubleClicked(const QModelIndex&)) );
    connect( this->mainWindow, SIGNAL(changeDirectory(QString)),
             this, SLOT(onChangeDirectory(QString)) );
}

void
Controller::onGoHome(void)
{
    this->changeDirectory( QDir::homePath() );
}

void
Controller::onGoUp(void)
{
}

void
Controller::onRowDoubleClicked( const QModelIndex& index )
{
    if (this->fileSystemModel->isDir( index ))
    {
        this->fileSystemView->setRootIndex( index );
    }
}

void
Controller::onChangeDirectory( QString dirPath )
{
    if (QString::compare( dirPath, "~" ) == 0)
    {
        dirPath = QDir::homePath();
    }

    this->changeDirectory( dirPath );
}

void
Controller::changeDirectory( QString dirPath )
{
    QModelIndex dirModelIndex = this->fileSystemModel->index( dirPath );

    qDebug() << "Changing to";
    qDebug() << dirPath;

    this->fileSystemModel->setRootPath( dirPath );
    this->fileSystemView->setRootIndex( dirModelIndex );
}

void
Controller::configureFileSystemViewAppearance(void)
{
    this->fileSystemView->verticalHeader()->hide();
    this->fileSystemView->horizontalHeader()->setStretchLastSection( true );
    this->fileSystemView->setSelectionBehavior( QAbstractItemView::SelectRows );
    this->fileSystemView->setSelectionMode( QAbstractItemView::SingleSelection );
}

