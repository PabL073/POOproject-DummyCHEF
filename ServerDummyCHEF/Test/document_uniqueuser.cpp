#include "document_uniqueuser.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"



QString Document_UniqueUser::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

    if(db.open())
    {
        message="1/";
        int ok=0;
        QSqlQuery qry;
        if(qry.exec("SELECT * FROM [DummyChef].[dbo].[Log]"))
        {
            while(qry.next() && ok==0)
            {
                if(this->_username==qry.value(0).toString())
                {
                 message.append("user deja utilizat/");
                 ok=1;
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
        if(ok==0)
            message.append("user unic/");
        db.close();
         this->logfile("S-a verificat existenta unui username in baza de date.");
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
