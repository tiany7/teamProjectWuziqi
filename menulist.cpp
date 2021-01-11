#include "menulist.h"
#include "ui_menulist.h"

menuList::menuList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menuList)
{
    ui->setupUi(this);
}

menuList::~menuList()
{
    delete ui;
}

void menuList::on_pushButton_clicked()
{
    printf("%s", "here is me");
}
