#ifndef FIRSTSCREEN_H
#define FIRSTSCREEN_H


#include <QMainWindow>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class FirstScreen; }
QT_END_NAMESPACE

class FirstScreen : public QMainWindow
{
    Q_OBJECT


public:
    FirstScreen(QWidget *parent = nullptr);
    ~FirstScreen();

private slots:



    void on_loginButton_clicked();

    void on_registerButton_clicked();

    //void on_loginButton_2_clicked();

private:
    Ui::FirstScreen *ui;

};
#endif // FIRSTSCREEN_H
