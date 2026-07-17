#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../dorm.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void add_to_dorms(dormitory);

private slots:
    void on_AddStudentBtn_clicked();
    void on_AddDormBtn_clicked();


private:
    Ui::MainWindow *ui;
    std::vector<dormitory> dorms;
};
#endif // MAINWINDOW_H
