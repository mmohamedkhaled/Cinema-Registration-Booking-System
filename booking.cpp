#include "booking.h"
#include "ui_booking.h"

#include "Users.h"
#include "checkmark.h"


Booking::Booking(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Booking)
{
    ui->setupUi(this);
    // 1- set scene and view -------------------------------------
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 480, 500);
    ui->seatChart->setFixedSize(480, 500);
    ui->seatChart->setScene(scene);


    // 2- read seats data from file ------------------------------
    readSeatsData();


    // 3- set seats images from seats data and add to scene -----------------------
    setSeatsImages();

    // 4- add the checkmark to scene -----------------------
   checkmark = new CheckMark(this);
   checkmark->setPos(50, 50);
   scene->addItem(checkmark);
   scene->addItem(checkmark->currSeatText);


    // 5- set the focus on checkmark -----------------------
   checkmark->setFlag(QGraphicsItem::ItemIsFocusable);
   checkmark->setFocus();

   // 6. Show the View
   ui->seatChart->show();
}


int Booking::checkSeatData(int rowIndex, int colIndex)
{
    return seatsData[rowIndex][colIndex];
}

void Booking::setSeatData(int rowIndex, int colIndex, int data)
{
    seatsData[rowIndex][colIndex] = data;//In case of booking you need to set it.

    if (data == 0)
    {
        QPixmap availablePixmap(":/images/available.PNG");
        availablePixmap = availablePixmap.scaledToWidth(40);
        availablePixmap = availablePixmap.scaledToHeight(40);
        seatsImages[rowIndex][colIndex].setPixmap(availablePixmap);
    }
    else
    {
        QPixmap bookedPixmap(":/images/booked.PNG");
        bookedPixmap = bookedPixmap.scaledToWidth(40);
        bookedPixmap = bookedPixmap.scaledToHeight(40);
        seatsImages[rowIndex][colIndex].setPixmap(bookedPixmap);
    }
}

void Booking::readSeatsData()
{
    QFile file(":/textfiles/seatsData.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    QString input;
    for (int i = 0; i < sROWS; i++)
    {
        for (int j = 0; j < sCOLS; j++)
        {
            stream >> input;
            seatsData[i][j] = input.toInt();
        }
    }
    file.close();
}

void Booking::setSeatsImages()
{
    // fill the SeatsImages array
    int currX = 100, currY = 50;
    for (int i = 0; i < sROWS; i++)
    {

        for (int j = 0; j < sCOLS; j++)
        {
            setSeatData(i, j, seatsData[i][j]);
            seatsImages[i][j].setPos(currX, currY);
            scene->addItem(&seatsImages[i][j]);
            currX += 50;
        }
        currX = 100;
        currY += 50;
    }
}

void Booking::writeSeatsData()
{
    QFile file(":/textfiles/seatsData.txt"); //adjust to the path of your file in your computer
    file.open(QIODevice::WriteOnly | QIODevice::Text); // chose the mode of opening to write text
    QTextStream stream(&file); // link the writing stream to your file

    for (int i = 0; i < sROWS; i++)
    {
        for (int j = 0; j < sCOLS; j++)
        {
            stream << (QString::number(seatsData[i][j]) + " "); // write the data after converting it to a QString
        }
        stream << "\n";//add a new line after every row
    }
    file.close(); //close your file when you're done.

}



Booking::~Booking()
{
    delete ui;
}
