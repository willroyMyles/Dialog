#include "customdialog.h"
#include "stylesheet.h"

#include <QGraphicsDropShadowEffect>
#include <QVBoxLayout>

CustomDialog::CustomDialog() : QDialog()
{
    setAttribute(Qt::WA_MacShowFocusRect, false);
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint );
    setAttribute(Qt::WA_TranslucentBackground);


    auto layout = new QVBoxLayout();
    setLayout(layout);

    layout->setContentsMargins(20,20,20,20);

    auto effect = new QGraphicsDropShadowEffect;
    effect->setOffset(0);
    effect->setBlurRadius(15);
    effect->setColor(QColor(0,0,0));
    //this->setGraphicsEffect(effect);

    holder = new QWidget;
    holderLayout = new QVBoxLayout;
    holder->setLayout(holderLayout);
    holder->setStyleSheet(StyleSheet::QWidgetDark());
    holder->setGraphicsEffect(effect);
    holder->setMinimumSize(300,200);
    holderLayout->addStretch();



    buttonWidget = new QWidget;
    buttonHolder = new QHBoxLayout;
    buttonHolder->addStretch(20);
    buttonWidget->setLayout(buttonHolder);

    holderLayout->addWidget(buttonWidget);

    layout->addWidget(holder);

}

//should add before cancel button
void CustomDialog::addConfirmButton(QString text)
{
    okBtn = new QPushButton(text, this);
    okBtn->setStyleSheet(StyleSheet::QPushButtonGreyscale());
    if(!buttonHolder->children().contains(okBtn)) buttonHolder->addWidget(okBtn);
    configureConnections();
}

//should be added after confirm button
void CustomDialog::addCancelButton(QString text)
{
    cancelBtn = new QPushButton(text, this);
    cancelBtn->setStyleSheet(StyleSheet::QPushButtonGreyscale());
    if(!buttonHolder->children().contains(cancelBtn)) buttonHolder->addWidget(cancelBtn);
    configureConnections();
}

void CustomDialog::addConfirmAndCancelButtons()
{
    addConfirmButton();
    addCancelButton();
    configureConnections();
}

//inset in stacked order
void CustomDialog::insertWidget(QWidget *widget)
{
    holderLayout->insertWidget(1,widget);
}

//should be called after buttons added
void CustomDialog::configureConnections()
{
    if(buttonWidget->children().contains(okBtn))
    connect(okBtn, &QPushButton::clicked,[=](){
        emit accepted();
        close();
    });
    if(buttonWidget->children().contains(cancelBtn))
    connect(cancelBtn, &QPushButton::clicked,[=](){
        emit rejected();
        close();
    });

}

