#include "resetpassword.h"
#include "ui_resetpassword.h"
#include "ui_login.h"
#include <QString>
#include "tcpclient.h"
#include"failedresetpassword.h"
#include <QMessageBox>


resetPassword::resetPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resetPassword)
{
    ui->setupUi(this);
    //ui->restrictiiParola->setVisible(false);
}

resetPassword::~resetPassword()
{
    delete ui;
}

void resetPassword::on_sendAnswerButtomn_clicked()
{
    QString data="4/"+ui->username->text()+"/"+ui->Answer->text()+'/'+ui->newPassword->text()+'/';
    QString ans=TCPClient::send_recieve(data);
    if(ans.contains("succes"))
    {
        QMessageBox msgSucces;

        //qDebug()<<"RASPUNS:"<<answer;
        msgSucces.setText("\n\tParola a fost schimbata cu succes\t\n");
        //delete this;
        msgSucces.exec();
    }
    else
    {
        FailedResetPassword* failed=new FailedResetPassword(nullptr);
        failed->show();
    }

    delete this;
}

