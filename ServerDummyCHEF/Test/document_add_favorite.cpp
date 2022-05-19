#include "document_add_favorite.h"

QString Document_Add_Favorite::Message()
{

    QString delim="/";
    QSqlDatabase db = this->open_DB();
    QString message="12/";
    message.append(delim);
       if(db.open())
       {
           QSqlQuery qry;
           qry.prepare("SELECT Retete.IdReteta from [DummyChef].[dbo].[Retete] where Retete.Denumire_reteta=:1 and Retete.Nume_chef=:2");
           qry.bindValue(":1",this->_recipe);
           qry.bindValue(":2",this->_chef_name);
           qry.exec();
           if(qry.next())
           {
           int idRecipe;
           idRecipe=qry.value(0).toInt();
           qry.prepare("INSERT INTO [DummyChef].[dbo].[Favorite] (Username,IdReteta) VALUES (:username,:id)");
           qry.bindValue(":username",this->_username);
           qry.bindValue(":id",idRecipe);
           }
           if(qry.exec())
               {
                  message.append("DA/");
                  this->logfile("Reteta "+this->_recipe+" introdusa de cheful "+this->_chef_name+" a fost adaugata cu succes in lista de favorite a username-ului "+this->_username);
               }
           else
           {
                message.append("NU/");
                this->logfile("Reteta "+this->_recipe+" introdusa de cheful "+this->_chef_name+" exista deja in lista de favorite a username-ului "+this->_username);
            }
           db.close();
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

