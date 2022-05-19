#ifndef DOCUMENT_ACCESS_RECIPE_H
#define DOCUMENT_ACCESS_RECIPE_H
#include "recipe.h"
#include "document.h"

class Document_Access_Recipe : public document
{
private:
    Recipe _recipe;

public:
    Document_Access_Recipe(QString str)
    {
     Recipe r(str.section("/",1,1),str.section("/",2,2));
     _recipe=r;
    };

    QString Message();
    QString send_ingredients();
    QString send_steps();
    QString send_photo();
    QString send_reviews();
};

#endif // DOCUMENT_ACCESS_RECIPE_H
