#include "is_clear_marked_pid.h"
#include "ui_is_clear_marked_pid.h"

is_clear_marked_pid::is_clear_marked_pid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::is_clear_marked_pid)
{
    ui->setupUi(this);
}

is_clear_marked_pid::~is_clear_marked_pid()
{
    delete ui;
}
