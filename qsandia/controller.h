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
    void init(void);
    
signals:
    
public slots:
    void onGoHome(void);
    void onGoUp(void);
    void onRowDoubleClicked(const QModelIndex&);
    void onChangeDirectory(QString);

private:
    void connectViewModel(void);
    void changeDirectory(QString);
    void configureFileSystemViewAppearance(void);

    MainWindow *mainWindow;
    QTableView *fileSystemView;
    QFileSystemModel *fileSystemModel;
};

#endif // CONTROLLER_H
