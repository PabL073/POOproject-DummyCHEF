#include "login.h"
#include "ui_login.h"
#include "tcpclient.h"
#include "firstscreen.h"
#include "mainpage.h"
#include "incorrectcredentials.h"
#include "resetpassword.h"
#include<QMessageBox>

QString Login:: tipCont="";
QString Login:: username="";
QString Login:: password="";

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("DummyCHEF_LOGARE");
    ui->incorrect_label->setVisible(false);
}

Login::~Login()
{
    delete ui;
}



// QString Login::getUsername()
///{
 //   return ui->lineEdit->text();
//}

//QString Login::getPassword()
//{
//    return ui->lineEdit_2->text();
//}




void Login::on_loginButton_clicked()
{
    //string username, password
    QString loginData="0/"+ui->lineEdit->text()+'/'+ui->lineEdit_2->text()+"/";
    //QByteArray serverMessage = loginData.toUtf8();
    //send
    QString answer=TCPClient::send_recieve(loginData);
    //recieve

    if(answer.contains("DA"))
    {
        if(answer[5]=='L')
        {
            Login::tipCont='L';
        }
        if(answer[5]=='C')
        {
            Login::tipCont='C';
        }
        //::setUsername(ui->lineEdit->text());
        username=ui->lineEdit->text();
        mainpage * Screen=new mainpage(nullptr);
        Screen->show();
        this->hide();

    }

    //
    else
    {

            QMessageBox IncorrectCredentials;
            IncorrectCredentials.setText("\n\tUsername sau parola gresite.Incercati din nou.\t\n");
            IncorrectCredentials.exec();

    }

    qDebug()<<Login::tipCont;
}


void Login::on_resetare_parola_button_clicked()
{
    resetPassword* s=new resetPassword(nullptr);
    s->show();
}


void Login::on_backButton_clicked()
{
    delete this;
    FirstScreen *back=new FirstScreen(nullptr);
    back->show();
}

