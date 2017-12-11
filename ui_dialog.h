/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTableView *regFile;
    QTableView *Dmem;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPlainTextEdit *plainTextEdit;
    QTableView *tableView2;
    QPushButton *run_once;
    QPushButton *run_all;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTableView *BTB_2;
    QTableView *stack;
    QLabel *label_7;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(990, 652);
        regFile = new QTableView(Dialog);
        regFile->setObjectName(QStringLiteral("regFile"));
        regFile->setGeometry(QRect(840, 70, 141, 561));
        Dmem = new QTableView(Dialog);
        Dmem->setObjectName(QStringLiteral("Dmem"));
        Dmem->setGeometry(QRect(660, 70, 151, 561));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(870, 40, 81, 16));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(690, 40, 81, 16));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 260, 111, 32));
        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 10, 131, 251));
        tableView2 = new QTableView(Dialog);
        tableView2->setObjectName(QStringLiteral("tableView2"));
        tableView2->setGeometry(QRect(190, 10, 431, 261));
        run_once = new QPushButton(Dialog);
        run_once->setObjectName(QStringLiteral("run_once"));
        run_once->setGeometry(QRect(250, 270, 113, 32));
        run_all = new QPushButton(Dialog);
        run_all->setObjectName(QStringLiteral("run_all"));
        run_all->setGeometry(QRect(420, 270, 113, 32));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(420, 600, 51, 31));
        QFont font;
        font.setPointSize(24);
        label_3->setFont(font);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(260, 370, 60, 16));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(390, 370, 51, 20));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(520, 370, 91, 16));
        BTB_2 = new QTableView(Dialog);
        BTB_2->setObjectName(QStringLiteral("BTB_2"));
        BTB_2->setGeometry(QRect(260, 400, 351, 192));
        stack = new QTableView(Dialog);
        stack->setObjectName(QStringLiteral("stack"));
        stack->setGeometry(QRect(40, 420, 131, 131));
        label_7 = new QLabel(Dialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 570, 191, 21));
        QFont font1;
        font1.setPointSize(26);
        label_7->setFont(font1);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Register File", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Data Memory", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog", "Load Program", Q_NULLPTR));
        run_once->setText(QApplication::translate("Dialog", "Run Once", Q_NULLPTR));
        run_all->setText(QApplication::translate("Dialog", "Run All", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "BTB", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "PC", Q_NULLPTR));
        label_5->setText(QApplication::translate("Dialog", "Target", Q_NULLPTR));
        label_6->setText(QApplication::translate("Dialog", "Prediction Bits", Q_NULLPTR));
        label_7->setText(QApplication::translate("Dialog", "Procedure Stack", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
