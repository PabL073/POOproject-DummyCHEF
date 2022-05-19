#include "document_favorites.h"

#include <QtSql>
#include <QSqlError>
#include "iexceptions.h"
#include "bd_exception.h"


QString document_favorites::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

   if(db.open())
   {
       message.append("11/");
       QString delim="/";
       QSqlQuery qry;
       int ok=0;
       if(qry.exec("SELECT * FROM [DummyChef].[dbo].[Log]"))
       {
           while(qry.next() && ok==0)
           {
               if(this->_username==qry.value(0).toString())
               {
                ok=1;
               }
           }
       }
       if(ok==0)
       {
           message.append("username invalid/");
           return message;
       }
       qry.bindValue(":username",this->_username);
       qry.prepare("SELECT Retete.[Denumire_reteta],Retete.[Nume_chef] FROM [DummyChef].[dbo].[Favorite] INNER JOIN [DummyChef].[dbo].[Retete] on Retete.IdReteta=Favorite.IdReteta WHERE Favorite.[Username]=:username");
       qry.bindValue(":username",this->_username);
       if(qry.exec())
       {
               while(qry.next())
           {
               message.append(qry.value(0).toString());
               message.append(delim);
               message.append(qry.value(1).toString());
               message.append(delim);
           }
               this->logfile("S-a afisat lista de favorite a utilizatorului "+this->_username);
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

