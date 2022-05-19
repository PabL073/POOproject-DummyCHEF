#ifndef SHOWRETETA_H
#define SHOWRETETA_H

#include <QWidget>
#include "photo.h"

namespace Ui {
class showReteta;
}

class showReteta : public QWidget
{
    Q_OBJECT

public:
    explicit showReteta(QWidget *parent = nullptr);
    ~showReteta();
    void completeTitlu(QString s);
    void completeIngrediente(QStringList s);
    void completeDescriere(QString s);
    void completeNota(QString s);
    void completeRecenzii(QStringList s);
    void completeImagine();
    void verificareDrepturiStergere();


private slots:
    void addDataToPhoto(QByteArray data);

    void on_pushButton_clicked();

    void on_addNota_editingFinished();

    void on_addReview_clicked();

    void on_reviewTEXT_textChanged();

    void on_deleteButton_clicked();

    void on_stergeFavorite_clicked();

private:
    Ui::showReteta *ui;

    Photo *imagineReteta = nullptr;

};

#endif // SHOWRETETA_H
