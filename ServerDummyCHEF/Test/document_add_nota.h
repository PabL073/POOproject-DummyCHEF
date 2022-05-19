#ifndef DOCUMENT_ADD_NOTA_H
#define DOCUMENT_ADD_NOTA_H

#include "document.h"

class Document_Add_Nota : public document
{
private:
    QString _recipe;
    QString _chefname;
    int _nota;

public:
    Document_Add_Nota(QString str)
    {
        QString delim="/";
        _recipe=str.section(delim,1,1);
        _chefname=str.section(delim,2,2);
        QString n=str.section(delim,3,3);
        _nota=n.toInt();
    }
    QString Message()override;
};

#endif // DOCUMENT_ADD_NOTA_H
