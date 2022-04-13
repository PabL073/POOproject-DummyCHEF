#include "mainwindow.h"
#include "tcpclient.h"

#include <QApplication>
#define ip_server "172.0.0.1"
#define connection_port 1234

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TCPClient client;
    client.start(ip_server, connection_port);

    MainWindow w;
    w.show();
    return a.exec();
}
