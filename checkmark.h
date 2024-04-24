#ifndef CHECKMARK_H
#define CHECKMARK_H

#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include "booking.h"

class CheckMark : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    CheckMark(Booking* inBookingView);
    QGraphicsTextItem* currSeatText;

public slots:
    void keyPressEvent(QKeyEvent* event);
private:
    int rowIndex, colIndex;
    QGraphicsPixmapItem* previousItem;
    Booking* bookingView;
};

#endif // CHECKMARK_H





