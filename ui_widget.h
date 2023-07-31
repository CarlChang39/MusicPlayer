/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QListWidget *listWidget;
    QSlider *playSlider;
    QSlider *volumnSlider;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelCurTime;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTotalTime;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(405, 651);
        widget = new QWidget(Widget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(11, 576, 371, 64));
        widget->setMinimumSize(QSize(0, 64));
        widget->setMaximumSize(QSize(16777215, 64));
        widget->setStyleSheet(QString::fromUtf8("*{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgb(0, 85, 255);\n"
"}"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(32, 32));
        pushButton->setMaximumSize(QSize(32, 32));
        pushButton->setBaseSize(QSize(0, 0));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/icon/folder.png);"));
        pushButton->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(32, 32));
        pushButton_2->setMaximumSize(QSize(32, 32));
        pushButton_2->setBaseSize(QSize(0, 0));
        pushButton_2->setStyleSheet(QString::fromUtf8("image: url(:/icon/playlist.png);"));
        pushButton_2->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(32, 32));
        pushButton_3->setMaximumSize(QSize(32, 32));
        pushButton_3->setBaseSize(QSize(0, 0));
        pushButton_3->setStyleSheet(QString::fromUtf8("image: url(:/icon/lastSong.png);"));
        pushButton_3->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(32, 32));
        pushButton_4->setMaximumSize(QSize(32, 32));
        pushButton_4->setBaseSize(QSize(0, 0));
        pushButton_4->setStyleSheet(QString::fromUtf8("image: url(:/icon/start.png);"));
        pushButton_4->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(32, 32));
        pushButton_5->setMaximumSize(QSize(32, 32));
        pushButton_5->setBaseSize(QSize(0, 0));
        pushButton_5->setStyleSheet(QString::fromUtf8("image: url(:/icon/nextSong.png);"));
        pushButton_5->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(32, 32));
        pushButton_6->setMaximumSize(QSize(32, 32));
        pushButton_6->setBaseSize(QSize(0, 0));
        pushButton_6->setStyleSheet(QString::fromUtf8("image: url(:/icon/volume.png);"));
        pushButton_6->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_6);

        listWidget = new QListWidget(Widget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(11, 11, 371, 471));
        playSlider = new QSlider(Widget);
        playSlider->setObjectName("playSlider");
        playSlider->setGeometry(QRect(11, 551, 371, 18));
        playSlider->setOrientation(Qt::Horizontal);
        volumnSlider = new QSlider(Widget);
        volumnSlider->setObjectName("volumnSlider");
        volumnSlider->setGeometry(QRect(360, 460, 18, 160));
        volumnSlider->setOrientation(Qt::Vertical);
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 490, 371, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelCurTime = new QLabel(horizontalLayoutWidget);
        labelCurTime->setObjectName("labelCurTime");

        horizontalLayout_2->addWidget(labelCurTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labelTotalTime = new QLabel(horizontalLayoutWidget);
        labelTotalTime->setObjectName("labelTotalTime");

        horizontalLayout_2->addWidget(labelTotalTime);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        labelCurTime->setText(QString());
        labelTotalTime->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
