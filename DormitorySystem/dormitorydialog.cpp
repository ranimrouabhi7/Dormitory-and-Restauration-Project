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
            this, &DormitoryDialog::onDormSelected); // connsect the selection with the onDormSelected

    if(!dorms.empty())
        onDormSelected(QString::fromStdString(dorms[0].get_dorm_name())); // this is for the first dorm
                                                                         // manually call the onDormSelected
}

DormitoryDialog::~DormitoryDialog()
{
    delete ui;
}

void DormitoryDialog::onDormSelected(const QString& dormname)
{
    ui->RoomComboBox->clear(); // each time the user select another dorm clear

    for ( auto& d : dorms ) // search on the dorm
    {
        if( QString::fromStdString(d.get_dorm_name()) == dormname )
        {
            for( int j = 0; j < d.get_capacity(); j++)
            {
                if( ! (d.get_rooms() + j)->is_fully_occupied() ) // if the room is not fully occupied add it
                {
                    ui->RoomComboBox->addItem(QString::number( j + 1));
                }
            }
        }
    }
}


QString DormitoryDialog::get_Dorm(){ return ui->DormComboBox->currentText(); }

int DormitoryDialog::get_Room(){ return ui->RoomComboBox->currentText().toInt(); }