#ifndef DOCUMENT_FAVORITE_H
#define DOCUMENT_FAVORITE_H

#include "document.h"

class Document_Favorite : public document
{
protected:
    QString _username;
    QString _recipe;
    QString _chef_name;
public:
    Document_Favorite(QString str)
    {
        QString delim="/";
        _username=str.section(delim,1,1);
        _recipe=str.section(delim,2,2);
        _chef_name=str.section(delim,3,3);
    }
    QString Message()=0;
};

#endif // DOCUMENT_FAVORITE_H
