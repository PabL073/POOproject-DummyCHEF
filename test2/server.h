#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void StartServer();

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

};

#endif // SERVER_H
