#include "firstscreen.h"
#include "login.h"
#include <QApplication>
#include "tcpclient.h"
#include<QFile>

#define ip_server "192.168.43.203"
#define connection_port 1234

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
   /*     QFile styleSheetFile("C:/Users/paulc/OneDrive/Documents/TEST22/Devsion.qss");
        styleSheetFile.open(QFile::ReadOnly);
        QString styleSheet=QLatin1String(styleSheetFile.readAll());
        app.setStyleSheet(styleSheet);*/

    app.setWindowIcon(QIcon("C:/Users/paulc/OneDrive/Documents/TEST22/img/icon.ico"));
    TCPClient *client=TCPClient::getInstance();
    client->start(ip_server, connection_port);




    FirstScreen w;
    //QtTheme w;
    w.show();

    return app.exec();
}


