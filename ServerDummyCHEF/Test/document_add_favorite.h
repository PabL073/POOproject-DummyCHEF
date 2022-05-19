#ifndef DOCUMENT_ADD_FAVORITE_H
#define DOCUMENT_ADD_FAVORITE_H

#include "document_favorite.h"

class Document_Add_Favorite : public Document_Favorite
{
public:
    Document_Add_Favorite(QString str):Document_Favorite(str) {};
    QString Message() override;
};

#endif // DOCUMENT_ADD_FAVORITE_H
