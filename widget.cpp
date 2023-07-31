#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QDir>
#include <QUrl>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 实现播放音乐：首先在pro中添加multimedia模块
    // 创建output对象
    audioOutput = new QAudioOutput(this);
    // 创建媒体播放对象
    mediaPlayer = new QMediaPlayer(this);
    mediaPlayer->setAudioOutput(audioOutput);
    // 音量滑动条默认隐藏
    ui->volumnSlider->setVisible(false);

    // 信号和槽
    // 获取当前歌曲时长
    connect(mediaPlayer, &QMediaPlayer::durationChanged, this, [=] (qint64 duration) {
        ui->labelTotalTime->setText(QString("%1:%2").arg(duration/1000/60).arg(duration/1000%60));
        ui->playSlider->setRange(0, duration);
    });
    // 获取当前播放时长
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, [=] (qint64 pos) {
        ui->labelCurTime->setText(QString("%1:%2").arg(pos/1000/60,2,10,QChar('0')).arg(pos/1000%60,2,10,QChar('0')));
        ui->playSlider->setValue(pos);
    });
    // 拖动进度条，改变音乐播放进度
    connect(ui->playSlider, &QSlider::sliderMoved, mediaPlayer, QMediaPlayer::setPosition);
    /* ！可进一步实现点击进度条改变音乐播放进度！ */
    // 设置音量
    audioOutput->setVolume(0.5);    // 范围从0-1
}

Widget::~Widget()
{
    delete ui;
}

// 文件夹按钮
void Widget::on_pushButton_clicked()
{
    // 打开文对话框，让用户导入音乐所在目录
    // 打开一个已经存在的目录
    auto path = QFileDialog::getExistingDirectory(this, "选择文件夹", "");
    // 获取路径下所有mp3、wav文件
    QDir dir(path);
    auto musicList = dir.entryList(QStringList() << "*.mp3" << "*.wav");
    // 将音乐名称列表载入页面的listWidght中
    ui->listWidget->addItems(musicList);
    // 默认选中第一个音乐
    curIndex = 0;
    ui->listWidget->setCurrentRow(curIndex);
    // 保存音乐的完整路径
    for (auto &file : musicList) {
        playList.append(QUrl::fromLocalFile(path+'/'+file));
    }
    // 获取playList中歌曲数目
    playListSize = playList.size();
}

// 播放按钮
void Widget::on_pushButton_4_clicked()
{
    if (playList.empty()) {
        qInfo() << "No mp3 or wav file found!\n";
        return ;
    }
    /* ！存在bug： 歌曲在播放过程中无法切歌，只能先暂停之后才能切换歌曲！ */
    switch(mediaPlayer->playbackState()) {
    case QMediaPlayer::PlaybackState::StoppedState:     // 当前没有播放歌曲
    {
        // 点击按钮播放当前选中的音乐
        // 获取选中的行号
        curIndex = ui->listWidget->currentRow();
        // 播放对应下标的音乐
        mediaPlayer->setSource(playList[curIndex]);
        mediaPlayer->play();
        // 改变按钮样式为点击暂停
        ui->pushButton_4->setStyleSheet("QPushButton{image: url(:/icon/pause.png);}");
        break;
    }
    case QMediaPlayer::PlaybackState::PlayingState:     // 歌曲当前正在播放
        // 如果正在播放，点击按钮暂停音乐
        mediaPlayer->pause();
        // 改变按钮样式为点击播放
        ui->pushButton_4->setStyleSheet("QPushButton{image: url(:/icon/start.png);}");
        break;
    case QMediaPlayer::PlaybackState::PausedState:      // 歌曲当前正在暂停
        // 检查用户是否切换歌曲
        curIndex = ui->listWidget->currentRow();
        mediaPlayer->play();
        // 改变按钮样式为点击暂停
        ui->pushButton_4->setStyleSheet("QPushButton{image: url(:/icon/pause.png);}");
        break;
    }

}

// 切换上一首按钮
void Widget::on_pushButton_3_clicked()
{
    // 让listWidget循环选中上一行
    /* ！奇怪的bug：下边边这行代码括号里如果不加playListSize竟然能出现curIndex = -1！ */
    curIndex = (curIndex-1+playListSize)%playListSize;
    // listWidget循环选中上一行
    ui->listWidget->setCurrentRow(curIndex);
    // 播放器设置上一曲并播放
    mediaPlayer->setSource(playList[curIndex]);
    mediaPlayer->play();
    // 改变按钮样式为点击暂停
    ui->pushButton_4->setStyleSheet("QPushButton{image: url(:/icon/pause.png);}");
}

// 切换下一首按钮
void Widget::on_pushButton_5_clicked()
{
    // 让listWidget循环选中下一行
    curIndex = (curIndex+1)%playListSize;
    // listWidget循环选中下一行
    ui->listWidget->setCurrentRow(curIndex);
    // 播放器设置下一曲并播放
    mediaPlayer->setSource(playList[curIndex]);
    mediaPlayer->play();
    // 改变按钮样式为点击暂停
    ui->pushButton_4->setStyleSheet("QPushButton{image: url(:/icon/pause.png);}");
}

// listWidget双击改变选中行切歌
void Widget::on_listWidget_clicked(const QModelIndex &index)
{
    curIndex = index.row();
    // 播放器设置下一曲并播放
    mediaPlayer->setSource(playList[curIndex]);
    mediaPlayer->play();
    // 改变按钮样式为点击暂停
    ui->pushButton_4->setStyleSheet("QPushButton{image: url(:/icon/pause.png);}");
}

// 音量选项
void Widget::on_pushButton_6_clicked()
{
    if (ui->volumnSlider->isVisible()) {    // 若音量滑动条当前可见
        // 设置音量滑动条为不可见
        ui->volumnSlider->setVisible(false);
    } else {                                // 若音量滑动条当前不可见
        // 设置音量滑动条为可见
        ui->volumnSlider->setVisible(true);
    }
}

