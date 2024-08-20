#ifndef QTVIDEOPLAYER_H
#define QTVIDEOPLAYER_H

#include <QWidget>

class QMediaPlayer;
class QVideoWidget;

namespace Ui {
class QtVideoPlayer;
}

class QtVideoPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit QtVideoPlayer(QWidget *parent = nullptr);
    ~QtVideoPlayer();

private:
    Ui::QtVideoPlayer *ui;
    QMediaPlayer* player;
    QVideoWidget* videoWidget;


private slots:
    void updatePosition(qint64 position);

};

#endif // QTVIDEOPLAYER_H
