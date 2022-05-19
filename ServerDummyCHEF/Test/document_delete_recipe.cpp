#include "document_delete_recipe.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"


QString Document_Delete_Recipe::Message()
{

    QSqlDatabase db=this->open_DB();
    QString message;

       if(db.open())
       {
           message="10/";
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

                           QSqlQuery uqry;
                           uqry.prepare("DELETE FROM [DummyChef].[dbo].[Retete] WHERE [Denumire_reteta]=:3 AND [Nume_chef]=:4");
                           uqry.bindValue(":3",this->_recipe);
                           uqry.bindValue(":4",this->_chefname);
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
                               message.append("DA/");
                               this->logfile("Reteta "+this->_recipe+", chef:"+this->_chefname+" a fost stearsa cu succes.");
                               ok=1;
                           }

                       }
                   }
               }
               if(ok==0)
                   this->logfile("S-a incercat stergerea unei retete inexistente.");
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
