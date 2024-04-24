    #include "checkmark.h"
#include <QGraphicsScene>
#include <QFont>
#include "booking.h"
#include "Users.h"
#include "Exceptions.h"
CheckMark::CheckMark(Booking* inBookingView)
{
    rowIndex = 0;
    colIndex = -1;

    //since the checkmark is right before the first column of the seat chart

    QPixmap checkmarkPixmap(":/images/checkmark.png");
    checkmarkPixmap = checkmarkPixmap.scaledToWidth(40);
    checkmarkPixmap = checkmarkPixmap.scaledToHeight(40);
    setPixmap(checkmarkPixmap);

    currSeatText = new QGraphicsTextItem();
    currSeatText->setPos(100, 400);
    currSeatText->setFont(QFont("times", 16));
    currSeatText->setDefaultTextColor(Qt::blue);

    bookingView = inBookingView;


 // set the checkmark pixMAp
    // scale its width and hieght
     // set the pixmap


}

void CheckMark::keyPressEvent(QKeyEvent * event)
{

        if (event->key () == Qt::Key_Left)
    {
        if (colIndex>0)
            {
                colIndex--;
         setPos(x()-50, y());
        }
    }

else if (event->key () == Qt::Key_Right)
        {
        if(colIndex< sCOLS )
        {
         colIndex++;
         setPos(x()+50, y());
        }


        }

else if (event->key () == Qt::Key_Up)
    {
        if(rowIndex>0)
        {
         rowIndex--;
        setPos(x(), y()-50);
        }
    }
else if (event->key () == Qt::Key_Down)
        {
        if(rowIndex<sROWS)
        {
        rowIndex++;
        setPos(x(), y()+50);
        }
        }
  if (event->key () == Qt::Key_Space)
        {
        if(colIndex==-1)
        {
        return;
        }
        if(bookingView->checkSeatData(rowIndex,colIndex)==0)
        {
        bookingView->setSeatData(rowIndex,colIndex,1);
        bookingView->writeSeatsData();
        currSeatText->setDefaultTextColor(Qt::darkGreen);
        currSeatText->setPlainText("the seat is booked succesfully");

        }
        else
        {
        currSeatText->setDefaultTextColor(Qt::red);
        currSeatText->setPlainText("soory, seat is already booked ");
        }
        return;
        }



    // check on the right left up and down conditions and update the position of the checkmark

    // check if the user hits space
     // call the bookingView's functions to check and set the seat data


// start checking for the collision to update the seat images on the screen
}
