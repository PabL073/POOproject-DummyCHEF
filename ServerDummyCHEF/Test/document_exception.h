#ifndef DOCUMENT_EXCEPTION_H
#define DOCUMENT_EXCEPTION_H

#include "exceptions.h"

class Protocol_Exception : public Exceptions
{
public:
    Protocol_Exception(){this->message="22222"; qDebug()<<"Error"<<this->message<<":Protocol invalid.";}
};

#endif // DOCUMENT_EXCEPTION_H
