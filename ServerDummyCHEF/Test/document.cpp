#include "document.h"

QSqlDatabase document::open_DB()
{
QString servername ="DESKTOP-V7ILIT2";
QString dbname="DummyChef";
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setConnectOptions();
QString dsn = QString ("DRIVER={SQL Server Native Client 11.0};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);
db.setDatabaseName(dsn);
return db;
}

void document::logfile(QString message)
{
    Logging &instance=Logging::getInstance(message);
    instance.logging();
}
