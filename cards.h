#ifndef CARDS_H
#define CARDS_H

#include <QMainWindow>
#include <carditem.h>
#include <QDebug>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Cards; }
QT_END_NAMESPACE

class Cards : public QMainWindow
{
    Q_OBJECT

public:
    Cards(QWidget *parent = nullptr);
    ~Cards();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void Flip(int cardNum);

    void ResetAll();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::Cards *ui;
    CardItem* allCards;
    QPixmap defaultPixmap;
    int sum = 0;
    int counter = 0;
    QTimer* timer;
};
#endif // CARDS_H
