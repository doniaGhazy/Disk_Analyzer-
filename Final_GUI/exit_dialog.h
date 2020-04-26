#ifndef EXIT_DIALOG_H
#define EXIT_DIALOG_H

#include <QDialog>

namespace Ui {
class Exit_dialog;
}

class Exit_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Exit_dialog(QWidget *parent = nullptr);
    ~Exit_dialog();

private slots:
    void on_Exit_btnBox_accepted();
    void on_Exit_btnBox_rejected();

private:
    Ui::Exit_dialog *ui;
};

#endif // EXIT_DIALOG_H
