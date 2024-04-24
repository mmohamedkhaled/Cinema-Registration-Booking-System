#include "welcomewindow.h"
#include "ui_welcomewindow.h"

#include <QPixmap>
#include "loginwindow.h"
#include "booking.h"
WelcomeWindow::WelcomeWindow(QString username, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QPixmap pix (":/images/welcome.jpg");
    int w = ui->labelWelcomePic->width();
    int h = ui->labelWelcomePic->height();
    ui->labelWelcomePic->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->labelUsername->setText("Hello " + username  + ", ");
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButton_clicked()
{
    hide();
    LoginWindow* loginWindow = new LoginWindow(this);
    loginWindow->show();
}


void WelcomeWindow::on_bookbutton_clicked()
{
    Booking* bookwindow = new Booking();
    bookwindow->show();
    this->close();
}

