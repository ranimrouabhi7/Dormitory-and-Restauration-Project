#ifndef ADDDORMDIALOG_H
#define ADDDORMDIALOG_H

#include <QDialog>

namespace Ui {
class AddDormDialog;
}

class AddDormDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDormDialog(QWidget *parent = nullptr);
    ~AddDormDialog();
    QString get_Dorm_name();
    int get_Capacity();
    int get_Rooms_capacity();

private:
    Ui::AddDormDialog *ui;
};

#endif // ADDDORMDIALOG_H
