#include "document_register.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"

QString Document_Register::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

   if(db.open())
   {
       QString delim="/";
       message="3/";

       QString sqry="INSERT INTO [DummyChef].[dbo].[Log] ([UserName],[Password],[Nume],[Prenume],[email],[TipCont],[Raspuns]) VALUES(:1,:2,:3,:4,:5,:6,:7)";

       QSqlQuery qry;

       qry.prepare(sqry);

       qry.bindValue(":1",_username);
       qry.bindValue(":2",_password);
       qry.bindValue(":3",_lastname);
       qry.bindValue(":4",_firstname);
       qry.bindValue(":5",_email);
       qry.bindValue(":6",_account);
       qry.bindValue(":7",_answer);

       if(qry.exec())
       {
            message.append("DA/");
            this->logfile("S-a realizat inregistrarea userului "+this->_username);
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
           this->logfile(message);
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


