#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->floatSliderWidget->setRange(95, 105);
    ui->floatSliderWidget->setStep(0.1);
    ui->floatSliderWidget->slider->setFloat(95, 0.1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    qDebug()<<"change value  "<<value;
    ui->spinBox->setValue(value);
}
