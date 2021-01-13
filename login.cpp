#include "login.h"
#include "ui_login.h"
#include <QPainter>
#include <QTimer>
#include <QSound>
#include <QMouseEvent>
#include <QMessageBox>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <math.h>
#include <QPalette>
#include "mainwindow.h"
#include <QPixmap>
#include <QPixmapCache>
#include <Qimage>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <dialog.h>
#include "menulist.h"
#include "login.h"
#include "mainwindow.h"
#include "registerpage.h"
login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login),
    database(new Dialog())
{
    ui->setupUi(this);
    setWindowTitle("用户登录");
    connect(ui->username, SIGNAL(returnPressed()),this, SLOT(on_log_clicked()));
    connect(ui->password, SIGNAL(returnPressed()),this, SLOT(on_log_clicked()));
    ui->password->setEchoMode(QLineEdit::Password);
    database->openDatabase();
    database->createTable("users");
}

login::~login()
{
    delete ui;
}

void login::on_cancel_clicked()
{
    this->close();//关闭页面
}


void login::on_log_clicked()
{
    QString user = ui->username->text();
    QString pass = ui->password->text();
    if(!user.length() || !pass.length()){
        QString dlgTitle=QStringLiteral("提示");
        QString strInfo=QStringLiteral("用户名或密码不能为空！");
        QMessageBox::warning(this,dlgTitle,strInfo);
        return;
    }
    bool success = database->verify(user,pass);
    //确认登陆
    if(success){
        QString dlgTitle=QStringLiteral("恭喜");
        QString strInfo=QStringLiteral("登录成功！");
        QMessageBox::warning(this,dlgTitle,strInfo);
        MainWindow *w = new MainWindow();
        w->currentUser = user;
        this->close();
       w->show();
    }else{
        QString dlgTitle=QStringLiteral("登陆失败");
        QString strInfo=QStringLiteral("用户名或密码错误，请稍后重试！");
        QMessageBox::warning(this,dlgTitle,strInfo);
        return;
    }
}

void login::on_commandLinkButton_clicked()
{
   registerPage *p = new registerPage();
   this->hide();
   p->show();
}
