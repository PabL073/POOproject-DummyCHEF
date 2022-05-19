#include "document_list_recipes.h"

#include <QtSql>
#include <QSqlError>
#include "iexceptions.h"
#include "bd_exception.h"


QString Document_List_Recipes::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

   if(db.open())
   {
       QString delim="/";
       int ok=0;
       if(this->_col0==0)
           message="5/";
       else
           message="6/";
       QSqlQuery qry;
       if(qry.exec("SELECT [Denumire_reteta],[Nume_chef] FROM [DummyChef].[dbo].[Retete]"))
       {
           while(qry.next())
           {
               if(qry.value(this->_col0).toString().contains(_keyword) and this->_col0==0)
               {
                 message.append(qry.value(this->_col0).toString());
                 message.append(delim);
                 message.append(qry.value(this->_col1).toString());
                 message.append(delim);
                 ok=1;
                 QString message_log="S-au listat retetele care contin cuvantul cheie ";
                 message_log.append(this->_keyword);
                 this->logfile(message_log);
               }
                 else if(qry.value(this->_col0).toString()==this->_keyword and this->_col0==1)
                 {
                   message.append(qry.value(this->_col1).toString());
                   message.append(delim);
                   ok=1;
                   QString message_log="S-au listat retetele sefului ";
                   message_log+=this->_keyword;
                   message.append(this->_keyword);
                   message.append(delim);
                   this->logfile(message_log);
                 }
               }

       if(ok==0)
       {
           if(this->_col0==0)
           {
           message.append("nu exista nicio reteta cu denumirea introdusa/");
           this->logfile("S-a incercat listarea unor retete cu un cuvant cheie inexistent.");
           }
                   else
           {
               message.append("nu aveti cont de CHEF/");
              this->logfile("S-a incercat listarea retetelor unui chef care nu exista.");
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
