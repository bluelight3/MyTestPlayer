#include "myaudioplayer.h"
#include "ui_myaudioplayer.h"
#include "playthread.h"
#include "MyHelper.h"

MyAudioPlayer::MyAudioPlayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyAudioPlayer)
{
    ui->setupUi(this);

    this->setAcceptDrops(true);

    m_thread = new PlayThread();

    connect(m_thread,SIGNAL(duration(int,int)),this,SLOT(onDuration(int,int)));

    connect(m_thread,SIGNAL(seekOk()),this,SLOT(onSeekOk()));


    void duration(long currentMs,long destMs);        //播放时长

    m_thread->start();

    sliderSeeking =false;
}

MyAudioPlayer::~MyAudioPlayer()
{
    delete ui;
}

void MyAudioPlayer::on_btn_browse_clicked()
{
     QString audioPath = FileHelper::GetFileName("*.wav *.mp3");
     ui->line_audioPath->setText(audioPath);
}

void MyAudioPlayer::onSeekOk()
{
    sliderSeeking=false;
}

void MyAudioPlayer::onDuration(int currentMs,int destMs)      //时长
{
    static int currentMs1=-1,destMs1=-1;

    if(currentMs1==currentMs&&destMs1==destMs)
    {
        return;
    }

    currentMs1 = currentMs;
    destMs1   =  destMs;

    qDebug()<<"onDuration："<<currentMs<<destMs<<sliderSeeking;

    int currentSec = currentMs1 / 1000;
    int destSec = destMs1 / 1000;


    QString currentTime = QString("%1:%2:%3").arg(currentSec/3600,2,10,QChar('0')).arg(currentSec%3600/60,2,10,QChar('0')).arg(currentSec%60,2,10,QChar('0'));

    QString destTime = QString("%1:%2:%3").arg(destSec/3600,2,10,QChar('0')).arg(destSec%3600/60,2,10,QChar('0')).arg(destSec%60,2,10,QChar('0'));

    ui->label_duration->setText(currentTime+"/"+destTime);


    if(!sliderSeeking) //未滑动
    {
        ui->slider->setMaximum(destMs);
        ui->slider->setValue(currentMs);
    }

}



void MyAudioPlayer::on_btn_start_clicked()
{

    sliderSeeking=false;

    m_thread->play(ui->line_audioPath->text());

}


void MyAudioPlayer::on_btn_stop_clicked()
{
    m_thread->stop();
}

void MyAudioPlayer::on_btn_pause_clicked()
{
    m_thread->pause();
}

void MyAudioPlayer::on_btn_resume_clicked()
{
   m_thread->resume();
}


void MyAudioPlayer::on_slider_sliderPressed()
{
    sliderSeeking=true;
}

void MyAudioPlayer::on_slider_sliderReleased()
{

    m_thread->seek(ui->slider->value());

}
