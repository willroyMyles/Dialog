#include "customdialog.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CustomDialog w;
    w.addConfirmAndCancelButtons();
    w.insertWidget(new QLabel("hello"));
    w.exec();

    return a.exec();
}
