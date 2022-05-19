#ifndef PROTOCOALE_H
#define PROTOCOALE_H
#include <qstring.h>


class protocoale
{
public:
    protocoale();
    ~protocoale();

   private:
    QString message;

   public:
    QString login_protocol();
    QString register_protocol();
    QString recipe_protocol();


};

#endif // PROTOCOALE_H
