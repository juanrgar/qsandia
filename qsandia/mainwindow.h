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

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onGoHome(void);

private:
    void setPositionToScreenCenter(void);
    void createFileSystemView(void);
    void configureFileSystemViewAppearance(void);
    void createActions(void);
    void configureToolBar(void);

    QTableView *fileSystemView;
    QAction *goHomeAction;
    QAction *refreshAction;

    static const int initialWidth = 800;
    static const int initialHeight = 600;
};

#endif // MAINWINDOW_H
