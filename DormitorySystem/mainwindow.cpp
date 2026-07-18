#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogaddstud.h"
#include "../student.h"
#include "dormitorydialog.h"
#include "../dorm.h"
#include "adddormdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->listWidget, &QListWidget::currentRowChanged,
            ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    ui->listWidget->setCurrentRow(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_AddStudentBtn_clicked()
{
    DialogAddStud dialog(this); // create teh dialog window object
    if ( dialog.exec() == QDialog::Accepted ) // when the dialg finishes
    {
        int row = ui->StudentsTable->rowCount();

        ui->StudentsTable->insertRow(row);
        ui->StudentsTable->setItem(row, 0, new QTableWidgetItem(QString::number(dialog.get_ID())));
        ui->StudentsTable->setItem(row, 1, new QTableWidgetItem(dialog.get_FullName()));
        ui->StudentsTable->setItem(row, 2, new QTableWidgetItem(QString::number(dialog.get_Acc_Year())));

        if ( dialog.get_Accomondation_Status() )
        {
            DormitoryDialog dormassignment(this,dorms);

            if ( dormassignment.exec() == QDialog::Accepted )
            {
                resident_student res_stud (dialog.get_ID(),
                                          dialog.get_FullName().toStdString(),
                                          dialog.get_Acc_Year(),
                                          dormassignment.get_Dorm().toStdString(),
                                          dormassignment.get_Room());

                for ( size_t i = 0 ; i < dorms.size(); i++ )
                {
                    if( dormassignment.get_Dorm().toStdString() == (dorms.begin() + i)->get_dorm_name() )
                    {
                        (dorms.begin() + i)->add_student( res_stud, dormassignment.get_Room() ); // adding a student to the vector students
                        break;
                    }
                }
                ui->StudentsTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString("resident")));
                ui->StudentsTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(res_stud.get_dormitory())));
                ui->StudentsTable->setItem(row, 5, new QTableWidgetItem(QString::number(res_stud.get_room())));
            }
        }
        else
        {
            student stud (dialog.get_ID(),
                         dialog.get_FullName().toStdString(),
                         dialog.get_Acc_Year());
            ui->StudentsTable->setItem(row, 3, new QTableWidgetItem(QString::fromStdString("not resident")));
            ui->StudentsTable->setItem(row, 4, new QTableWidgetItem(QString::fromStdString("-")));
            ui->StudentsTable->setItem(row, 5, new QTableWidgetItem(QString::fromStdString("-")));
        }
    }
}


void MainWindow::on_AddDormBtn_clicked()
{
    AddDormDialog dorm(this);
    if( dorm.exec() == QDialog::Accepted )
    {
        dormitory dormi(dorm.get_Capacity(),
                        dorm.get_Dorm_name().toStdString(),
                        dorm.get_Rooms_capacity());

        dorms.push_back(dormi);

        int row = ui->Dorm_table->rowCount();
        ui->Dorm_table->insertRow(row);
        ui->Dorm_table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(dormi.get_dorm_name())));
        ui->Dorm_table->setItem(row, 1, new QTableWidgetItem(QString::number(dormi.get_capacity())));
        ui->Dorm_table->setItem(row, 2, new QTableWidgetItem(QString::number(dormi.get_rooms_capacity())));
    }
}





