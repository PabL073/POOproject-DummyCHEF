#ifndef DOCUMENT_ADD_REVIEW_H
#define DOCUMENT_ADD_REVIEW_H

#include "document.h"
#include "review.h"

class Document_Add_Review : public document
{
private:
    QString _recipe;
    QString _chefname;
    Review _review;
public:
    Document_Add_Review(QString str):_review(str.section("/",3,3),str.section("/",4,4))
    {
        QString delim="/";
        _recipe=str.section(delim,1,1);
        _chefname=str.section(delim,2,2);
    };

    QString Message();
};


#endif // DOCUMENT_ADD_REVIEW_H
