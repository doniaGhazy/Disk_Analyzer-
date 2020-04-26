#include "exit_dialog.h"
#include "ui_exit_dialog.h"
#include<QApplication>

Exit_dialog::Exit_dialog(QWidget *parent): QDialog(parent), ui(new Ui::Exit_dialog)
{
    ui->setupUi(this);
}

Exit_dialog::~Exit_dialog()
{
    delete ui;
}

void Exit_dialog::on_Exit_btnBox_accepted()
{
 QApplication::closeAllWindows();
}

void Exit_dialog::on_Exit_btnBox_rejected()
{
   close();
}
