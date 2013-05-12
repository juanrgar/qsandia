#include "filesystem.h"

FileSystem::FileSystem(QObject *parent) :
    QAbstractTableModel(parent)
{
}

int
FileSystem::rowCount(const QModelIndex &parent) const
{
    return 2;
}

int
FileSystem::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant
FileSystem::data(const QModelIndex &index, int role) const
{
    switch ( role )
    {
    case Qt::DisplayRole:
        return QString("Row");
        break;
    }
    return QVariant();
}

QVariant
FileSystem::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch ( role )
    {
    case Qt::DisplayRole:
        return QString("Header");
        break;
    }
    return QVariant();
}
