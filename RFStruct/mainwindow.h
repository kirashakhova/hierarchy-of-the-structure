#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Тут ничего важного

#include "legotreemodel.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);

    void on_addButton_clicked();

    void on_delete_2_clicked();

    void on_upButton_clicked();

    void on_Model_clicked();

    void on_Tree_clicked();

    void on_addToList_clicked();

    void on_clear_clicked();

    void on_findDistanse_clicked();

    void on_edit_clicked();

    void on_photo_clicked();

private:
    Ui::MainWindow *ui;
    LegoTreeModel *mainModel;
    QPixmap pic;

};
#endif // MAINWINDOW_H
