#include "document_passwordreset.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"


QString Document_PasswordReset::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

   if(db.open())
   {
       message="4/";
       int ok=0;
       QSqlQuery qry;
       if(qry.exec("SELECT * FROM [DummyChef].[dbo].[Log]"))
       {
           while(qry.next() && ok==0)
           {
               if(this->_username==qry.value(0).toString())
               {
                   if(this->_answer==qry.value(6).toString())
                   {
                       QSqlQuery uqry;
                       uqry.prepare("UPDATE [DummyChef].[dbo].[Log] SET [Password]=:1 WHERE [UserName]=:2 AND [Raspuns]=:3");
                       uqry.bindValue(":1",_newpassword);
                       uqry.bindValue(":2",_username);
                       uqry.bindValue(":3",_answer);
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
                       message.append("parola schimbata cu succes/");
                       this->logfile("A fost modificata parola userului "+this->_username);
                       ok=1;
                       }
                   }
               }
            }

           if(ok==0)
           {
               message.append("username sau raspuns gresit/");
               this->logfile("S-a incercat modificarea parolei unui user care a introdus gresit credentialele.");
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
