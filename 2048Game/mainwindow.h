#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamelogic.h"
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTextBrowser>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initAll();
    void showMessage();
    void showBroad();
    void keyPressEvent(QKeyEvent *event);
    void changeColor(QLabel* label, int num);

private slots:
    void on_btnStart_clicked();
    void on_btnExit_clicked();

private:
    Ui::MainWindow *ui;
    GameLogic *gamelogic;
};

#endif // MAINWINDOW_H
