#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "dialog.h"
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT
    friend class MainWindow;//友元类
public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_cancel_clicked();

    void on_log_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::login *ui;
    Dialog* database;
};

#endif // LOGIN_H
