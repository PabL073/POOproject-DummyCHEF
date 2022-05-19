#ifndef ADDRETETA_H
#define ADDRETETA_H

#include <QDialog>

namespace Ui {
class addReteta;
}

class addReteta : public QDialog
{
    Q_OBJECT

public:
    bool pathSET=false;
    explicit addReteta(QWidget *parent = nullptr);
    ~addReteta();
    //void addImagePath(QString s){this->imagePath=s;pathSET=true;}
    //QString getImagePath(){return this->imagePath;}

private slots:

    //void on_Cancel_rejected();

    void on_SendRetetaButton_accepted();

    void on_pushButton_clicked();

    //QString imagePath;


private:
    Ui::addReteta *ui;
};

#endif // ADDRETETA_H
