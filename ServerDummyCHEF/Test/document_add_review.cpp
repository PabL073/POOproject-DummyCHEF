#include "document_add_review.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"


QString Document_Add_Review::Message()
{

    QSqlDatabase db=this->open_DB();
    QString message;

       if(db.open())
       {
           message="8/";
           int ok=0;
           QSqlQuery qry;
           if(qry.exec("SELECT * FROM [DummyChef].[dbo].[Retete]"))
           {
               while(qry.next() && ok==0)
               {
                   if(this->_recipe==qry.value(1).toString())
                   {
                       if(this->_chefname==qry.value(2).toString())
                       {
                           QString reviews=qry.value(6).toString();
                           reviews.append(",");
                           reviews.append(this->_review.get_username());
                           reviews.append(":");
                           reviews.append(this->_review.get_review());
                           ok=1;
                           QSqlQuery uqry;
                           uqry.prepare("UPDATE [DummyChef].[dbo].[Retete] SET [Recenzii]=:1 WHERE [Denumire_reteta]=:2 AND [Nume_chef]=:3");
                           uqry.bindValue(":1",reviews);
                           uqry.bindValue(":2",this->_recipe);
                           uqry.bindValue(":3",this->_chefname);
                           uqry.exec();
                           if(!uqry.exec())
                             {
                                   try
                                   {
                                       IExceptions *ex=Factory_Exceptions::Create_BD_Exception_Instance();
                                       throw ex;
                                   }
                                   catch(IExceptions &ex)
                                   {
                                       message.append(ex.Message());
                                   }
                           }
                           else
                           {
                               message.append("comentariu adaugat cu succes/");
                               this->logfile("Usernameul "+this->_review.get_username()+" a adaugat cu succes un cometariu la reteta "+this->_recipe+","+this->_chefname);
                               ok=1;
                           }

                       }
                   }
               }
               if(ok==0)
               {
                   message.append("nu exista aceasta reteta/");
                   this->logfile("S-a incercat adaugarea unei comentariu la o reteta inexistenta.");
               }
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
           }
       }

    return message;
}
