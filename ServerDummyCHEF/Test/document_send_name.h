#ifndef DOCUMENT_SEND_NAME_H
#define DOCUMENT_SEND_NAME_H

#include "document.h"

class Document_Send_Name : public document
{
    QString _username;
public:
    Document_Send_Name(QString username):_username(username) {};
    QString Message() override;
};

#endif // DOCUMENT_SEND_NAME_H
