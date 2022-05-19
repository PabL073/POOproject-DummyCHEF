#include "register.h"
#include "ui_register.h"
#include <QMessageBox>
#include"fieldscompleted.h"
#include "tcpclient.h"

Register::Register(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("DummyCHEF_Inregistrare");
    ui->label_9->setVisible(false);
    ui->label_10->setVisible(false);
    ui->label_11->setVisible(false);
    ui->finalizare_inregistrare->setDisabled(true);
}

Register::~Register()
{
    delete ui;
}

void Register::check_pass()
{
    if(ui->parola->text()== ui->parola2->text())
    {
        ui->label_9->setVisible(false);
    }

}

bool Register::checkPasssword(QString s)
{
    QString ALPHA="QWERTYUIOPASDFGHJKLZXCVBNM";
    QString alpha="qwertyuiopasdfghjklzxcvbnm";
    QString numbers="0123456789";
    QString specialC="?!*%$#.,";

    bool hasALPHA=false;
    bool hasalpha=false;
    bool hasNumbers=false;
    bool hasSpecialC=false;
    bool isCorrect=false;
    bool verify=false;

    for(int i =0; i<s.length(); i++)
    {
        verify=false;
        if (ALPHA.contains(s[i]))
        {
            hasALPHA=true;
            verify=true;
        }
        if (alpha.contains(s[i]))
        {
            hasalpha=true;
            verify=true;
        }

        if (numbers.contains(s[i]))
        {
            hasNumbers=true;
            verify=true;
        }
        if (specialC.contains(s[i]))
        {
            hasSpecialC=true;
            verify=true;
        }

        if (verify=false)
        {
            return false;
        }
    }


    if(s.length()>=8 && hasALPHA==true && hasalpha==true && hasNumbers==true && hasSpecialC==true)
    {
        isCorrect=true;
    }

    return isCorrect;
}

bool Register::fieldsCompleted()
{
    if(ui->prenume->text().length()!=0&& ui->nume->text().length()!=0 && ui->email->text().length()!=0
            &&ui->parola->text().length()!=0 && ui->parola2->text().length()!=0
            &&ui->SecurityQuestion->text().length()!=0
            && (ui->contChef->isChecked()|| ui->contLearner->isChecked())
            && ui->termeni_conditii_CheckBox->isChecked()
        )
    {
        return true;
    }

    return false;
}

void Register::on_finalizare_inregistrare_clicked()
{
        QString RegisterData="3/"+ui->nume->text()+'/'+ui->prenume->text()+'/'+ui->username->text()+'/'+
                ui->email->text()+'/'+ui->parola->text()+'/';

        if(ui->contLearner->isChecked())
        {
            RegisterData+="L/";
        }
        else
        {
            RegisterData+="C/";
        }
        RegisterData+=ui->SecurityQuestion->text()+"/";

        QString answer= TCPClient::send_recieve(RegisterData);

        if(answer.contains("DA"))
        {
            QMessageBox mesaj_inregistrareFinalizata;

            //qDebug()<<"RASPUNS:"<<answer;
            mesaj_inregistrareFinalizata.setText("\n\t\t\t\nCont creat cu succes!\t\t\n");
            delete this;
            mesaj_inregistrareFinalizata.exec();
        }
      //else



    //mesaj_inregistrareFinalizata.setText("\n\t\t\t\n------------------\t\t\n");


}




void Register::on_parola_editingFinished()
{
    bool isGood=checkPasssword(ui->parola->text());
    if (isGood)
    {
        ui->label_12->setVisible(false);
    }
}


void Register::on_parola2_editingFinished()
{
     this->check_pass();
}



void Register::on_termeni_conditii_CheckBox_stateChanged(int arg1)
{
    bool check=false;


    while(!check)
    {
        if(fieldsCompleted()&& checkPasssword(ui->parola->text()))
        {
                check=true;
               ui->finalizare_inregistrare->setDisabled(false);

        }
    }
}



void Register::on_parola_textChanged(const QString &arg1)
{
    ui->label_12->setVisible(true);
    on_parola_editingFinished();
}


void Register::on_parola_selectionChanged()
{
    ui->label_12->setVisible(true);
    on_parola_editingFinished();
}


void Register::on_parola2_selectionChanged()
{
    ui->label_9->setVisible(true);
    check_pass();
}


void Register::on_parola2_textEdited(const QString &arg1)
{
    ui->label_9->setVisible(true);
    check_pass();
}


void Register::on_email_editingFinished()
{
    ui->label_10->setVisible(false);
    QString msg="2/"+ui->email->text()+"/";
    QString ans=TCPClient::send_recieve(msg);
    if (ans.contains("folosit"))
    {
        ui->label_10->setVisible(true);
    }
}




void Register::on_username_editingFinished()
{
    ui->label_11->setVisible(false);
    QString msg="1/"+ui->username->text()+"/";
    QString ans=TCPClient::send_recieve(msg);
    if (ans.contains("utilizat"))
    {
        ui->label_11->setVisible(true);
    }
}

