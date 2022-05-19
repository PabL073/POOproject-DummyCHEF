#ifndef DOCUMENT_LIST_RECIPES_H
#define DOCUMENT_LIST_RECIPES_H

#include "document.h"

class Document_List_Recipes : public document
{
private:
    QString _keyword;
    int _col0;
    int _col1;
public:
    Document_List_Recipes(QString str,int col0, int col1) :_col0(col0), _col1(col1)
    {
         _keyword=str.section("/",1,1);
    }
    QString Message();
};

#endif // DOCUMENT_LIST_RECIPES_H
