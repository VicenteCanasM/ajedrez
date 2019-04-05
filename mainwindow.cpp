#include "mainwindow.h"
#include "piezas.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <utility>
using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


