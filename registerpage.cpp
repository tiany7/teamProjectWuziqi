#include "registerpage.h"
#include "ui_registerpage.h"
#include "login.h"
registerPage::registerPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registerPage),
    database(new Dialog())
{
    ui->setupUi(this);
    setWindowTitle("用户注册");
    connect(ui->password, SIGNAL(returnPressed()),this, SLOT(on_submit_clicked()));
    connect(ui->username, SIGNAL(returnPressed()),this, SLOT(on_submit_clicked()));
    connect(ui->confirmed, SIGNAL(returnPressed()),this, SLOT(on_submit_clicked()));
    ui->password->setEchoMode(QLineEdit::Password);
    ui->confirmed->setEchoMode(QLineEdit::Password);
    database->openDatabase();
    database->createTable("users");
}

registerPage::~registerPage()
{
    delete ui;
    delete database;
}

void registerPage::on_cancel_clicked()
{
    login *p = new login();
    this->close();//关闭页面
    p->show();

}

void registerPage::on_submit_clicked()
{
    QString user = ui->username->text();
    QString password = ui->password->text();
    QString confirmed = ui->confirmed->text();
   if(password != confirmed){
       QString dlgTitle=QStringLiteral("提示");
       QString strInfo=QStringLiteral("两次输入的密码不一致");
       QMessageBox::warning(this,dlgTitle,strInfo);
       return;
   }else if(!password.length()){
       QString dlgTitle=QStringLiteral("提示");
       QString strInfo=QStringLiteral("密码不能为空");
       QMessageBox::warning(this,dlgTitle,strInfo);
       return;
   }
    if(database->exist(user)){
        QString dlgTitle=QStringLiteral("提示");
        QString strInfo=QStringLiteral("用户名已存在，请更换后重试");
        QMessageBox::warning(this,dlgTitle,strInfo);
        return;
    }
    bool success = database->insert(user,password);
    if(success){
        QString dlgTitle=QStringLiteral("恭喜");
        QString strInfo=QStringLiteral("您已成功注册！");
        QMessageBox::warning(this,dlgTitle,strInfo);
        login *p = new login();
        p->show();
        this->close();
    }else{
        QString dlgTitle=QStringLiteral("创建失败");
        QString strInfo=QStringLiteral("请稍后重试或联系管理员");
        QMessageBox::warning(this,dlgTitle,strInfo);
    }
}
