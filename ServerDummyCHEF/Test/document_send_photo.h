#ifndef DOCUMENT_SEND_PHOTO_H
#define DOCUMENT_SEND_PHOTO_H

#include "document.h"

class document_send_photo : public document
{
private:
    QString _chefname;
    QString _recipe;

    public:
public:
    document_send_photo(QString str)
    {
        _chefname=str.section('/',2,2);
        _recipe=str.section('/',1,1);
    }
    QString Message() override;
};

#endif // DOCUMENT_SEND_PHOTO_H
