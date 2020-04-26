/********************************************************************************
** Form generated from reading UI file 'exit_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXIT_DIALOG_H
#define UI_EXIT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Exit_dialog
{
public:
    QDialogButtonBox *Exit_btnBox;
    QLabel *label;

    void setupUi(QDialog *Exit_dialog)
    {
        if (Exit_dialog->objectName().isEmpty())
            Exit_dialog->setObjectName(QString::fromUtf8("Exit_dialog"));
        Exit_dialog->resize(356, 145);
        Exit_btnBox = new QDialogButtonBox(Exit_dialog);
        Exit_btnBox->setObjectName(QString::fromUtf8("Exit_btnBox"));
        Exit_btnBox->setGeometry(QRect(-80, 70, 341, 32));
        Exit_btnBox->setOrientation(Qt::Horizontal);
        Exit_btnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Exit_dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 251, 61));

        retranslateUi(Exit_dialog);
        QObject::connect(Exit_btnBox, SIGNAL(accepted()), Exit_dialog, SLOT(accept()));
        QObject::connect(Exit_btnBox, SIGNAL(rejected()), Exit_dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Exit_dialog);
    } // setupUi

    void retranslateUi(QDialog *Exit_dialog)
    {
        Exit_dialog->setWindowTitle(QCoreApplication::translate("Exit_dialog", "Exit", nullptr));
        label->setText(QCoreApplication::translate("Exit_dialog", "<html><head/><body><p><span style=\" font-weight:600;\">Are You Sure that You want to Exit?</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Exit_dialog: public Ui_Exit_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXIT_DIALOG_H
