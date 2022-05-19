#ifndef DOCUMENT_UNIQUEMAIL_H
#define DOCUMENT_UNIQUEMAIL_H

#include "document.h"

class document_uniquemail : public document
{
private:
    QString _mail;
public:
    document_uniquemail(QString str)
    {
         _mail=str.section("/",1,1);
    }
    QString Message();
};

#endif // DOCUMENT_UNIQUEMAIL_H
