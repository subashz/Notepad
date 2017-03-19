#include "gotodialog.h"
#include "ui_gotodialog.h"

GotoDialog::GotoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GotoDialog)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0,100,this));
}

GotoDialog::~GotoDialog()
{
    delete ui;
}
