#ifndef DOCUMENT_REGISTER_H
#define DOCUMENT_REGISTER_H

#include "document.h"

class Document_Register : public document
{
private:
    QString _lastname;
    QString _firstname;
    QString _email;
    QString _username;
    QString _password;
    QString _account;
    QString _answer;

public:
    Document_Register(const QString& lastname,const QString& firstname,const QString& email, const QString& username,const QString& password,const QString& account,const QString& answer)
        : _lastname(lastname), _firstname(firstname), _email(email), _username(username), _password(password), _account(account),_answer(answer) {};
    QString Message();
};

#endif // DOCUMENT_REGISTER_H
