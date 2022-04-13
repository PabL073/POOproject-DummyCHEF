#include "server.h"
#include "thread.h"

#define port 1234

Server::Server(QObject *parent)
    : QTcpServer{parent}
{

}

void Server::StartServer()
{

    if(!this->listen(QHostAddress::Any,port))
    {

        qDebug()<<"Server could not start!";
    }
    else
    {
        qDebug()<<"Listening...";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
     qDebug()<< socketDescriptor<<"Connecting...";
     Thread *thread=new Thread(socketDescriptor,this);
     connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

     thread->start();

}
