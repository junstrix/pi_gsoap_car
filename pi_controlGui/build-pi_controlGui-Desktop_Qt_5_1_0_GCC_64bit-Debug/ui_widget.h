/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *forward_pushButton;
    QPushButton *back_pushButton;
    QPushButton *left1_pushButton;
    QPushButton *left2_pushButton;
    QPushButton *right1_pushButton;
    QPushButton *right2_pushButton;
    QLineEdit *server_lineEdit;
    QPushButton *start_pushButton;
    QPushButton *stop_pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(400, 300);
        forward_pushButton = new QPushButton(Widget);
        forward_pushButton->setObjectName(QStringLiteral("forward_pushButton"));
        forward_pushButton->setGeometry(QRect(150, 70, 75, 23));
        back_pushButton = new QPushButton(Widget);
        back_pushButton->setObjectName(QStringLiteral("back_pushButton"));
        back_pushButton->setGeometry(QRect(150, 170, 75, 23));
        left1_pushButton = new QPushButton(Widget);
        left1_pushButton->setObjectName(QStringLiteral("left1_pushButton"));
        left1_pushButton->setGeometry(QRect(30, 100, 75, 23));
        left2_pushButton = new QPushButton(Widget);
        left2_pushButton->setObjectName(QStringLiteral("left2_pushButton"));
        left2_pushButton->setGeometry(QRect(30, 160, 75, 23));
        right1_pushButton = new QPushButton(Widget);
        right1_pushButton->setObjectName(QStringLiteral("right1_pushButton"));
        right1_pushButton->setGeometry(QRect(260, 100, 75, 23));
        right2_pushButton = new QPushButton(Widget);
        right2_pushButton->setObjectName(QStringLiteral("right2_pushButton"));
        right2_pushButton->setGeometry(QRect(260, 160, 75, 23));
        server_lineEdit = new QLineEdit(Widget);
        server_lineEdit->setObjectName(QStringLiteral("server_lineEdit"));
        server_lineEdit->setGeometry(QRect(20, 10, 191, 20));
        start_pushButton = new QPushButton(Widget);
        start_pushButton->setObjectName(QStringLiteral("start_pushButton"));
        start_pushButton->setGeometry(QRect(230, 10, 75, 23));
        stop_pushButton = new QPushButton(Widget);
        stop_pushButton->setObjectName(QStringLiteral("stop_pushButton"));
        stop_pushButton->setGeometry(QRect(260, 220, 81, 51));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        forward_pushButton->setText(QApplication::translate("Widget", "\345\211\215\350\277\233", 0));
        back_pushButton->setText(QApplication::translate("Widget", "\345\220\216\351\200\200", 0));
        left1_pushButton->setText(QApplication::translate("Widget", "\345\267\246\345\211\215\350\275\254\345\274\257", 0));
        left2_pushButton->setText(QApplication::translate("Widget", "\345\267\246\345\220\216\350\275\254\345\274\257", 0));
        right1_pushButton->setText(QApplication::translate("Widget", "\345\217\263\345\211\215\350\275\254\345\274\257", 0));
        right2_pushButton->setText(QApplication::translate("Widget", "\345\217\263\345\220\216\350\275\254\345\274\257", 0));
        server_lineEdit->setText(QApplication::translate("Widget", "192.168.1.109:8888", 0));
        start_pushButton->setText(QApplication::translate("Widget", "\345\220\257\345\212\250", 0));
        stop_pushButton->setText(QApplication::translate("Widget", "\345\201\234\346\255\242", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
