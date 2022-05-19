#ifndef DOCUMENT_UNIQUEUSER_H
#define DOCUMENT_UNIQUEUSER_H

#include "document.h"

class Document_UniqueUser : public document
{
    private:
        QString _username;
    public:
        Document_UniqueUser(QString str)
        {
            QString delim="/";
            _username=str.section(delim,1,1);
        }
        QString Message();
};

#endif // DOCUMENT_UNIQUEUSER_H
