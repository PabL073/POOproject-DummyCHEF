#include "document_access_recipe.h"
#include <QtSql>
#include <QSqlError>
#include "iexceptions.h"
#include <list>

QString Document_Access_Recipe::Message()
{
       QSqlDatabase db=this->open_DB();
       QString message;
       if(db.open())
       {
           message.append("7/");
           QSqlQuery qry;
           qry.prepare("SELECT * FROM [DummyChef].[dbo].[Retete] where Retete.Denumire_reteta=:1 and Retete.Nume_chef=:2");
           qry.bindValue(":1",this->_recipe.get_name());
           qry.bindValue(":2",this->_recipe.get_chefname());
           qry.exec();
           if(qry.next())
           {
               this->_recipe.set_ingredients(qry.value(3).toString());
               this->_recipe.set_steps(qry.value(4).toString());
               this->_recipe.set_image(qry.value(5).toString());
               this->_recipe.set_reviews(qry.value(6).toString());
               this->_recipe.set_nota(qry.value(7).toFloat());
               message+=this->send_ingredients();
               message+=this->send_steps();
               //message+=this->send_photo();
               message+=this->send_reviews();
               QString message_log="S-a incercat accesarea retetei ";
               message_log.append(this->_recipe.get_name());
               message_log.append(" introdusa de cheful ");
               message_log.append(this->_recipe.get_chefname());
               this->logfile(message_log);
           }
           else
           {
                message.append("solicitare inexistenta/");
                this->logfile("S-a incercat accesarea unei retete inexistente.");
           }
           db.close();
           return message;
       }
       else
       {
           try
           {
               IExceptions *ex=Factory_Exceptions::Create_BD_Exception_Instance();
               throw ex;
           }
           catch(IExceptions &ex)
           {
               message.append(ex.Message());
               this->logfile(message);
           }
       }

    return message;
}

QString Document_Access_Recipe::send_ingredients()
{
    QString delim="/";
    QString message;
    int nr=this->_recipe._ingredients.size();
    message.append(message.number(nr));
    message+=delim;
    std::list<Ingredient>::iterator it;
    for (it = this->_recipe._ingredients.begin(); it != this->_recipe._ingredients.end(); ++it)
                   {
                      message.append(it->get_gramaj());
                      message.append(delim);
                      message.append(it->get_denumire());
                      message.append(delim);
                   }
    return message;
}


QString Document_Access_Recipe::send_steps()
{
    QString message=this->_recipe.get_steps()+"/";
    return message;
}


QString Document_Access_Recipe::send_photo()
{
    QString delim="/";
    QString message;
    QString photo=this->_recipe.get_image();

    FILE * pFile;
    long lSize;
    char * buffer;

     pFile = fopen (photo.toStdString().c_str() , "rb" );
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
     message.append(QString::number(lSize));
     message.append(delim);
     message.append(buffer);
     message+=delim;

     return message;
}

QString Document_Access_Recipe::send_reviews()
{
    QString delim="/";
    QString message;
    QString nota;
    nota.setNum(this->_recipe.get_nota());
    message.append(nota);
    message.append("/");
    int nr=this->_recipe._reviews.size();
    QString nr_com;
    message+=nr_com.number(nr);
    message+=delim;
    std::list<Review>::iterator it;
    for (it = this->_recipe._reviews.begin(); it != this->_recipe._reviews.end(); ++it)
                   {
                      message.append(it->get_username());
                      message.append(delim);
                      message.append(it->get_review());
                      message.append(delim);
                   }
    return message;
}

