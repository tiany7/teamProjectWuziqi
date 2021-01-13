#ifndef PURCHASEMENU_H
#define PURCHASEMENU_H

#include <QDialog>

namespace Ui {
class purchaseMenu;
}

class purchaseMenu : public QDialog
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit purchaseMenu(QWidget *parent = nullptr,const QString &username = "user");
    ~purchaseMenu();

private slots:

    void on_fst_linkActivated(const QString &link);

private:
    Ui::purchaseMenu *ui;
    QString user;
};

#endif // PURCHASEMENU_H
