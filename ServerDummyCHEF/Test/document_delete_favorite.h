#ifndef DOCUMENT_DELETE_FAVORITE_H
#define DOCUMENT_DELETE_FAVORITE_H

#include "document_favorite.h"

class Document_Delete_Favorite : public Document_Favorite
{
public:
    Document_Delete_Favorite(QString str):Document_Favorite(str) {};
    QString Message() override;
};

#endif // DOCUMENT_DELETE_FAVORITE_H
