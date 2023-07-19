#include "cards.h"
#include "ui_cards.h"

Cards::Cards(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cards)
{
    ui->setupUi(this);
    allCards = new CardItem[4];
    allCards[0].value = 1;
    allCards[0].cardPixmap = QPixmap(":/new/prefix1/A.jpeg");
    allCards[1].value = 2;
    allCards[1].cardPixmap = QPixmap(":/new/prefix1/2.jpeg");
    allCards[2].value = 3;
    allCards[2].cardPixmap = QPixmap(":/new/prefix1/3.jpeg");
    allCards[3].value = 4;
    allCards[3].cardPixmap = QPixmap(":/new/prefix1/4.jpeg");
    QLabel cards[4];
    defaultPixmap = QPixmap(":/new/prefix1/Unflipped.jpeg");
}

Cards::~Cards()
{
    delete ui;
    delete [] allCards;
}

void Cards::Flip(int cardNum){
    QLabel* cardUI;
    int val = allCards[cardNum].value;
    bool isFlipped = allCards[cardNum].isFlipped;
    QPixmap cardPixmap = allCards[cardNum].cardPixmap;

    switch(cardNum){
        case 0:
            cardUI = ui->Card1;
            break;
        case 1:
            cardUI = ui->Card2;
            break;
        case 2:
            cardUI = ui->Card3;
            break;
        case 3:
            cardUI = ui->Card4;
            break;
    }

    if (isFlipped){
        isFlipped = !isFlipped;
        sum -= val;
        cardUI->setPixmap(defaultPixmap);
    }
    else{
        isFlipped = !isFlipped;
        sum += val;
        cardUI->setPixmap(cardPixmap);
    }
    allCards[cardNum].isFlipped = isFlipped;

}

void Cards::ResetAll(){
    sum = 0;
    counter = 0;
    ui->Card1->setPixmap(defaultPixmap);
    ui->Card2->setPixmap(defaultPixmap);
    ui->Card3->setPixmap(defaultPixmap);
    ui->Card4->setPixmap(defaultPixmap);
    for (int i=0; i < 4; i++){
        allCards[i].isFlipped = false;
    }
    ui->textEdit->setText("");

    if (timer->isActive()){
        timer->stop();
    }
}

void Cards::on_pushButton_clicked()
{
    Flip(0);
}

void Cards::on_pushButton_2_clicked()
{
    Flip(1);
}

void Cards::on_pushButton_3_clicked()
{
    Flip(2);
}

void Cards::on_pushButton_4_clicked()
{
    Flip(3);
}

void Cards::on_pushButton_5_clicked() //Even
{
    Flip(1);
    Flip(3);
}

void Cards::on_pushButton_6_clicked() //Odd
{
    Flip(0);
    Flip(2);
}

void Cards::on_pushButton_7_clicked() //Reset
{
    ResetAll();
}

void Cards::on_pushButton_8_clicked() //Sum
{
    QString sumString = QString::number(sum);
    ui->textEdit->setText(sumString);
}

void Cards::on_pushButton_9_clicked() //Start
{
    if (timer->isActive()){ return; }

    ResetAll();

    timer = new QTimer();
    timer->setInterval(1000);
    connect(timer, &QTimer::timeout, this, [=](){
        Flip(counter);
        counter++;
        if (counter > 3){
            timer->stop();
        }
    });
    timer->start();
}

void Cards::on_pushButton_10_clicked() //Stop
{
    if (timer->isActive()){
        timer->stop();
    }
}
