#include "document_add_nota.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"


QString Document_Add_Nota::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

       if(db.open())
       {
           message.append("9/");
           QSqlQuery qry;
           qry.prepare("SELECT * FROM [DummyChef].[dbo].[Retete] where Retete.Denumire_reteta=:1 and Retete.Nume_chef=:2");
           qry.bindValue(":1",this->_recipe);
           qry.bindValue(":2",this->_chefname);
           qry.exec();
           if(qry.next())
           {
                           float medie=qry.value(7).toDouble();
                           int nr_note=qry.value(8).toInt();
                           medie=medie*nr_note;
                           medie+=this->_nota;
                           nr_note++;
                           medie=medie/nr_note;
                           QSqlQuery uqry;
                           uqry.prepare("UPDATE [DummyChef].[dbo].[Retete] SET [Medie]=:1, [Numar_note]=:2 WHERE [Denumire_reteta]=:3 AND [Nume_chef]=:4");
                           uqry.bindValue(":1",medie);
                           uqry.bindValue(":2",nr_note);
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
                                   this->logfile(message);
                               }
                           }
                           else
                           {
                               message.append("nota adaugata cu succes/");
                               this->logfile( "A fost adaugata o nota la reteta "+this->_recipe+" introdusa de cheful "+this->_chefname);
                           }
               }
               else
           {
                   message.append("nu exista aceasta reteta/");
                   this->logfile("S-a incercat adaugarea unei note la o reteta inexistenta.");
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
