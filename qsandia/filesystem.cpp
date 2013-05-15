#include "filesystem.h"

FileSystem::FileSystem(QObject *parent) :
    QAbstractTableModel(parent)
{
    this->currentWorkingDirectory = QDir::home();
    this->currentWorkingDirectory.setFilter( QDir::AllEntries | QDir::NoDotAndDotDot );
}

int
FileSystem::rowCount(const QModelIndex &parent) const
{
    return this->currentWorkingDirectory.count();
}

int
FileSystem::columnCount(const QModelIndex &parent) const
{
    return FileSystem::numberOfColumns;
}

QVariant
FileSystem::data(const QModelIndex &index, int role) const
{
    QFileInfoList currentDirFilesInfo = this->currentWorkingDirectory.entryInfoList();
    QFileInfo fileInfo = currentDirFilesInfo.at( index.row() );

    switch ( role )
    {
    case Qt::DisplayRole:
        if (index.column() == 0)
        {
            return fileInfo.baseName();
        }
        else
        {
            return fileInfo.size();
        }
    }
    return QVariant();
}

QVariant
FileSystem::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("Name");
            case 1:
                return QString("Size");
            }
        }
    }
    return QVariant();
}

void
FileSystem::onRowDoubleClicked(const QModelIndex& index)
{
    const QString dirName;

    this->changeDirectory( dirName );
}

void
FileSystem::changeDirectory( const QString& dirName )
{
    this->currentWorkingDirectory.cd( dirName );
}
