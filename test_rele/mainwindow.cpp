#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

#include "bcm2835.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rele220 = new RRele220_4("Rele220_4", 17, 27, 22, 23, this);

    ui->comboBox->addItems(rele220->getParametersList());

    connect(ui->pbSet, SIGNAL(clicked()), SLOT(setSlot()));
    connect(ui->pbGet, SIGNAL(clicked()), SLOT(getSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSlot()
{
    bool rez = rele220->setValue(ui->comboBox->currentText(), ui->comboBox_2->currentText());
    if (rez)
        ui->label->setText("success");
    else
        ui->label->setText("failed");
}

void MainWindow::getSlot()
{
    QString rez = rele220->getValue(ui->comboBox->currentText());
    ui->comboBox_2->setCurrentIndex(ui->comboBox_2->findText(rez));
}
