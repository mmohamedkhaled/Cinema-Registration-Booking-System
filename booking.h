#ifndef BOOKING_H
#define BOOKING_H



#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
class CheckMark;


namespace Ui {
class Booking;
}

class Booking : public QDialog
{
    Q_OBJECT

public:
    explicit Booking(QWidget *parent = nullptr);
    ~Booking();

    int  checkSeatData(int rowIndex, int colIndex); // a getter
    void setSeatData(int rowIndex, int colIndex, int data); // a setter and also updates image
    void readSeatsData();  // reads seats' data from file
    void setSeatsImages(); // sets seats' images from seats' data
    void writeSeatsData(); // writes seats' data to file

    QGraphicsScene* scene;

private:
    Ui::Booking *ui;
    int seatsData[6][6]; // 0 available, 1 booked
    QGraphicsPixmapItem seatsImages[6][6];
    CheckMark* checkmark;

};



#endif // BOOKING_H
