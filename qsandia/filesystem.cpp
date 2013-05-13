#include "filesystem.h"

FileSystem::FileSystem(QObject *parent) :
    QAbstractTableModel(parent)
{
    this->currentWorkingDirectory = QDir::home();
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
    switch ( role )
    {
    case Qt::DisplayRole:
        if (index.column() == 0)
        {
            return QString(this->currentWorkingDirectory[index.row()]);
        }
        else
        {
            return QString("Size");
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
