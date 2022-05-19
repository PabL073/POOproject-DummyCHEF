#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QListWidgetItem>

namespace Ui {
class mainpage;
}

class mainpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainpage(QWidget *parent = nullptr);
    ~mainpage();

private slots:
    void on_addReteta_clicked();

    //void on_backButton_clicked();

    void on_logoutButton_clicked();

    //void on_searchList_itemClicked(QListWidgetItem *item);

    void on_searchButtomn_clicked();

    void on_searchButtonNume_clicked();

    void on_favoritesButton_clicked();

    void on_listaCautari_itemDoubleClicked(QListWidgetItem *item);

    //void on_listaCautari_itemClicked(QListWidgetItem *item);

    void on_top_clicked();

    void on_pushButton_clicked();

private:
    Ui::mainpage *ui;
};

#endif // MAINPAGE_H
