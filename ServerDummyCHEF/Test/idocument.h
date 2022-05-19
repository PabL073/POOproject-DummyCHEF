#ifndef IDOCUMENT_H
#define IDOCUMENT_H
#include <QObject>
#include "iexceptions.h"
#include "document_exception.h"
#include <QtSql>

typedef enum{LOGARE=23,VERIF_USER_UNIC,VERIF_MAIL_UNIC,REGISTER,PASSWORD_RESET,LISTA_DENUMIRI_RETETE,LISTA_RETETE_CHEFI,
             ACCESS_RECIPE,ADD_REVIEW,ADD_NOTA,DELETE_RECIPE,FAVORITES_LIST,ADD_FAVORITE,DELETE_FAVORITE,ADD_RECIPE,TOP,SEND_NAME,
            RETETE_CONT_CHEF,SEND_PHOTO} prot;

class IDocument
{
public:

    virtual QString Message() = 0;
    virtual ~IDocument() {};
};

class Factory_Document
{
public:
    static IDocument* Create_LogInstance(const QString &str);
    static IDocument* Create_UniqueUserInstance(const QString& str);
    static IDocument* Create_UniqueMailInstance(const QString& str);
    static IDocument* Create_RegisterInstance(const QString& lastname,const QString& firstname,const QString& email, const QString& username,const QString& password,const QString& account,const QString& answer);
    static IDocument* Create_PasswordResetInstance(const QString& str);
    static IDocument* Create_ListRecipesInstance(QString& str,int col0, int col1);
    static IDocument* Create_AccessRecipeInstance(const QString& str);
    static IDocument* Create_AddReviewInstance(const QString& str);
    static IDocument* Create_AddNotaInstance(const QString& str);
    static IDocument* Create_DeleteRecipeInstance(const QString& str);
    static IDocument* Create_FavoritesInstance(const QString& str);
    static IDocument* Create_AddFavoriteInstance(const QString& str);
    static IDocument* Create_DeleteFavoriteInstance(const QString& str);
    static IDocument* Create_AddRecipeInstance(const QString& str);
    static IDocument* Create_TopRecipeInstance();
    static IDocument* Create_SendNameInstance(const QString &str);
    static IDocument* Create_SendPhotoInstance(const QString &str);
};



#endif // IDOCUMENT_H
