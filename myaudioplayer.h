#ifndef MYAUDIOPLAYER_H
#define MYAUDIOPLAYER_H

#include <QWidget>
#include "playthread.h"

namespace Ui {
class MyAudioPlayer;
}

class MyAudioPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MyAudioPlayer(QWidget *parent = nullptr);
    ~MyAudioPlayer();

    PlayThread *m_thread;


    bool sliderSeeking;      //滑动标志位,false:表示未seek,true:正在seek
private slots:
    void on_btn_browse_clicked();

    void on_btn_start_clicked();

    void on_btn_stop_clicked();

    void on_btn_pause_clicked();

    void on_btn_resume_clicked();

    void onDuration(int currentMs, int destMs);

    void onSeekOk();


    void on_slider_sliderPressed();

    void on_slider_sliderReleased();


private:
    Ui::MyAudioPlayer *ui;


};

#endif // MYAUDIOPLAYER_H
