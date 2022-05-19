#ifndef FAILEDRESETPASSWORD_H
#define FAILEDRESETPASSWORD_H

#include <QDialog>

namespace Ui {
class FailedResetPassword;
}

class FailedResetPassword : public QDialog
{
    Q_OBJECT

public:
    explicit FailedResetPassword(QWidget *parent = nullptr);
    ~FailedResetPassword();

private slots:
    void on_reloadButton_clicked();

private:
    Ui::FailedResetPassword *ui;
};

#endif // FAILEDRESETPASSWORD_H
