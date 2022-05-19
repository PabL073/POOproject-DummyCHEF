#ifndef DOCUMENT_ADD_RECIPE_H
#define DOCUMENT_ADD_RECIPE_H

#include "document.h"
#include "recipe.h"


class Document_add_recipe : public document
{
Recipe _recipe;

public:
    Document_add_recipe(QString str);
    QString Message();
};

#endif // DOCUMENT_ADD_RECIPE_H
