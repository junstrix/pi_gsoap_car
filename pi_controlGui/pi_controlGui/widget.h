#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:
    void on_forward_pushButton_clicked();

    void on_start_pushButton_clicked();

    void on_stop_pushButton_clicked();

    void on_back_pushButton_clicked();

    void on_left1_pushButton_clicked();

    void on_right1_pushButton_clicked();

    void on_left2_pushButton_clicked();

    void on_right2_pushButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
