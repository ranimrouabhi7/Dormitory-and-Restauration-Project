#ifndef DIALOGADDSTUD_H
#define DIALOGADDSTUD_H

#include <QDialog>

namespace Ui {
class DialogAddStud;
}

class DialogAddStud : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddStud(QWidget *parent = nullptr);
    ~DialogAddStud();
    int get_ID();
    QString get_FullName();
    int get_Acc_Year();
    bool get_Accomondation_Status();

private:
    Ui::DialogAddStud *ui;
};

#endif // DIALOGADDSTUD_H
