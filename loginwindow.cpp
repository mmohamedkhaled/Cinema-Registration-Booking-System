#include "loginwindow.h"
#include "ui_loginwindow.h"

#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"
#include "Exceptions.h"
#include <QMessageBox>
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    ui->labelError->setVisible(false);
}


LoginWindow::~LoginWindow()
{
    delete ui;
}

bool LoginWindow::isValidUser()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    if(username.isEmpty())
        throw EmptyText("username");
    else if (password.isEmpty())
        throw EmptyText("password");

    bool successfulLogin = false;
    for(int i = 0; i < usersCount; i++)
    {
        if (username == usernames[i] && password == passwords[i])
        {
            return true;
        }
    }

    return false;
}
void LoginWindow::on_pushButtonLogin_clicked()
{
    try {
        if(isValidUser())
        {
            WelcomeWindow* welcomeWindow = new WelcomeWindow(ui->lineEditUsername->text());
            welcomeWindow->show();
            this->close();
        }
        else
        ui->labelError->setVisible(true);


    }


    catch (EmptyText& em) {
        QMessageBox::warning(this,tr("Error!"),tr(em.what()));
    }


}


void LoginWindow::on_pushButtonRegister_clicked()
{
    hide();
    RegisterWindow* registerWindow = new RegisterWindow(this);
    registerWindow->show();
}

