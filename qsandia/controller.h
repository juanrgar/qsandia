#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include <QTableView>
#include <QFileSystemModel>
#include <QDebug>

class MainWindow;

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    virtual ~Controller(void);
    void init(void);
    
signals:
    
public slots:
    void onGoHome(void);
    void onGoUp(void);
    void onRowDoubleClicked(const QModelIndex&);
    void onChangeDirectory(QString);

private:
    void connectViewModel(void);
    void changeDirectoryPath(QString);
    void changeDirectoryIndex(const QModelIndex&);
    void configureFileSystemViewAppearance(void);

    MainWindow *mainWindow;
    QTableView *fileSystemView;
    QFileSystemModel *fileSystemModel;
};

#endif // CONTROLLER_H
