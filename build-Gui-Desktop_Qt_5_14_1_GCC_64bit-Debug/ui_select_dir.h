/********************************************************************************
** Form generated from reading UI file 'select_dir.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_DIR_H
#define UI_SELECT_DIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_select_dir
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *select_dir)
    {
        if (select_dir->objectName().isEmpty())
            select_dir->setObjectName(QString::fromUtf8("select_dir"));
        select_dir->resize(400, 300);
        buttonBox = new QDialogButtonBox(select_dir);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(select_dir);
        QObject::connect(buttonBox, SIGNAL(accepted()), select_dir, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), select_dir, SLOT(reject()));

        QMetaObject::connectSlotsByName(select_dir);
    } // setupUi

    void retranslateUi(QDialog *select_dir)
    {
        select_dir->setWindowTitle(QCoreApplication::translate("select_dir", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class select_dir: public Ui_select_dir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_DIR_H
