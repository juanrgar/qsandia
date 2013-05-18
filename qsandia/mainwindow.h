#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QApplication>
#include <QDesktopWidget>
#include <QHeaderView>
#include <QToolBar>
#include <QAction>
#include <QIcon>
#include "controller.h"

class Controller;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init(void);
    void setWindowController(Controller *controller);
    void connectActions(void);

signals:
    void changeDirectory(QString dirName);

private slots:

private:
    void setPositionToScreenCenter(void);
    void configureFileSystemViewAppearance(void);
    void createActions(void);
    void configureToolBar(void);

    Controller *controller;
    QAction *goHomeAction;
    QAction *goUpAction;

    static const int initialWidth = 800;
    static const int initialHeight = 600;
};

#endif // MAINWINDOW_H
