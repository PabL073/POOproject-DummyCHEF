#include "tcpclient.h"
#include "QTcpSocket"
#include "QDebug"
#include "showreteta.h"
#include "QDataStream"
#include<QMessageBox>

bool TCPClient::onSignal =false;
QString TCPClient::readText="";
QTcpSocket* TCPClient::socket=nullptr;
QString TCPClient::username="";
TCPClient* TCPClient::instance=nullptr;
QString TCPClient:: securityQuestion="";



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

    TCPClient::readText=message;
    TCPClient::onSignal=true;

    if(socket->isWritable())
    {
        //const char* sendMessage = "Hello";
        //socket->write(sendMessage);
        //socket->waitForBytesWritten(1000);
    }


    QStringList Tokens=QString(message).split('/');
    if(Tokens[0]=="18" || Tokens.size()==1)
    {
        emit photoData(message);
    }

}


void TCPClient::start(QString ip, unsigned short port)
{

    socket->connectToHost(ip, port); // pune ip si port din parametri
    if (socket->waitForConnected(2000))
    {
        qDebug() << "Connected...";
    }
    else
    {
        qDebug() << "Connection to server failed...";
        QMessageBox noConnection;
        noConnection.setText("\n\tConexiunea la server a esuat!\t\n");
        noConnection.exec();
        if(noConnection.Ok)
        {
            exit(0);
        }
    }

   // QByteArray mesaj ="Salut, Raluca!";
   // socket->write((mesaj));
}

void TCPClient::stop()
{
    if (this->socket->isOpen())
    {
        this->socket->close();
        qDebug() << "Socket closed...";
    }
}

QString TCPClient::send_recieve(QString s)
{
    if (TCPClient::socket->isWritable())
    {
        qDebug()<<"request message:"<<s<<"\n";
        QByteArray serverMessage = s.toUtf8();
        TCPClient::socket->write(serverMessage);
        TCPClient::socket->waitForBytesWritten(3000);
    }

    while(TCPClient::onSignal==false)
    {
        TCPClient::socket->waitForReadyRead(3000);
    }

    qDebug()<<"recievedMessage:"<<TCPClient::readText<<"\n";
    QString msg=TCPClient::readText;
    TCPClient::onSignal=false;
    readText="";

    return msg;
}

void TCPClient::sendMessage(QString message)
{
    if(TCPClient::socket->isWritable())
    {
        QByteArray sendMessage = message.toUtf8();
        TCPClient::socket->write(sendMessage);
        TCPClient::socket->waitForBytesWritten(3000);
    }
}

void TCPClient::setUsername(QString s)
{
    username=s;
}

QString TCPClient::getUsername()
{
    return username;
}

void TCPClient::setQuestion(QString s)
{
    securityQuestion=s;
}

QString TCPClient::getQuestion()
{
    return securityQuestion;
}

TCPClient *TCPClient::getInstance()
{
    if (instance == nullptr)
        {
            instance = new TCPClient();
        }

    return instance;
}

