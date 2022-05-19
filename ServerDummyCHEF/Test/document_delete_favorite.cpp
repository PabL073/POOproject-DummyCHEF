#include "document_delete_favorite.h"

QString Document_Delete_Favorite::Message()
{

    QString delim="/";
    QSqlDatabase db = this->open_DB();
    QString message="13";
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
           int idRecipe=qry.value(0).toInt();

           QSqlQuery uqry;
           uqry.prepare("DELETE FROM [DummyChef].[dbo].[Favorite] WHERE [Username]=:3 AND [IdReteta]=:4");
           uqry.bindValue(":3",this->_username);
           uqry.bindValue(":4",idRecipe);
           uqry.exec();
           if(uqry.exec())
               {
                  message.append("DA/");
                  this->logfile("Reteta "+this->_recipe+" introdusa de cheful "+this->_chef_name+" a fost stearsa cu succes din lista de favorite a username-ului "+this->_username);
               }
           else
           {
               message.append("NU/");
               this->logfile("S-a incercat stergerea unei retete inexistente.");
           }
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


