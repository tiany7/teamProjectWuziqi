#include "dialog.h"
#include "ui_dialog.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    user_account(0)
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
           // QString dlgTitle=QStringLiteral("数据库");
               // QString strInfo=QStringLiteral("连接成功");
                //QMessageBox::warning(this,dlgTitle,strInfo);
                return true;
        }else{
            //QString dlgTitle=QStringLiteral("错误");
               // QString strInfo=QStringLiteral("数据库连接失败，请检查SQL连接设置");
                //QMessageBox::warning(this,dlgTitle,strInfo);
                return false;
        }
}
void Dialog::createTable(const QString &name){
    QSqlQuery query(user_db);
    bool success = query.exec("CREATE TABLE IF NOT EXISTS " + name +
                              "( user_id INT auto_increment,user_password VARCHAR(50),user_name VARCHAR(50),account_balance DECIMAL(32,2) DEFAULT 0.0,PRIMARY KEY(user_id))");
    if(success){
        qDebug() << QObject::tr("创建成功！\n");
    }else{
        qDebug() << QObject::tr("创建失败！请检查SQL\n");
    }
}
bool Dialog::insert(const QString &username, const QString &password){
    bool success = false;
    if(user_db.open()){
        QSqlQuery query(user_db);
        QString dbname = "users";
       query.prepare("INSERT INTO users(user_name,user_password,account_balance) VALUES(:username, :password, :balance)");
       query.bindValue(":username",username);
       query.bindValue(":password",password);
       QString balance = "0";
       query.bindValue(":balance",balance);
        success = query.exec();
        if(success){
            qDebug() << QObject::tr("数据插入成功！\n");
        }else{
            qDebug() << QObject::tr("数据插入失败！请检查SQL\n");
        }
    }
    user_db.close();
    return success;
}
bool Dialog::verify(const QString &username, const QString &password){
    if(user_db.open()){
        QSqlQuery query2(user_db);
        query2.prepare("SELECT user_password FROM users WHERE user_name = :username");
        query2.bindValue(":username",username);
        int success = query2.exec();
        int num = query2.record().count();
        QString pass;
        if(query2.next()){
             pass = query2.value(0).toString();
        }
        if(pass == password){
            qDebug() << QObject::tr("密码匹配成功！\n");

        }else{
            qDebug() << QObject::tr("密码匹配失败！\n");
            user_db.close();
            return false;
        }

    }
    user_db.close();
    return true;
}
bool Dialog::exist(const QString &username){
    if(user_db.open()){
        QSqlQuery query(user_db);
        query.prepare("SELECT user_password FROM users WHERE user_name = :username");
        query.bindValue(":username",username);
        bool success = query.exec();
        if(success){
            user_db.close();
            return query.next();
        }else{
            user_db.close();
            qDebug() << QObject::tr("查询失败！\n");
           return false;
        }
    }
    return false;
}


