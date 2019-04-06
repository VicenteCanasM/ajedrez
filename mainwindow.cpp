#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include "tablero.h"
using namespace std;

static vector < vector <QPushButton>> botones;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* QPalette prueba = ui->boton11 -> palette();
    prueba.setColor(QPalette::Button,QColor(Qt::gray));
    ui -> boton11 -> setAutoFillBackground(true);
    ui -> boton11 -> setPalette(prueba);
    ui -> boton11 -> update();*/
    vector < vector < int >> pos_inicial(8, vector <int>(8,2));
    for (unsigned long i = 0; i < 8; i++){
        for (unsigned long j = 0; j < 8; j++){
            if (i < 2) pos_inicial[i][j] = 0;
            else if (i > 5) pos_inicial[i][j] = 1;
        }
    }
    tablero echiquier(pos_inicial);
    echiquier.imprimir_tablero();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_a1_clicked()
{
    /*QPalette prueba = ui->boton11 -> palette();
    if (click == 0){
        prueba.setColor(QPalette::Button,QColor(Qt::darkCyan));
        click = 1;
    }else{
        prueba.setColor(QPalette::Button,QColor(Qt::gray));
        click = 0;
    }
    ui -> boton11 -> setAutoFillBackground(true);
    ui -> boton11 -> setPalette(prueba);
    ui -> boton11 -> update();*/
}

void MainWindow::on_a2_clicked()
{

}
