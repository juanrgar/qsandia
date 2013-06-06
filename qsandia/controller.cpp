#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    this->mainWindow = new MainWindow;

    this->fileSystemModel = new QFileSystemModel;

    this->fileSystemView = new QTableView( this->mainWindow );
    this->mainWindow->setCentralWidget( this->fileSystemView );

    this->fileSystemView->setModel( fileSystemModel );
    this->changeDirectoryPath( QDir::homePath() );
    this->configureFileSystemViewAppearance();

    this->connectViewModel();

    this->mainWindow->init();
    this->mainWindow->setWindowController( this );
    this->mainWindow->connectActions();
}

Controller::~Controller(void)
{
    delete this->mainWindow;
    delete this->fileSystemModel;
}

void
Controller::init(void)
{
    this->mainWindow->show();
}

void
Controller::connectViewModel(void)
{
    connect( this->fileSystemView, SIGNAL(doubleClicked(const QModelIndex&)),
             this, SLOT(onRowDoubleClicked(const QModelIndex&)) );
    connect( this->mainWindow, SIGNAL(changeDirectory(QString)),
             this, SLOT(onChangeDirectory(QString)) );
//    connect( this->fileSystemModel, SIGNAL(directoryLoaded(const QString&)),
//             this->fileSystemView, SLOT(resizeColumnsToContents()) );
}

void
Controller::onGoHome(void)
{
    this->changeDirectoryPath( QDir::homePath() );
}

void
Controller::onGoUp(void)
{
    QString currentDirPath = this->fileSystemModel->rootPath();
    QDir currentDir = QDir( currentDirPath );

    currentDir.cdUp();
    QString newDirPath = currentDir.absolutePath();

    this->changeDirectoryPath( newDirPath );
}

void
Controller::onRowDoubleClicked( const QModelIndex& index )
{
    this->changeDirectoryIndex( index );
}

void
Controller::onChangeDirectory( QString dirPath )
{
    if (QString::compare( dirPath, "~" ) == 0)
    {
        dirPath = QDir::homePath();
    }

    this->changeDirectoryPath( dirPath );
}

void
Controller::changeDirectoryPath( QString dirPath )
{
    QModelIndex dirModelIndex = this->fileSystemModel->index( dirPath );

    qDebug() << "Changing to";
    qDebug() << dirPath;

    this->mainWindow->setCurrentDirectory( dirPath );

    this->fileSystemModel->setRootPath( dirPath );
    this->fileSystemView->setRootIndex( dirModelIndex );
}

void
Controller::changeDirectoryIndex( const QModelIndex& dirModelIndex )
{
    if (!this->fileSystemModel->isDir( dirModelIndex ))
    {
        return;
    }

    QVariant dirPathVariant = this->fileSystemModel->data( dirModelIndex, QFileSystemModel::FilePathRole );
    QString dirPath = dirPathVariant.toString();

    this->mainWindow->setCurrentDirectory( dirPath );

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

