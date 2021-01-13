#include "purchasemenu.h"
#include "ui_purchasemenu.h"
#include <QLabel>
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
#include "purchasemenu.h"
#define TIGA ":/res/picture/tiga.JPG"
#define GAIYA "C:\\Users\tiany\\Documents\\teamProjectWuziqi\\res\\gaiya.jpg"
#define AGUL "C:\\Users\tiany\\Documents\\teamProjectWuziqi\\res\\aguru.jpg"

purchaseMenu::purchaseMenu(QWidget *parent, const QString &username) :
    QDialog(parent),
    ui(new Ui::purchaseMenu)
{
    ui->setupUi(this);
    ui->username->setText(username);
   setWindowTitle("购买道具");
   QImage *tiga = new QImage(TIGA), * Gaiya , * Agu;
   Gaiya = new QImage(GAIYA);
   Agu = new QImage(AGUL);
   QPixmap *p = new QPixmap;
   p->load(TIGA);
   p->scaled(tiga->size(),Qt::KeepAspectRatio);
   ui->fst->setPixmap(*p);
}

purchaseMenu::~purchaseMenu()
{
    delete ui;
}


void purchaseMenu::on_fst_linkActivated(const QString &link)
{
   QImage *tiga = new QImage(TIGA), * Gaiya , * Agu;
   Gaiya = new QImage(GAIYA);
   Agu = new QImage(AGUL);
   QPixmap *p = new QPixmap;
   p->load(TIGA);
   p->scaled(tiga->size(),Qt::KeepAspectRatio);
   ui->fst->setPixmap(*p);
}
