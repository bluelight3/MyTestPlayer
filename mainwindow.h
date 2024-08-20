#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qtvideoplayer.h"
#include "myaudioplayer.h"
#include "myvideoplayer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QtVideoPlayer* m_qtVideoPlayer;
    MyAudioPlayer* m_myAudioPlayer;
    MyVideoPlayer* m_myVideoPlayer;

private slots:

    void on_btn_qtVideoPlayer_clicked();

    void on_btn_myAudioPlayer_clicked();

    void on_btn_myVideoPlayer_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
