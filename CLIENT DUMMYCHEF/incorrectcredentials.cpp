#include "incorrectcredentials.h"
#include "ui_incorrectcredentials.h"

incorrectCredentials::incorrectCredentials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::incorrectCredentials)
{
    ui->setupUi(this);
}

incorrectCredentials::~incorrectCredentials()
{
    delete ui;
}
