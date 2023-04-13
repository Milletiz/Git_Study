#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QDockWidget>
#include<QLabel>
#include<QMdiArea>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    //获取CPU信息
//    const QString getMemory();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initWindow();

    QMdiArea *mdiArea;

};

#endif // MAINWINDOW_H
