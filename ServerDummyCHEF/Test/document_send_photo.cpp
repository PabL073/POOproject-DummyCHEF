#include "document_send_photo.h"

#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"

QString document_send_photo::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message="18/";
    QString delim="/";

    if(db.open())
    {
    QString path;
    QSqlQuery qry;
    qry.prepare("SELECT [Image] FROM [DummyChef].[dbo].[Retete] where Retete.Denumire_reteta=:1 and Retete.Nume_chef=:2");
    qry.bindValue(":1",this->_recipe);
    qry.bindValue(":2",this->_chefname);
    qry.exec();
    if(qry.next())
    {
        path=qry.value(0).toString();
    }

    QString photo1=path;
    photo1.erase(photo1.begin(),photo1.begin()+10);
    message.append(photo1);
    message+=delim;

    FILE * pFile;
    int lSize;
    char * buffer;
    qDebug()<<path;

     pFile = fopen (path.toStdString().c_str() , "rb" );
     if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

     // obtain file size:
     fseek (pFile , 0 , SEEK_END);
     lSize = ftell (pFile);
     rewind (pFile);

     // allocate memory to contain the whole file:
     buffer = (char*) malloc (sizeof(char)*lSize);
     if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

     // copy the file into the buffer:
     fread (buffer,1,lSize,pFile);
     qDebug()<<buffer;
     message.append(QString::number(lSize));
     message.append(delim);
     message.append(buffer);
     message+=delim;
     message+="18";
}
     return message;
}



