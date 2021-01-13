#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
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
#include "menulist.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    bool openDatabase(const QString &type = "QSQLITE",
                              const QString &host = "127.0.0.1",
                              const QString &db_name = "user_db",
                              const QString &account_name = "root",
                              const QString &password = "root");
    void createTable(const QString &name = "tb");
    bool insert(const QString &username, const QString &password);
    bool verify(const QString &username, const QString &password);
    bool exist(const QString &username);
private:
    Ui::Dialog *ui;
    QSqlDatabase user_db;
    int user_account;
};

#endif // DIALOG_H
