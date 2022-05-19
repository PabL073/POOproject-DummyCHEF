#include "failedresetpassword.h"
#include "ui_failedresetpassword.h"

FailedResetPassword::FailedResetPassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FailedResetPassword)
{
    ui->setupUi(this);
}

FailedResetPassword::~FailedResetPassword()
{
    delete ui;
}

void FailedResetPassword::on_reloadButton_clicked()
{
    delete this;
}

