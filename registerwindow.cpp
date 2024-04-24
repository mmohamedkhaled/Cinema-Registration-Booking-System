#include "registerwindow.h"
#include "ui_registerwindow.h"

#include "Users.h"
#include "welcomewindow.h"
#include "Exceptions.h"

#include<QMessageBox>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

}



RegisterWindow::~RegisterWindow()
{
    delete ui;
}
void RegisterWindow::setNewUser(QString username,QString password,int age)
{

    // ---------- Fields' Retrieval -----------

    QString retype = ui->lineEditRetype->text();
    QString month = ui->comboBoxMonth->currentText();
    QString day = ui->lineEditDay->text();
    QString year = ui->lineEditYear->text();

    bool male = ui->radioButtonMale->isChecked();
    bool female = ui->radioButtonFemale->isChecked();
    bool userAccount = ui->radioButtonUser->isChecked();
    bool adminAccount = ui->radioButtonAdmin->isChecked();
    bool actionGenre = ui->checkBoxAction->isChecked();
    bool comedyGenre = ui->checkBoxComedy->isChecked();
    bool romanceGenre = ui->checkBoxRomance->isChecked();
    bool dramaGenre = ui->checkBoxDrama->isChecked();
    bool horrorGenre = ui->checkBoxHorror->isChecked();
    bool otherGenre = ui->checkBoxOtherGenre->isChecked();

    // ---------- Errors' Checking -----------

    // Check all fields are entered
    if (username == "" || password == "" || retype == ""
        || month == "" || day == "" || year == ""
        || (!male && !female) || (!userAccount && !adminAccount)
        || (!actionGenre && !comedyGenre && !romanceGenre
            && !dramaGenre && !horrorGenre && !otherGenre))
    {
        throw EmptyText("fields exist");
    }


    // Check Username if existing
    for(int i = 0; i < usersCount; i++)
    {
        if (username == usernames[i])
        {
            throw DuplicateUser(username.toStdString());
        }
    }
    // Check re-type password
    if (password != retype)
    {
        throw PasswordMisMatch();
    }
    // Check age

    if (day.toInt() >31 || day.toInt()<=0)
        throw InvalidDay();
    if (2023-year.toInt() < 17)
        throw InvalidYear();



    // add new user
    usernames[usersCount] = username;
    passwords[usersCount] = password;
    ages[usersCount] = age;
    usersCount++;

    }
void RegisterWindow::on_pushButtonRegister_clicked()
{
        QString year = ui->lineEditYear->text();
        int age = 2023 - year.toInt();
        try{
            setNewUser(ui->lineEditUsername->text(),ui->lineEditPassword->text(),age);
            WelcomeWindow* welcomeWindow = new WelcomeWindow(ui->lineEditUsername->text());
            welcomeWindow->show();
            this->close();
        }
        catch (logic_error&e)
        {
            QMessageBox::warning(this,tr("Error!"),tr(e.what()));
        }


}

