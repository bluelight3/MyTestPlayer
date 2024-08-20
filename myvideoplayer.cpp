#include "myvideoplayer.h"
#include "ui_myvideoplayer.h"

MyVideoPlayer::MyVideoPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyVideoPlayer)
{
    ui->setupUi(this);
    QStringList urls;
    urls << "C://Users//Administrator//Desktop//gitcode//QWidgetDemo//video//build-playffmpeg-Desktop_Qt_5_14_2_MinGW_32_bit-Debug//debug//stream_chn0.h265";
    urls << "C://gl//码流或原始视频实例//码流//h265//1080p_30fps_h265.mp4";
    urls << "http://vfx.mtime.cn/Video/2021/11/16/mp4/211116131456748178.mp4";
    urls << "http://vd3.bdstatic.com/mda-jennyc5ci1ugrxzi/mda-jennyc5ci1ugrxzi.mp4";
    urls << "rtsp://admin:Admin123456@192.168.0.15:554/media/video1";
    ui->comboBox_url->addItems(urls);
    ui->comboBox_url->setCurrentIndex(0);

//    connect(&m_ffmpegThread,SIGNAL(duration(int,int)),this,SLOT(onDuration(int,int)));

}

MyVideoPlayer::~MyVideoPlayer()
{
    delete ui;
}

void MyVideoPlayer::on_btn_open_clicked()
{
    if (ui->btn_open->text() == "打开") {
        ui->btn_open->setText("关闭");
        QString url = ui->comboBox_url->currentText().trimmed();
        ui->playWidget->setUrl(url);
        ui->playWidget->open();
    } else {
        ui->btn_open->setText("打开");
        ui->playWidget->close();
    }

}

void MyVideoPlayer::on_btn_select_clicked()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (!fileName.isEmpty()) {
        ui->comboBox_url->addItem(fileName);
        ui->comboBox_url->lineEdit()->setText(fileName);
        if (ui->btn_open->text() == "打开") {
            on_btn_open_clicked();
        }
    }
}






void MyVideoPlayer::on_btn_pause_clicked()
{
    if (ui->btn_pause->text() == "暂停") {
        ui->btn_pause->setText("播放");
        QString url = ui->comboBox_url->currentText().trimmed();
        ui->playWidget->setUrl(url);
        ui->playWidget->open();
    } else {
        ui->btn_pause->setText("播放");
        ui->playWidget->close();
    }
}
