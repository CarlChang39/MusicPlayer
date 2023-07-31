#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QAudioOutput>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_6_clicked();

    void changeVolumn();        // 自定义槽函数控制音量

private:
    Ui::Widget *ui;
    QList<QUrl> playList;       // 播放列表
    QAudioOutput *audioOutput;
    QMediaPlayer *mediaPlayer;

    int playListSize;           // 播放列表歌曲数目
    int curIndex;               // 当前歌曲索引
    int lastIndex;              // 上一首歌曲索引
};
#endif // WIDGET_H
