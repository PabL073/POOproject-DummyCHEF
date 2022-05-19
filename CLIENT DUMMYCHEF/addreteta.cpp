#include "addreteta.h"
#include "ui_addreteta.h"
#include"tcpclient.h"
#include<QString>
#include<QFileDialog>
#include<QMessageBox>
#include<QFile>
#include"login.h"

addReteta::addReteta(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addReteta)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Formular adaugare reteta");
    ui->addNume->setPlaceholderText("ex: Budinca de chia cu capsuni");
    ui->addIngrediente->setPlaceholderText("ex: Seminte chia/Lapte(ml)/Capsuni etc.");
    ui->addGramaje->setPlaceholderText("100/200/80");

}

addReteta::~addReteta()
{
    delete ui;
}

void addReteta::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                "All files (*.*);;PNG File(*.png);;JPG File (*.jpg);;JPEG File(*.JPEG)"

                );
    QMessageBox::information(this,tr("File Name"),filename);

    //this->addImagePath(filename);
}


void addReteta::on_SendRetetaButton_accepted()
{
    QString reteta="14/"+ui->addNume->text()+'/';
    QString aux=TCPClient::send_recieve("16/"+Login::username+"/");
    QStringList name=aux.split('/');


    reteta+=name[1]+'/';

    QString stringIngrediente=ui->addIngrediente->toPlainText();
    QString stringGramaje=ui->addGramaje->toPlainText();

    QStringList ListaIngrediente=stringIngrediente.split('/');
    QStringList ListaGramaje=stringGramaje.split('/');

 /*
    if(ListaIngrediente.size()!=ListaGramaje.size())
    {

        warning.setText("\n\tAdaugati cantitati pentru fiecare ingredient!\t\n");
        warning.exec();
    }*/

    QString nrPerechi=QString::number(ListaIngrediente.size());

    reteta+=nrPerechi+'/';

    for(int i=0;i<ListaIngrediente.size();i++)
    {
        reteta+=ListaGramaje[i]+'/'+ListaIngrediente[i]+'/';
    }

    reteta+=ui->addDescriere->toPlainText();
    reteta+='/';

    QString ans=TCPClient::send_recieve(reteta);

    QMessageBox warning;
    if(ans.contains("DA"))
    {
        warning.setText("\n\tReteta adaugata cu succes!");
        warning.exec();
    }
    else
    {
        warning.setText("\n\t A aparut o eroare la adaugarea retetei!\nIncercati din nou!\t\n");
        warning.exec();
    }

       //Get Picture Size
       /* printf("Getting Picture Size\n");
        FILE *picture;
        picture = fopen(this->getImagePath(), "r");
        int size;
        fseek(picture, 0, SEEK_END);
        size = ftell(picture);

        //Send Picture Size
        printf("Sending Picture Size\n");
        write(sock, &size, sizeof(size));

        //Send Picture as Byte Array
        printf("Sending Picture as Byte Array\n");
        char send_buffer[size];
        while(!feof(picture)) {
            fread(send_buffer, 1, sizeof(send_buffer), picture);
            write(sock, send_buffer, sizeof(send_buffer));
            bzero(send_buffer, sizeof(send_buffer));
        }*/

}



