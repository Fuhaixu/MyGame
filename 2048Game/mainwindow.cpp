#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    gamelogic=new GameLogic;
    ui->setupUi(this);
    showBroad();
    setWindowTitle("2048游戏");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initAll(){
    gamelogic->initAll();
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    qDebug()<<event->key();
    if(!gamelogic->getGameStart())return;
    switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        gamelogic->process(CMD_UP);
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        gamelogic->process(CMD_DOWN);
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        gamelogic->process(CMD_LEFT);
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        gamelogic->process(CMD_RIGHT);
        break;
    }
    showBroad();
    showMessage();
    switch (gamelogic->judge()) {
    case STAT_PROCESS:
        break;
    case STAT_WIN:
        QMessageBox::information(NULL,"2048","大吉大利，今晚吃鸡！"); break;
    case STAT_LOSE:
        QMessageBox::information(NULL,"2048","再接再厉，永不放弃！"); break;
    }
}

void MainWindow::showMessage(){
    ui->label_showGrade->setText(QString::number(gamelogic->getGrade()));
    ui->label_showGradeBasic->setText(QString::number(gamelogic->getGradeBasic()));
    ui->label_GradeUp->setText(QString::number(gamelogic->getGradeUp()));
    ui->label_Step->setText(QString::number(gamelogic->getStep()));
}

void MainWindow::showBroad(){
    if(gamelogic->getData(0,0))
        ui->label_1->setText(QString::number(gamelogic->getData(0,0)));
    else ui->label_1->setText("");
    if(gamelogic->getData(0,1))
        ui->label_2->setText(QString::number(gamelogic->getData(0,1)));
    else ui->label_2->setText("");
    if(gamelogic->getData(0,2))
        ui->label_3->setText(QString::number(gamelogic->getData(0,2)));
    else ui->label_3->setText("");
    if(gamelogic->getData(0,3))
        ui->label_4->setText(QString::number(gamelogic->getData(0,3)));
    else ui->label_4->setText("");

    changeColor(ui->label_1,gamelogic->getData(0,0));
    changeColor(ui->label_2,gamelogic->getData(0,1));
    changeColor(ui->label_3,gamelogic->getData(0,2));
    changeColor(ui->label_4,gamelogic->getData(0,3));


    if(gamelogic->getData(1,0))
        ui->label_5->setText(QString::number(gamelogic->getData(1,0)));
    else ui->label_5->setText("");
    if(gamelogic->getData(1,1))
        ui->label_6->setText(QString::number(gamelogic->getData(1,1)));
    else ui->label_6->setText("");
    if(gamelogic->getData(1,2))
        ui->label_7->setText(QString::number(gamelogic->getData(1,2)));
    else ui->label_7->setText("");
    if(gamelogic->getData(1,3))
        ui->label_8->setText(QString::number(gamelogic->getData(1,3)));
    else ui->label_8->setText("");
    changeColor(ui->label_5,gamelogic->getData(1,0));
    changeColor(ui->label_6,gamelogic->getData(1,1));
    changeColor(ui->label_7,gamelogic->getData(1,2));
    changeColor(ui->label_8,gamelogic->getData(1,3));

    if(gamelogic->getData(2,0))
        ui->label_9->setText(QString::number(gamelogic->getData(2,0)));
    else ui->label_9->setText("");
    if(gamelogic->getData(2,1))
        ui->label_10->setText(QString::number(gamelogic->getData(2,1)));
    else ui->label_10->setText("");
    if(gamelogic->getData(2,2))
        ui->label_11->setText(QString::number(gamelogic->getData(2,2)));
    else ui->label_11->setText("");
    if(gamelogic->getData(2,3))
        ui->label_12->setText(QString::number(gamelogic->getData(2,3)));
    else ui->label_12->setText("");
    changeColor(ui->label_9,gamelogic->getData(2,0));
    changeColor(ui->label_10,gamelogic->getData(2,1));
    changeColor(ui->label_11,gamelogic->getData(2,2));
    changeColor(ui->label_12,gamelogic->getData(2,3));

    if(gamelogic->getData(3,0))
        ui->label_13->setText(QString::number(gamelogic->getData(3,0)));
    else ui->label_13->setText("");
    if(gamelogic->getData(3,1))
        ui->label_14->setText(QString::number(gamelogic->getData(3,1)));
    else ui->label_14->setText("");
    if(gamelogic->getData(3,2))
        ui->label_15->setText(QString::number(gamelogic->getData(3,2)));
    else ui->label_15->setText("");
    if(gamelogic->getData(3,3))
        ui->label_16->setText(QString::number(gamelogic->getData(3,3)));
    else ui->label_16->setText("");
    changeColor(ui->label_13,gamelogic->getData(3,0));
    changeColor(ui->label_14,gamelogic->getData(3,1));
    changeColor(ui->label_15,gamelogic->getData(3,2));
    changeColor(ui->label_16,gamelogic->getData(3,3));
}

void MainWindow::changeColor(QLabel *label, int num){
    label->setAlignment(Qt::AlignCenter);
    switch (num) {
        case 2:    label->setStyleSheet("background-color: rgb(238,228,218);"
                                       "font:bold 75 30pt ""微软雅黑"""); break;
        case 4:    label->setStyleSheet("background-color: rgb(237,224,200);"
                                       "font:bold 75 30pt ""微软雅黑"""); break;
        case 8:    label->setStyleSheet("background-color: rgb(242,177,121);"
                                       "font:bold 75 30pt ""微软雅黑"""); break;
        case 16:   label->setStyleSheet("background-color: rgb(245,150,100);"
                                       "font:bold 75 30pt ""微软雅黑"""); break;
        case 32:   label->setStyleSheet("background-color: rgb(245,125,95);"
                                       "font:bold 75 30pt ""微软雅黑"""); break;
        case 64:   label->setStyleSheet("background-color: rgb(245,95,60);"
                                       "font:bold 75 30pt ""微软雅黑"""); break;
        case 128:  label->setStyleSheet("background-color: rgb(237,207,114);"
                                       "font:bold 75 25pt ""微软雅黑"""); break;
        case 256:  label->setStyleSheet("background-color: rgb(237,204,97);"
                                       "font:bold 75 25pt ""微软雅黑"""); break;
        case 512:  label->setStyleSheet("background-color: rgb(237,204,97);"
                                       "font:bold 75 25pt ""微软雅黑"""); break;
        case 1024: label->setStyleSheet("background-color: rgb(237,204,97);"
                                       "font:bold 75 20pt ""微软雅黑"""); break;
        case 2048: label->setStyleSheet("background-color: rgb(237,204,97);"
                                       "font:bold 75 20pt ""微软雅黑"""); break;
        default:   label->setStyleSheet("background-color: rgb(238,228,218);"
                                       "font:bold 75 40pt ""微软雅黑"""); break;
    }
}


void MainWindow::on_btnStart_clicked()
{
    ui->btnStart->setText("重新开始");
    initAll();
    gamelogic->createNum();
    gamelogic->createNum();
    gamelogic->setGameStart(true);

    showBroad();
    showMessage();
}

void MainWindow::on_btnExit_clicked()
{
    this->close();
}
