#include "dialog.h"
#include "ui_dialog.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
bool Dialog::openDatabase(const QString &type, const QString &host, const QString &db_name, const QString &account_name, const QString &password){
        user_db = QSqlDatabase::addDatabase(type);
        user_db.setHostName(host);
        user_db.setDatabaseName(db_name);
        user_db.setUserName(account_name);
        user_db.setPassword(password);
        if(user_db.open()){
            QString dlgTitle=QStringLiteral("数据库");
                QString strInfo=QStringLiteral("连接成功");
                QMessageBox::warning(this,dlgTitle,strInfo);
                return true;
        }else{
            QString dlgTitle=QStringLiteral("错误");
                QString strInfo=QStringLiteral("数据库连接失败，请检查SQL连接设置");
                QMessageBox::warning(this,dlgTitle,strInfo);
                return false;
        }
}
void Dialog::createTable(const QString &name){
    QSqlQuery query(user_db);
    bool success = query.exec("CREATE TABLE IF NOT EXISTS " + name +
                              "( user_id INT auto_increment,user_password VARCHAR(50),user_name VARCHAR(50),account_balance DECIMAL(32,2) DEFAULT 0.0,expiration_date DATETIME,PRIMARY KEY(user_id))");
    if(success){
        qDebug() << QObject::tr("创建成功！\n");
    }else{
        qDebug() << QObject::tr("创建失败！请检查SQL\n");
    }
}

