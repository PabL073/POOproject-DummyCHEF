#ifndef DOCUMENT_LOG_H
#define DOCUMENT_LOG_H

#include "document.h"

class Document_Log : public document
{
private:
    QString _username;
    QString _password;
public:
    Document_Log(QString str)
    {
        QString delim="/";
        _username=str.section(delim,1,1);
        _password=str.section(delim,2,2);
    }
    QString Message() override;
};

#endif // DOCUMENT_LOG_H
