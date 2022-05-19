#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include "iexceptions.h"

class Exceptions : public IExceptions
{
protected:
    QString message;
public:
    Exceptions(){};
    QString Message() {return message;}
};

#endif // EXCEPTIONS_H
