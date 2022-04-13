#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>

class QTcpSocket;

class TCPClient : public QObject
{
    Q_OBJECT
public:
    explicit TCPClient(QObject *parent = nullptr);
    virtual ~TCPClient() {};

    void start(QString ip, unsigned short port);
    void stop();

signals:


private slots:
    void readyRead();

private:
    QTcpSocket* socket;


};

#endif // TCPCLIENT_H
