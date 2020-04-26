/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionOpen_Directory;
    QAction *actionSettings;
    QAction *actionAnalyze_Folder;
    QAction *actionAnalyze_Home;
    QAction *actionExit;
    QWidget *centralwidget;
    QTreeWidget *directoryTree;
    QFrame *chartFrame;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuHelp;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1236, 714);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Icons/About.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon);
        actionOpen_Directory = new QAction(MainWindow);
        actionOpen_Directory->setObjectName(QString::fromUtf8("actionOpen_Directory"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/Icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Directory->setIcon(icon1);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/Icons/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon2);
        actionAnalyze_Folder = new QAction(MainWindow);
        actionAnalyze_Folder->setObjectName(QString::fromUtf8("actionAnalyze_Folder"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/Icons/root.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnalyze_Folder->setIcon(icon3);
        actionAnalyze_Home = new QAction(MainWindow);
        actionAnalyze_Home->setObjectName(QString::fromUtf8("actionAnalyze_Home"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/Icons/home.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAnalyze_Home->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/Icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon5);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        directoryTree = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        directoryTree->setHeaderItem(__qtreewidgetitem);
        directoryTree->setObjectName(QString::fromUtf8("directoryTree"));
        directoryTree->setGeometry(QRect(0, 0, 551, 531));
        chartFrame = new QFrame(centralwidget);
        chartFrame->setObjectName(QString::fromUtf8("chartFrame"));
        chartFrame->setGeometry(QRect(560, 0, 681, 591));
        horizontalLayout = new QHBoxLayout(chartFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1236, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTools = new QMenu(menubar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionAnalyze_Home);
        menuFile->addAction(actionAnalyze_Folder);
        menuFile->addAction(actionExit);
        menuTools->addAction(actionOpen_Directory);
        menuTools->addAction(actionSettings);
        menuHelp->addAction(actionAbout);
        toolBar->addAction(actionAnalyze_Home);
        toolBar->addAction(actionAnalyze_Folder);
        toolBar->addSeparator();
        toolBar->addAction(actionOpen_Directory);
        toolBar->addAction(actionSettings);
        toolBar->addAction(actionAbout);
        toolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Disk Analyzer", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionOpen_Directory->setText(QCoreApplication::translate("MainWindow", "Open Directory", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionAnalyze_Folder->setText(QCoreApplication::translate("MainWindow", "Analyze Folder", nullptr));
        actionAnalyze_Home->setText(QCoreApplication::translate("MainWindow", "Analyze Home", nullptr));
#if QT_CONFIG(tooltip)
        actionAnalyze_Home->setToolTip(QCoreApplication::translate("MainWindow", "Analyze Home", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
