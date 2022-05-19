#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "idocument.h"
#include "logging.h"

class document : public IDocument
{
public:
    virtual QString Message() = 0;
    virtual ~document() {};

    QSqlDatabase open_DB();
    void logfile(QString message);
};

#endif // DOCUMENT_H
