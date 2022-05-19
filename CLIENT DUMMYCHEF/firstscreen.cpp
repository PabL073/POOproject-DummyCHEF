#include "firstscreen.h"
#include "ui_firstscreen.h"
#include "login.h"
#include "register.h"

FirstScreen::FirstScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstScreen)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("DummyCHEF");
}

FirstScreen::~FirstScreen()
{
    delete ui;
}


void FirstScreen::on_loginButton_clicked()
{
    Login *log = new Login (nullptr);
    log->show();
    this->hide();
}


void FirstScreen::on_registerButton_clicked()
{
    Register *reg = new Register (nullptr);
    reg->show();
}






