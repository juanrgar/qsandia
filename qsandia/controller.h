#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include "filesystem.h"
#include <QTableView>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = 0);
    void init(void);
    
signals:
    
public slots:

private:
    void connectViewModel(void);

    MainWindow *mainWindow;
    QTableView *fileSystemView;
    FileSystem *fileSystemModel;
};

#endif // CONTROLLER_H
