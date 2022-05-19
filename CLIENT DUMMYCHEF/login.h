#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    static QString getCurrentUsername();
    static QString getCurrentPassword();

    //void setUsername(QString s){this->username=s;}
    //void setPassword(QString s){this->password=s;}

    static QString username;
    static QString password;
    static QString tipCont;

private slots:

    void on_loginButton_clicked();

    void on_resetare_parola_button_clicked();

    void on_backButton_clicked();


private:
    Ui::Login *ui;
    //QString username="";
   // QString password="";
};

#endif // LOGIN_H
