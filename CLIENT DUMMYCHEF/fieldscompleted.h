#ifndef FIELDSCOMPLETED_H
#define FIELDSCOMPLETED_H

#include <QDialog>

namespace Ui {
class FieldsCompleted;
}

class FieldsCompleted : public QDialog
{
    Q_OBJECT

public:
    explicit FieldsCompleted(QWidget *parent = nullptr);
    ~FieldsCompleted();

private:
    Ui::FieldsCompleted *ui;
};

#endif // FIELDSCOMPLETED_H
