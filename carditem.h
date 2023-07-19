#ifndef CARDITEM_H
#define CARDITEM_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class CardItem
{
public:
    CardItem();
    bool isFlipped = false;
    QPixmap cardPixmap;
    int value;
};

#endif // CARDITEM_H
