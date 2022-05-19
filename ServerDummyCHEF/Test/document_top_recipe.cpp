#include "document_top_recipe.h"

#include <QtSql>
#include <QSqlError>
#include "iexceptions.h"
#include "bd_exception.h"


QString Document_Top_Recipe::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

   if(db.open())
   {
       QSqlQuery qry;
       qry.prepare("SELECT TOP(5) Denumire_reteta,Nume_chef FROM [DummyChef].[dbo].[Retete] ORDER BY Medie DESC");
       qry.exec();
       while(qry.next())
       {
            message+=qry.value(0).toString();
            message+="/";
            message+=qry.value(1).toString();
            message+="/";
            this->logfile("S-au afisat top 5 cele mai faimoase retete.");
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


