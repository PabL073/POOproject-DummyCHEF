#include "document_send_name.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"

QString Document_Send_Name::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

   if(db.open())
   {
       message="16/";

       QSqlQuery qry;
       qry.prepare("SELECT Nume,Prenume FROM [DummyChef].[dbo].[Log] where UserName=:1");
       qry.bindValue(":1",_username);
       qry.exec();
       while(qry.next())
       {
           message.append(qry.value(0).toString());
           message+=" ";
           message.append(qry.value(1).toString());
           message+="/";
       }
       this->logfile("S-a transmis numele userului "+_username);

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



