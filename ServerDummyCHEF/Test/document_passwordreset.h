#ifndef DOCUMENT_PASSWORDRESET_H
#define DOCUMENT_PASSWORDRESET_H

#include "document.h"

class Document_PasswordReset : public document
{
private:
    QString _username;
    QString _answer;
    QString _newpassword;


public:
    Document_PasswordReset(const QString& str)
    {
        QString delim="/";
        _username=str.section(delim,1,1);
        _answer=str.section(delim,2,2);
        _newpassword=str.section(delim,3,3);
    }
    QString Message();
};

#endif // DOCUMENT_PASSWORDRESET_H
