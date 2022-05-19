#include "document_log.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"

QString Document_Log::Message()
{

QSqlDatabase db=this->open_DB();
QString message;
   if(db.open())
   {
       message="0/";
       int ok=0;
       QSqlQuery qry;
       //QString Password=this->_password.resize(this->_password.size()-2);
       if(qry.exec("SELECT * FROM [DummyChef].[dbo].[Log]"))
       {
           while(qry.next() && ok==0)
           {
               if(this->_username==qry.value(0).toString())
               {
                   if(this->_password==qry.value(1).toString())
                   {
                       message.append("DA/");
                       message.append(qry.value(5).toString());
                       ok=1;
                       QString message_log="Logarea utilizatorului ";
                       message_log.append(this->_username);
                       message_log.append(" a fost realizata cu succes.");
                       this->logfile(message_log);
                       break;
                   }
               }
           }
           if(ok==0)
           {
                message.append(("NU/"));
                this->logfile("Logarea nu s-a efectuat cu succes:credentiale cresite!");
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
               this->logfile(message);
           }
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
           this->logfile(message);
       }
   }
db.close();
return message;
}

