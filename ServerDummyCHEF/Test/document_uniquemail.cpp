#include "document_uniquemail.h"
#include <QtSql>
#include "iexceptions.h"
#include "bd_exception.h"

QString document_uniquemail::Message()
{
    QSqlDatabase db=this->open_DB();
    QString message;

    if(db.open())
    {
        message="2/";
        int ok=0;
        QSqlQuery qry;
        if(qry.exec("SELECT * FROM [DummyChef].[dbo].[Log]"))
        {
            while(qry.next() && ok==0)
            {
                if(this->_mail==qry.value(4).toString())
                {
                 message.append("mail deja folosit/");
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
            message.append("adresa de mail valida/");
        db.close();
        this->logfile("S-a verificat existenta unei adrese de mail in baza de date.");
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
