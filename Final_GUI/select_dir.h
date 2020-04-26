#ifndef SELECT_DIR_H
#define SELECT_DIR_H

#include <QDialog>

namespace Ui {
class select_dir;
}

class select_dir : public QDialog
{
    Q_OBJECT

public:
    explicit select_dir(QWidget *parent = 0);
    ~select_dir();

private:
    Ui::select_dir *ui;
};

#endif // SELECT_DIR_H
