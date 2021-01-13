#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H
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
class registerPage;
}

class registerPage : public QDialog
{
    Q_OBJECT

public:
    explicit registerPage(QWidget *parent = nullptr);
    ~registerPage();

private slots:
    void on_cancel_clicked();

    void on_submit_clicked();

private:
    Ui::registerPage *ui;
    Dialog *database;
};

#endif // REGISTERPAGE_H
