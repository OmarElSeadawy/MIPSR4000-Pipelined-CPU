#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    //Dialog(Ui::Dialog *ui);
    ~Dialog();

private slots:

    void on_pushButton_clicked();

    void on_run_once_clicked();

    void on_run_all_clicked();

private:
    Ui::Dialog *ui;
    QStandardItemModel *model_reg;
    QStandardItemModel *model_mem;
    QStandardItemModel *cycles;
    QStandardItemModel *branch;
    QStandardItemModel *procedures;
    QPushButton *run_once;
};

#endif // DIALOG_H
