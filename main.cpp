#include "mainwindow.h"
#include <QApplication>
#include "registerpage.h"
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   login page;
   page.show();
    return a.exec();
}
