#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtvideoplayer.h"
#include "MyHelper.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_qtVideoPlayer = new QtVideoPlayer();
    m_myAudioPlayer = new MyAudioPlayer();
    m_myVideoPlayer = new MyVideoPlayer();
    FormHelper::FormOnlyCloseButton(m_qtVideoPlayer);
    FormHelper::FormOnlyCloseButton(m_myAudioPlayer);
    FormHelper::FormOnlyCloseButton(m_myVideoPlayer);
}

MainWindow::~MainWindow()
{
    delete m_qtVideoPlayer;
    delete m_myAudioPlayer;
    delete m_myVideoPlayer;
    delete ui;
}


void MainWindow::on_btn_qtVideoPlayer_clicked()
{
    m_qtVideoPlayer->show();
}

void MainWindow::on_btn_myAudioPlayer_clicked()
{
    m_myAudioPlayer->show();
}

void MainWindow::on_btn_myVideoPlayer_clicked()
{
    m_myVideoPlayer->show();
}

void MainWindow::on_pushButton_clicked()
{
    QString qstr_testMessage = "这是一条帮助信息";
    MyHelper::ShowMessageBoxInfo(qstr_testMessage);
}
