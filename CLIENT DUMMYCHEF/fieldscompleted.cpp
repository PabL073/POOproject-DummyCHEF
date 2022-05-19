#include "fieldscompleted.h"
#include "ui_fieldscompleted.h"

FieldsCompleted::FieldsCompleted(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FieldsCompleted)
{
    ui->setupUi(this);
     QWidget::setWindowTitle("Error");
}

FieldsCompleted::~FieldsCompleted()
{
    delete ui;
}
