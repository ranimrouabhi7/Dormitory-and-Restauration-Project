#include "dialogaddstud.h"
#include "ui_dialogaddstud.h"

DialogAddStud::DialogAddStud(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAddStud)
{
    ui->setupUi(this);
}

DialogAddStud::~DialogAddStud()
{
    delete ui;
}

int DialogAddStud::get_ID(){ return ui->IDinput->text().toInt(); }

QString DialogAddStud::get_FullName(){ return ui->Fullnameinput->text(); }

int DialogAddStud::get_Acc_Year(){ return ui->AcademicYearSpinBox->value(); }

bool DialogAddStud::get_Accomondation_Status(){ return ui->Acc_statusCheckBox->isChecked(); }