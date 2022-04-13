#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>


class Thread : public QThread
{
    Q_OBJECT
public:
    explicit Thread(qintptr ID,QObject *parent = 0);

    void run();

signals:

    void error(QTcpSocket::SocketError socketError);

public Q_SLOTS:
        void readyRead();
        void disconnected();



private:
       QTcpSocket * socket;
       int socketDescriptor;

};

#endif // THREAD_H
