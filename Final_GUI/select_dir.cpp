#include "select_dir.h"
#include "ui_select_dir.h"

select_dir::select_dir(QWidget *parent): QDialog(parent), ui(new Ui::select_dir)
{
    ui->setupUi(this);
}

select_dir::~select_dir()
{
    delete ui;
}
