#include "mainpage.h"
#include "ui_mainpage.h"
#include "addreteta.h"
#include "firstscreen.h"
#include"tcpclient.h"
#include"login.h"
#include "showreteta.h"

mainpage::mainpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainpage)
{
    ui->setupUi(this);
    qDebug()<<"/n"<<Login::tipCont;
    if(Login::tipCont=='L')
    {
        ui->addReteta->setDisabled(true);
        QWidget::setWindowTitle("Utilizator LEARNER");
    }

    if(Login::tipCont=='C')
    {
        QWidget::setWindowTitle("Utilizator CHEF");
    }

//setez scrisul din campul de cautare
    ui->searchBox->setPlaceholderText("Căutați numele rețetei...");
    ui->searchBox_2->setPlaceholderText("Cautati numele chefului...");

    // setez backgroundul butonului de search
    QPixmap pixmap(":/img/da.jpg");
    QIcon ButtonIcon(pixmap);
    ui->searchButtomn->setIcon(ButtonIcon);
    ui->searchButtomn->setIconSize(ui->searchButtomn->size());
    ui->searchButtonNume->setIcon(ButtonIcon);
    ui->searchButtonNume->setIconSize(ui->searchButtomn->size());


//setez backgroundul butonului de favorite

    QPixmap fav(":/img/favorites.png");
    QIcon FAVbutton(fav);
    ui->favoritesButton->setIcon(FAVbutton);
    ui->favoritesButton->setIconSize(ui->favoritesButton->size());


}

mainpage::~mainpage()
{
    delete ui;
}

void mainpage::on_addReteta_clicked()
{
    addReteta* Query= new addReteta(nullptr);
    Query->show();
}


void mainpage::on_logoutButton_clicked()
{
    delete this;
    FirstScreen *S=new FirstScreen(nullptr);
    S->show();

}



void mainpage::on_searchButtomn_clicked()
{
    ui->listaCautari->clear();
    QString searchedItem="5/"+ui->searchBox->toPlainText()+'/';
    QString msg=TCPClient::send_recieve(searchedItem);
    QStringList lista=msg.split('/');

    for(int i=1;i+1<lista.size();i+=2)
    {
        ui->listaCautari->addItem(lista[i]+"\t\t\t\t"+lista[i+1]+'\t');
    }

}


void mainpage::on_searchButtonNume_clicked()
{
    ui->listaCautari->clear();
    QString searchedItem="6/"+ui->searchBox_2->toPlainText()+'/';
    QString msg=TCPClient::send_recieve(searchedItem);
    QStringList lista=msg.split('/');


    for(int i=1;i+1<lista.size();i+=2)
    {
         ui->listaCautari->addItem(lista[i]+"\t\t\t\t"+ui->searchBox_2->toPlainText()+'\t');
    }
}


void mainpage::on_favoritesButton_clicked()
{
    QString msg="11/"+Login::username+"/";
    QString ans=TCPClient::send_recieve(msg);

    ui->listaCautari->clear();
    if(ans.contains("invalid"))
    {
        ui->listaCautari->addItem("\n\t\tLista de favorite este goala!\n");

    }
    else
    {
        QStringList lista=ans.split('/');

        for(int i=1;i+1<lista.size();i+=2)
        {
            ui->listaCautari->addItem(lista[i]+"\t\t\t\t"+lista[i+1]+'\t');
        }
    }

}


void mainpage::on_listaCautari_itemDoubleClicked(QListWidgetItem *item)
{
    QString aux=item->text();
    QStringList reteta=aux.split('\t');

    for(int i=0;i<reteta.length();i++)
    {
       qDebug()<<reteta[i];
    }

    QString msg="7/"+reteta[0]+'/'+reteta[4]+'/';
    QString ans=TCPClient::send_recieve(msg);



    showReteta* show=new showReteta(nullptr);

    QStringList textReteta=ans.split('/');
    int sizeIngrediente=textReteta[1].toInt();
    QStringList listaIngrediente;
    int j=2;

    for(int i=0;i<2*sizeIngrediente;i++)
    {
        listaIngrediente.push_back(textReteta[j]);
        j++;
    }

    QString Descriere=textReteta[2+2*sizeIngrediente];
    j++;

    QString Nota=textReteta[3+2*sizeIngrediente];
    j++;

    QStringList listaReview;
    int sizeReview=textReteta[4+2*sizeIngrediente].toInt();
    j++;

    for(int i=0;i<2*sizeReview;i++)
    {
        listaReview.push_back(textReteta[j]);
        j++;
    }


    show->completeTitlu(item->text());
    show->completeIngrediente(listaIngrediente);
    show->completeDescriere(Descriere);
    show->completeRecenzii(listaReview);
    show->completeNota(Nota);
    //show->completeImagine();

    show->show();

}


void mainpage::on_top_clicked()
{
    QString msg=TCPClient::send_recieve("15/");
    QStringList lista=msg.split('/');

    ui->listaCautari->clear();
    for(int i=0;i+1<lista.size();i+=2)
    {
        ui->listaCautari->addItem(lista[i]+"\t\t\t\t"+lista[i+1]+"\t\n");
    }
}


void mainpage::on_pushButton_clicked()
{
    ui->listaCautari->clear();
    QString msg="17/"+Login::username+'/';

    QString ans=TCPClient::send_recieve(msg);
    QStringList lista=ans.split('/');

    for(int i=1;i+1<lista.size();i+=2)
    {
        ui->listaCautari->addItem(lista[i]+"\t\t\t\t"+lista[i+1]+"\t\n");
    }
}

