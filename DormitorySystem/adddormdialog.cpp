#include "adddormdialog.h"
#include "ui_adddormdialog.h"

AddDormDialog::AddDormDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDormDialog)
{
    ui->setupUi(this);
}

AddDormDialog::~AddDormDialog()
{
    delete ui;
}

QString AddDormDialog::get_Dorm_name(){ return ui->DormNameLineEdit->text(); }

int AddDormDialog::get_Capacity(){ return ui->CapacityLineEdit->text().toInt(); }

int AddDormDialog::get_Rooms_capacity(){ return ui->RoomCapLineEdit->text().toInt(); }