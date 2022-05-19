#include "showreteta.h"
#include "ui_showreteta.h"
#include "tcpclient.h"
#include"login.h"
#include <QMessageBox>

showReteta::showReteta(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showReteta)
{
    ui->setupUi(this);
    ui->reviewTEXT->setPlaceholderText("Scrieti un review...");
     ui->addReview->setDisabled(true);
    ui->deleteButton->hide();
   connect(TCPClient::getInstance(), SIGNAL(photoData(QByteArray)), this, SLOT(addDataToPhoto(QByteArray)));


}

showReteta::~showReteta()
{
    delete ui;
}

void showReteta::completeTitlu(QString s)
{
    ui->Titlu->setText(s+" \t\t");

    QString ans=TCPClient::send_recieve("16/"+Login::username+'/');
    ans=ans.section('/',1,1);
    QStringList aux=s.split('\t');

    if(ans==aux[4])
    {
        ui->deleteButton->show();
    }

}

void showReteta::completeIngrediente(QStringList s)
{
    for(int i=0;i<s.size();i+=2)
    {
        ui->ListaIngrediente->append(s[i]+"\t"+s[i+1]);
    }
}

void showReteta::completeDescriere(QString s)
{
    ui->Descriere->setText(s);
}

void showReteta::completeNota(QString s)
{
    ui->Nota->setText("NOTA:\n"+s);
}

void showReteta::completeRecenzii(QStringList s)
{
    for(int i=0;i<s.size();i+=2)
    {
        ui->Recenzii->append(s[i]+" :"+"  "+s[i+1]);
    }
}

void showReteta::completeImagine()
{
    QString sendMessage("18/");
    QString name = ui->Titlu->text();
    QStringList toks = name.split('\t');
    for(int i =0;i<toks.size();i++)
    {
        if( toks[i].length() > 2)
        {
            sendMessage += toks[i]+'/';
        }
    }
    TCPClient::getInstance()->sendMessage(sendMessage);

    while(this->imagineReteta->isDone() == false)
    {

    }
    QImage img = this->imagineReteta->createPath();

    ui->label->setPixmap(QPixmap::fromImage(img, Qt::AutoColor));
}

void showReteta::verificareDrepturiStergere()
{
    QString nume_chef_logat=TCPClient::send_recieve("16/"+Login::username+'/');
    nume_chef_logat=nume_chef_logat.section('/',1,1);

    QString aux=ui->Titlu->text();
    QStringList numeReteta=aux.split("\t");

    if(nume_chef_logat==numeReteta[4])
    {
        ui->deleteButton->show();
    }

}

void showReteta::on_pushButton_clicked()
{
    QString send="12/"+Login::username+'/';
    QString aux=ui->Titlu->text();
    QStringList numeReteta=aux.split("\t");

    QString nume_RETETA=numeReteta[0];

    send+=nume_RETETA+'/'+numeReteta[4]+'/';
    QString msg=TCPClient::send_recieve(send);

    QMessageBox addFAV;

    if(msg.contains("DA"))
    {
         addFAV.setText("\n\tReteta adaugata la favorite!\t\n");
    }
    else
    {
        addFAV.setText("\n\tReteta este deja in lista de favorite!\t\n");
    }
    addFAV.exec();

}


void showReteta::on_addNota_editingFinished()
{
    QString sendNota="9/";
    QString aux=ui->Titlu->text();
    QStringList numeReteta=aux.split("\t");

    QString nume_RETETA=numeReteta[4];

    //sendNota+=nume_RETETA+'/';


    QString numeChef =numeReteta[0];

    sendNota+=numeChef+'/'+nume_RETETA+'/'+ui->addNota->text()+'/';

    QString ans=TCPClient::send_recieve(sendNota);

    if(ui->reviewTEXT->toPlainText().isEmpty())
    {
        ui->addReview->setDisabled(true);
    }


    if(ans.contains("succes"))
    {
        QMessageBox addNOTA;
        addNOTA.setText("\n\Ati adaugat o nota pentru reteta!\t\n");
    }

}


void showReteta::on_addReview_clicked()
{

    QString sendReview="8/";
    QString aux=ui->Titlu->text();
    QStringList numeReteta=aux.split("\t");

    QString nume_RETETA=numeReteta[4];

    //sendNota+=nume_RETETA+'/';


    QString numeChef =numeReteta[0];
    //numeChef.erase(numeChef.begin(),numeChef.begin()+6);



    sendReview+=numeChef+'/'+nume_RETETA+'/'+Login::username+'/'+ui->reviewTEXT->toPlainText()+'/';

    //8/numereteta/numechef/username/review

    QString ans=TCPClient::send_recieve(sendReview);


    if(ans.contains("succes"))
    {
        QMessageBox addNOTA;
        addNOTA.setText("\n\Ati adaugat un review pentru reteta!\t\n");
    }


}


void showReteta::on_reviewTEXT_textChanged()
{
    if(ui->reviewTEXT->toPlainText().isEmpty()==false)
    {
        ui->addReview->setDisabled(false);
    }
}

void showReteta::addDataToPhoto(QByteArray data)
{
    if(this->imagineReteta != nullptr)
    {
        this->imagineReteta->addData(data);
    }
}


void showReteta::on_deleteButton_clicked()
{
    QString send="10/";
    QString aux=ui->Titlu->text();
    QStringList numeReteta=aux.split("\t");

    QString nume_RETETA=numeReteta[0];

    send+=nume_RETETA+'/'+numeReteta[4]+'/';
    QString msg=TCPClient::send_recieve(send);

    QMessageBox MBox;

    if(msg.contains("DA"))
    {
        MBox.setText("\n\tReteta a fost stearsa!\t\n");
        if(MBox.Ok)
        {
            delete this;
        }
    }
    else
    {
        MBox.setText("\n\tReteta nu a putut fi stearsa!\t\n");
    }

    MBox.exec();
}


void showReteta::on_stergeFavorite_clicked()
{
    QString send="13/"+Login::username+'/';
    QString aux=ui->Titlu->text();
    QStringList numeReteta=aux.split("\t");

    QString nume_RETETA=numeReteta[0];

    send+=nume_RETETA+'/'+numeReteta[4]+'/';
    QString msg=TCPClient::send_recieve(send);

    QMessageBox MBox;

    if(msg.contains("DA"))
    {
        MBox.setText("\n\tReteta a fost stearsa din lista de favorite!\t\n");
    }
    else
    {
         MBox.setText("\n\tReteta nu se afla in lista de favorite\t\n");
    }

    MBox.exec();

}

