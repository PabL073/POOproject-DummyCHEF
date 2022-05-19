#ifndef INCORRECTCREDENTIALS_H
#define INCORRECTCREDENTIALS_H

#include <QDialog>

namespace Ui {
class incorrectCredentials;
}

class incorrectCredentials : public QDialog
{
    Q_OBJECT

public:
    explicit incorrectCredentials(QWidget *parent = nullptr);
    ~incorrectCredentials();

private:
    Ui::incorrectCredentials *ui;
};

#endif // INCORRECTCREDENTIALS_H
