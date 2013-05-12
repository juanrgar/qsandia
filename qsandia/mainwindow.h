#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QApplication>
#include <QDesktopWidget>
#include "filesystem.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    FileSystem *fileSystemModel;
    QListView *fileSystemView;

    static const int initialWidth = 800;
    static const int initialHeight = 600;
};

#endif // MAINWINDOW_H
