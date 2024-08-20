#ifndef MYVIDEOPLAYER_H
#define MYVIDEOPLAYER_H

#include <QWidget>
#include "ffmpeg.h"

namespace Ui {
class MyVideoPlayer;
}

class MyVideoPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MyVideoPlayer(QWidget *parent = nullptr);
    ~MyVideoPlayer();

    FFmpegThread m_ffmpegThread;
private slots:
    void on_btn_select_clicked();

    void on_btn_open_clicked();

    void on_btn_pause_clicked();

private:
    Ui::MyVideoPlayer *ui;
};

#endif // MYVIDEOPLAYER_H
