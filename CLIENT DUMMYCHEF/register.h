#ifndef REGISTER_H
#define REGISTER_H
#include<qstring.h>

#include <QMainWindow>

namespace Ui {
class Register;
}

class Register : public QMainWindow
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

    void check_pass();
    void check_email();
    void check_username();

private slots:
    void on_finalizare_inregistrare_clicked();

    void on_learner_CheckBox_stateChanged(int arg1);

    void on_chef_CheckBox_stateChanged(int arg1);

    void on_termeni_conditii_CheckBox_stateChanged(int arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_contLearner_clicked();

    void on_contChef_clicked();

    void on_contLearner_pressed();

    void on_parola_editingFinished();

    void on_parola2_editingFinished();

    void on_termeni_conditii_CheckBox_clicked();

    void on_termeni_conditii_CheckBox_toggled(bool checked);

    void on_parola_textEdited(const QString &arg1);

    void on_parola_textChanged(const QString &arg1);

    void on_parola_selectionChanged();

    void on_parola2_selectionChanged();

    void on_parola2_textEdited(const QString &arg1);

    void on_email_textEdited(const QString &arg1);

    void on_email_editingFinished();

    void on_email_textChanged(const QString &arg1);

    void on_email_selectionChanged();

    void on_username_editingFinished();

private:
    Ui::Register *ui;
    bool checkPasssword(QString s);
    bool fieldsCompleted();

};

#endif // REGISTER_H
