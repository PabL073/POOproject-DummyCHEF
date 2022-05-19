#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QDialog>

namespace Ui {
class resetPassword;
}

class resetPassword : public QDialog
{
    Q_OBJECT

public:
    explicit resetPassword(QWidget *parent = nullptr);
    ~resetPassword();

private slots:
    void on_sendAnswerButtomn_clicked();

private:
    Ui::resetPassword *ui;
};

#endif // RESETPASSWORD_H
