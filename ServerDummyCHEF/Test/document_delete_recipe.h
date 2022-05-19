#ifndef DOCUMENT_DELETE_RECIPE_H
#define DOCUMENT_DELETE_RECIPE_H

#include "document.h"

class Document_Delete_Recipe : public document
{
private:
    QString _recipe;
    QString _chefname;

public:
    Document_Delete_Recipe(QString str)
    {
        QString delim="/";
        _recipe=str.section(delim,1,1);
        _chefname=str.section(delim,2,2);
    }
    QString Message() override;
};

#endif // DOCUMENT_DELETE_RECIPE_H
