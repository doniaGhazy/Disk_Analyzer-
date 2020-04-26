/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_aboutDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *aboutDialog)
    {
        if (aboutDialog->objectName().isEmpty())
            aboutDialog->setObjectName(QString::fromUtf8("aboutDialog"));
        aboutDialog->resize(403, 315);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(aboutDialog->sizePolicy().hasHeightForWidth());
        aboutDialog->setSizePolicy(sizePolicy);
        label = new QLabel(aboutDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 9, 371, 271));

        retranslateUi(aboutDialog);

        QMetaObject::connectSlotsByName(aboutDialog);
    } // setupUi

    void retranslateUi(QDialog *aboutDialog)
    {
        aboutDialog->setWindowTitle(QCoreApplication::translate("aboutDialog", "About Us", nullptr));
        label->setText(QCoreApplication::translate("aboutDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600;\">Disk Analyzer 1.0</span></p><p><span style=\" font-size:16pt; font-weight:600; font-style:italic;\">Authors:</span></p><p><span style=\" font-size:12pt;\">Ahmed Esam</span></p><p><span style=\" font-size:12pt;\">Donia Ghazy</span></p><p><span style=\" font-size:12pt;\">Ismael Elsharkawi</span></p><p><span style=\" font-size:12pt;\">Marwan Eid</span></p><p><span style=\" font-size:12pt;\">Mohammed Osama</span></p><p><span style=\" font-family:'arial,sans-serif'; font-size:16px; color:#cc0000; background-color:#ffffff;\">Copyright \302\251 2020</span></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p><p><br/></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class aboutDialog: public Ui_aboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
