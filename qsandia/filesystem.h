#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <QAbstractTableModel>

class FileSystem : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit FileSystem(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

signals:
    
public slots:

private:
    QString currentWorkingDirectory;
    
};

#endif // FILESYSTEM_H
