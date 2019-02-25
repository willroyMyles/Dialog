#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class CustomDialog : public QDialog
{
public:
    CustomDialog();
    QWidget *holder; // body of the widget
    QWidget *buttonWidget;
    QVBoxLayout *holderLayout;
    QLineEdit *lineEdit;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QHBoxLayout *buttonHolder;

    void addConfirmButton(QString text = "ok");
    void addCancelButton(QString text = "cancel");
    void addConfirmAndCancelButtons();

    void insertWidget(QWidget *widget);

private:
    void configureConnections();
};

#endif // CUSTOMDIALOG_H
