#include "document_add_recipe.h"
#include <QtSql>
#include <QSqlError>
#include "iexceptions.h"
#include "bd_exception.h"


Document_add_recipe::Document_add_recipe(QString str)
{
    int i=1;
    Recipe recipe(str.section('/',i,i),str.section('/',i+1,i+1));
    _recipe=recipe;
    i+=2;
    int nr=str.section('/',i,i).toInt();
    i++;
    for(int j=0;j<nr;j++)
    {
       _recipe.add_ingredients(str.section('/',i,i),str.section('/',i+1,i+1));
       i+=2;
    }
    this->_recipe.set_steps(str.section('/',i,i));
    QString image=str.section('/',i,i);
    i++;
    int nr_octeti=image.toInt();
    FILE * pFileOUT;
    QString poza="C:\\Poze\\"+this->_recipe.get_name()+"_"+this->_recipe.get_chefname()+".jpg";
    this->_recipe.set_image(poza);
    pFileOUT = fopen (poza.toStdString().c_str(), "wb");
    fwrite (str.section('/',i,i).toStdString().c_str(), sizeof(char), nr_octeti,pFileOUT);
    fclose (pFileOUT);
}



QString Document_add_recipe::Message()
{
    QString message;
     QSqlDatabase db=this->open_DB();
    if(db.open())
    {
        QSqlQuery qry;
        qry.prepare("INSERT INTO [DummyChef].[dbo].[Retete] ([Denumire_reteta],[Nume_chef],[Ingrediente],[Pasi],[Image],[Recenzii],[Medie],[Numar_note]) VALUES (:reteta,:chef,:ingrediente,:pasi,:imagine,:recenzii,:medie,:numar_note)");
        qry.bindValue(":reteta",this->_recipe.get_name());
        qry.bindValue(":chef",this->_recipe.get_chefname());
        qry.bindValue(":ingrediente",this->_recipe.get_ingredients());
        qry.bindValue(":pasi",this->_recipe.get_steps());
        qry.bindValue(":imagine",this->_recipe.get_image());
        qry.bindValue(":recenzii","");
        qry.bindValue(":medie","0");
        qry.bindValue(":numar_note","0");
        qry.exec();
        message.append("14/DA/");
        this->logfile("Reteta "+this->_recipe.get_name()+"introdusa de cheful"+this->_recipe.get_chefname()+" a fost adaugata cu succes.");
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

