#ifndef DOCUMENT_FAVORITES_H
#define DOCUMENT_FAVORITES_H

#include "document.h"

class document_favorites : public document
{
private:
    QString _username;
public:
    document_favorites(QString str)
    {
        _username=str.section("/",1,1);
    }
    QString Message();
};

#endif // DOCUMENT_FAVORITES_H
