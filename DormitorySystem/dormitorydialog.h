#ifndef DORMITORYDIALOG_H
#define DORMITORYDIALOG_H

#include <QDialog>
#include <vector>
#include "../dorm.h"

namespace Ui {
class DormitoryDialog;
}

class DormitoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DormitoryDialog(QWidget *parent, std::vector <dormitory>& dorms);
    ~DormitoryDialog();
    QString get_Dorm();
    int get_Room();

private:
    Ui::DormitoryDialog *ui;
    std::vector <dormitory> dorms;

private slots:
    void onDormSelected(const QString& dormname);
};

#endif // DORMITORYDIALOG_H
