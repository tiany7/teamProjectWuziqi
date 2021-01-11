#ifndef MENULIST_H
#define MENULIST_H

#include <QDialog>

namespace Ui {
class menuList;
}

class menuList : public QDialog
{
    Q_OBJECT

public:
    explicit menuList(QWidget *parent = nullptr);

    ~menuList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::menuList *ui;
};

#endif // MENULIST_H
