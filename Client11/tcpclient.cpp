#include "tcpclient.h"
#include "QTcpSocket"
#include "QDebug"

TCPClient::TCPClient(QObject *parent)
    : QObject{parent}
{
    socket = new QTcpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
}

void TCPClient::readyRead()
{
    qDebug() << "Ready to read...";
    QByteArray message;
    message = socket->readAll();

    if(socket->isWritable())
    {
        const char* sendMessage = "Hello";
        socket->write(sendMessage);
        socket->waitForBytesWritten(1000);
    }
}

void TCPClient::start(QString ip, unsigned short port)
{

    socket->connectToHost(ip, port); // pune ip si port din parametri
    if (socket->waitForConnected(3000))
    {
        qDebug() << "Connected...";
    }
    else
    {
        qDebug() << "Connection to server failed...";
    }

    QByteArray mesaj ="Salut, Raluca!";
    socket->write((mesaj));
}

void TCPClient::stop()
{
    if (this->socket->isOpen())
    {
        this->socket->close();
        qDebug() << "Socket closed...";
    }
}
