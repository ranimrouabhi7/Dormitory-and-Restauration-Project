#include "dormitorydialog.h"
#include "ui_dormitorydialog.h"



DormitoryDialog::DormitoryDialog(QWidget *parent, std::vector<dormitory>& dorms)
    : QDialog(parent)
    , ui(new Ui::DormitoryDialog)
    , dorms(dorms)
{
    ui->setupUi(this);
    for( auto& d : dorms)
    {
        ui->DormComboBox->addItem(QString::fromStdString(d.get_dorm_name())); // addItem takes a QString
    }

    connect(ui->DormComboBox, &QComboBox::currentTextChanged,
            this, &DormitoryDialog::onDormSelected);
}

DormitoryDialog::~DormitoryDialog()
{
    delete ui;
}

void DormitoryDialog::onDormSelected(const QString& dormname)
{
    ui->RoomComboBox->clear();

    for ( auto& d : dorms )
    {
        if( QString::fromStdString(d.get_dorm_name()) == dormname )
        {
            for( int j = 0; j < d.get_capacity(); j++)
            {
                if( ! (d.get_rooms() + j)->is_fully_occupied() )
                {
                    ui->RoomComboBox->addItem(QString::number( j + 1));
                }
            }
        }
    }
}


QString DormitoryDialog::get_Dorm(){ return ui->DormComboBox->currentText(); }

int DormitoryDialog::get_Room(){ return ui->RoomComboBox->currentText().toInt(); }