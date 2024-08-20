#include "qtvideoplayer.h"
#include "ui_qtvideoplayer.h"
#include <QMediaPlayer>
#include <QVideoWidget>



QtVideoPlayer::QtVideoPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QtVideoPlayer)
{
    ui->setupUi(this);
    player=new QMediaPlayer(this);
    videoWidget=new QVideoWidget(this);
    videoWidget->resize(800,450);
    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl::fromLocalFile("C://gl//Qt_projects//myvideowidget//vtest.avi"));
    player->play();
    connect(player,&QMediaPlayer::positionChanged,this,&QtVideoPlayer::updatePosition);

    // 亮度
    ui->sli_bri->setValue(videoWidget->brightness());
    connect(ui->sli_bri,&QSlider::sliderMoved,videoWidget,&QVideoWidget::setBrightness);
    connect(videoWidget,&QVideoWidget::brightnessChanged,ui->sli_bri,&QSlider::setValue);
    // 对比度
    ui->sli_contra->setValue(videoWidget->contrast());
    connect(ui->sli_contra,&QSlider::sliderMoved,videoWidget,&QVideoWidget::setContrast);
    connect(videoWidget,&QVideoWidget::contrastChanged,ui->sli_contra,&QSlider::setValue);
    // 色相
    ui->sli_hue->setValue(videoWidget->hue());
    connect(ui->sli_hue,&QSlider::sliderMoved,videoWidget,&QVideoWidget::setHue);
    connect(videoWidget,&QVideoWidget::hueChanged,ui->sli_hue,&QSlider::setValue);

    // 饱和度
    ui->sli_bri->setValue(videoWidget->saturation());
    connect(ui->sli_satur,&QSlider::sliderMoved,videoWidget,&QVideoWidget::setSaturation);
    connect(videoWidget,&QVideoWidget::saturationChanged,ui->sli_satur,&QSlider::setValue);

}

QtVideoPlayer::~QtVideoPlayer()
{
    delete ui;
}

void QtVideoPlayer::updatePosition(qint64 position)
{
    ui->sli_moveVideo->setMaximum(player->duration()/1000);
    ui->sli_moveVideo->setValue(position/1000);
}
