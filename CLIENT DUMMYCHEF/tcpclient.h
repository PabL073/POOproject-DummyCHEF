#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>

class QTcpSocket;

class TCPClient : public QObject
{
    Q_OBJECT

 private:
    explicit TCPClient(QObject *parent = nullptr);


 public:
    virtual ~TCPClient() {};
    void start(QString ip, unsigned short port);
    void stop();
    static QString send_recieve(QString s);
    static void sendMessage(QString message);
    static void setUsername(QString s);
    static QString getUsername();
    static void setQuestion(QString s);
    static QString getQuestion();
    static TCPClient* getInstance();

signals:
    void photoData(QByteArray data);

private slots:
    void readyRead();


private:
    static QTcpSocket* socket;
    static TCPClient* instance;
    static bool onSignal;
    static QString readText;
    static QString username;
    static QString securityQuestion;

};

#endif // TCPCLIENT_H
