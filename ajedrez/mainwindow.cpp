#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    estado_movimiento = true;

    vector < vector < int >> pos_inicial(8, vector <int>(8,2));
    for (unsigned long i = 0; i < 8; i++){
        for (unsigned long j = 0; j < 8; j++){
            if (i < 2) pos_inicial[i][j] = 0;
            else if (i > 5) pos_inicial[i][j] = 1;
        }
    }
    vector < vector < bool >> reyes(8, vector <bool>(8, false));
    reyes[4][0] = true;
    reyes[4][7] = true;

    gris.setColor(QPalette::Button,QColor(Qt::gray));
    blanco.setColor(QPalette::Button, QColor(Qt::white));
    azul.setColor(QPalette::Button,QColor(Qt::darkCyan));
    cian.setColor(QPalette::Button, QColor(Qt::cyan));

    iconos.resize(13);
    iconos[0] = QIcon("");
    iconos[1] = QIcon("pieces/merida_new/wp.svg");
    iconos[2] = QIcon("pieces/merida_new/wn.svg");
    iconos[3] = QIcon("pieces/merida_new/wb.svg");
    iconos[4] = QIcon("pieces/merida_new/wr.svg");
    iconos[5] = QIcon("pieces/merida_new/wq.svg");
    iconos[6] = QIcon("pieces/merida_new/wk.svg");
    iconos[7] = QIcon("pieces/merida_new/bp.svg");
    iconos[8] = QIcon("pieces/merida_new/bn.svg");
    iconos[9] = QIcon("pieces/merida_new/bb.svg");
    iconos[10] = QIcon("pieces/merida_new/br.svg");
    iconos[11] = QIcon("pieces/merida_new/bq.svg");
    iconos[12] = QIcon("pieces/merida_new/bk.svg");

    tablero aux(pos_inicial);
    echiquier = aux;
    echiquier.mat_escaque[0][0].t_icon = 4;
    echiquier.mat_escaque[1][0].t_icon = 2;
    echiquier.mat_escaque[2][0].t_icon = 3;
    echiquier.mat_escaque[3][0].t_icon = 5;
    echiquier.mat_escaque[4][0].t_icon = 6;
    echiquier.mat_escaque[5][0].t_icon = 3;
    echiquier.mat_escaque[6][0].t_icon = 2;
    echiquier.mat_escaque[7][0].t_icon = 4;
    echiquier.mat_escaque[0][1].t_icon = 1;
    echiquier.mat_escaque[1][1].t_icon = 1;
    echiquier.mat_escaque[2][1].t_icon = 1;
    echiquier.mat_escaque[3][1].t_icon = 1;
    echiquier.mat_escaque[4][1].t_icon = 1;
    echiquier.mat_escaque[5][1].t_icon = 1;
    echiquier.mat_escaque[6][1].t_icon = 1;
    echiquier.mat_escaque[7][1].t_icon = 1;
    echiquier.mat_escaque[0][7].t_icon = 10;
    echiquier.mat_escaque[1][7].t_icon = 8;
    echiquier.mat_escaque[2][7].t_icon = 9;
    echiquier.mat_escaque[3][7].t_icon = 11;
    echiquier.mat_escaque[4][7].t_icon = 12;
    echiquier.mat_escaque[5][7].t_icon = 9;
    echiquier.mat_escaque[6][7].t_icon = 8;
    echiquier.mat_escaque[7][7].t_icon = 10;
    echiquier.mat_escaque[0][6].t_icon = 7;
    echiquier.mat_escaque[1][6].t_icon = 7;
    echiquier.mat_escaque[2][6].t_icon = 7;
    echiquier.mat_escaque[3][6].t_icon = 7;
    echiquier.mat_escaque[4][6].t_icon = 7;
    echiquier.mat_escaque[5][6].t_icon = 7;
    echiquier.mat_escaque[6][6].t_icon = 7;
    echiquier.mat_escaque[7][6].t_icon = 7;
    /*QIcon caballo("pieces/merida_new/wn.svg");
    QIcon nada("");
    ui -> a1 ->setIcon(caballo);
    ui -> b1 -> setIcon(nada);*/

    // Inicialización de los colores de los botones de escaques
    {
        ui -> a1 -> setAutoFillBackground(true);
        ui -> a1 -> setPalette(gris);
        ui -> b1 -> setAutoFillBackground(true);
        ui -> b1 -> setPalette(blanco);
        ui -> c1 -> setAutoFillBackground(true);
        ui -> c1 -> setPalette(gris);
        ui -> d1 -> setAutoFillBackground(true);
        ui -> d1 -> setPalette(blanco);
        ui -> e1 -> setAutoFillBackground(true);
        ui -> e1 -> setPalette(gris);
        ui -> f1 -> setAutoFillBackground(true);
        ui -> f1 -> setPalette(blanco);
        ui -> g1 -> setAutoFillBackground(true);
        ui -> g1 -> setPalette(gris);
        ui -> h1 -> setAutoFillBackground(true);
        ui -> h1 -> setPalette(blanco);
        ui -> a2 -> setAutoFillBackground(true);
        ui -> a2 -> setPalette(blanco);
        ui -> b2 -> setAutoFillBackground(true);
        ui -> b2 -> setPalette(gris);
        ui -> c2 -> setAutoFillBackground(true);
        ui -> c2 -> setPalette(blanco);
        ui -> d2 -> setAutoFillBackground(true);
        ui -> d2 -> setPalette(gris);
        ui -> e2 -> setAutoFillBackground(true);
        ui -> e2 -> setPalette(blanco);
        ui -> f2 -> setAutoFillBackground(true);
        ui -> f2 -> setPalette(gris);
        ui -> g2 -> setAutoFillBackground(true);
        ui -> g2 -> setPalette(blanco);
        ui -> h2 -> setAutoFillBackground(true);
        ui -> h2 -> setPalette(gris);
        ui -> a3 -> setAutoFillBackground(true);
        ui -> a3 -> setPalette(gris);
        ui -> b3 -> setAutoFillBackground(true);
        ui -> b3 -> setPalette(blanco);
        ui -> c3 -> setAutoFillBackground(true);
        ui -> c3 -> setPalette(gris);
        ui -> d3 -> setAutoFillBackground(true);
        ui -> d3 -> setPalette(blanco);
        ui -> e3 -> setAutoFillBackground(true);
        ui -> e3 -> setPalette(gris);
        ui -> f3 -> setAutoFillBackground(true);
        ui -> f3 -> setPalette(blanco);
        ui -> g3 -> setAutoFillBackground(true);
        ui -> g3 -> setPalette(gris);
        ui -> h3 -> setAutoFillBackground(true);
        ui -> h3 -> setPalette(blanco);
        ui -> a4 -> setAutoFillBackground(true);
        ui -> a4 -> setPalette(blanco);
        ui -> b4 -> setAutoFillBackground(true);
        ui -> b4 -> setPalette(gris);
        ui -> c4 -> setAutoFillBackground(true);
        ui -> c4 -> setPalette(blanco);
        ui -> d4 -> setAutoFillBackground(true);
        ui -> d4 -> setPalette(gris);
        ui -> e4 -> setAutoFillBackground(true);
        ui -> e4 -> setPalette(blanco);
        ui -> f4 -> setAutoFillBackground(true);
        ui -> f4 -> setPalette(gris);
        ui -> g4 -> setAutoFillBackground(true);
        ui -> g4 -> setPalette(blanco);
        ui -> h4 -> setAutoFillBackground(true);
        ui -> h4 -> setPalette(gris);
        ui -> a5 -> setAutoFillBackground(true);
        ui -> a5 -> setPalette(gris);
        ui -> b5 -> setAutoFillBackground(true);
        ui -> b5 -> setPalette(blanco);
        ui -> c5 -> setAutoFillBackground(true);
        ui -> c5 -> setPalette(gris);
        ui -> d5 -> setAutoFillBackground(true);
        ui -> d5 -> setPalette(blanco);
        ui -> e5 -> setAutoFillBackground(true);
        ui -> e5 -> setPalette(gris);
        ui -> f5 -> setAutoFillBackground(true);
        ui -> f5 -> setPalette(blanco);
        ui -> g5 -> setAutoFillBackground(true);
        ui -> g5 -> setPalette(gris);
        ui -> h5 -> setAutoFillBackground(true);
        ui -> h5 -> setPalette(blanco);
        ui -> a6 -> setAutoFillBackground(true);
        ui -> a6 -> setPalette(blanco);
        ui -> b6 -> setAutoFillBackground(true);
        ui -> b6 -> setPalette(gris);
        ui -> c6 -> setAutoFillBackground(true);
        ui -> c6 -> setPalette(blanco);
        ui -> d6 -> setAutoFillBackground(true);
        ui -> d6 -> setPalette(gris);
        ui -> e6 -> setAutoFillBackground(true);
        ui -> e6 -> setPalette(blanco);
        ui -> f6 -> setAutoFillBackground(true);
        ui -> f6 -> setPalette(gris);
        ui -> g6 -> setAutoFillBackground(true);
        ui -> g6 -> setPalette(blanco);
        ui -> h6 -> setAutoFillBackground(true);
        ui -> h6 -> setPalette(gris);
        ui -> a7 -> setAutoFillBackground(true);
        ui -> a7 -> setPalette(gris);
        ui -> b7 -> setAutoFillBackground(true);
        ui -> b7 -> setPalette(blanco);
        ui -> c7 -> setAutoFillBackground(true);
        ui -> c7 -> setPalette(gris);
        ui -> d7 -> setAutoFillBackground(true);
        ui -> d7 -> setPalette(blanco);
        ui -> e7 -> setAutoFillBackground(true);
        ui -> e7 -> setPalette(gris);
        ui -> f7 -> setAutoFillBackground(true);
        ui -> f7 -> setPalette(blanco);
        ui -> g7 -> setAutoFillBackground(true);
        ui -> g7 -> setPalette(gris);
        ui -> h7 -> setAutoFillBackground(true);
        ui -> h7 -> setPalette(blanco);
        ui -> a8 -> setAutoFillBackground(true);
        ui -> a8 -> setPalette(blanco);
        ui -> b8 -> setAutoFillBackground(true);
        ui -> b8 -> setPalette(gris);
        ui -> c8 -> setAutoFillBackground(true);
        ui -> c8 -> setPalette(blanco);
        ui -> d8 -> setAutoFillBackground(true);
        ui -> d8 -> setPalette(gris);
        ui -> e8 -> setAutoFillBackground(true);
        ui -> e8 -> setPalette(blanco);
        ui -> f8 -> setAutoFillBackground(true);
        ui -> f8 -> setPalette(gris);
        ui -> g8 -> setAutoFillBackground(true);
        ui -> g8 -> setPalette(blanco);
        ui -> h8 -> setAutoFillBackground(true);
        ui -> h8 -> setPalette(gris);

        ui -> a1 -> update();
        ui -> b1 -> update();
        ui -> c1 -> update();
        ui -> d1 -> update();
        ui -> e1 -> update();
        ui -> f1 -> update();
        ui -> g1 -> update();
        ui -> h1 -> update();
        ui -> a2 -> update();
        ui -> b2 -> update();
        ui -> c2 -> update();
        ui -> d2 -> update();
        ui -> e2 -> update();
        ui -> f2 -> update();
        ui -> g2 -> update();
        ui -> h2 -> update();
        ui -> a3 -> update();
        ui -> b3 -> update();
        ui -> c3 -> update();
        ui -> d3 -> update();
        ui -> e3 -> update();
        ui -> f3 -> update();
        ui -> g3 -> update();
        ui -> h3 -> update();
        ui -> a4 -> update();
        ui -> b4 -> update();
        ui -> c4 -> update();
        ui -> d4 -> update();
        ui -> e4 -> update();
        ui -> f4 -> update();
        ui -> g4 -> update();
        ui -> h4 -> update();
        ui -> a5 -> update();
        ui -> b5 -> update();
        ui -> c5 -> update();
        ui -> d5 -> update();
        ui -> e5 -> update();
        ui -> f5 -> update();
        ui -> g5 -> update();
        ui -> h5 -> update();
        ui -> a6 -> update();
        ui -> b6 -> update();
        ui -> c6 -> update();
        ui -> d6 -> update();
        ui -> e6 -> update();
        ui -> f6 -> update();
        ui -> g6 -> update();
        ui -> h6 -> update();
        ui -> a7 -> update();
        ui -> b7 -> update();
        ui -> c7 -> update();
        ui -> d7 -> update();
        ui -> e7 -> update();
        ui -> f7 -> update();
        ui -> g7 -> update();
        ui -> h7 -> update();
        ui -> a8 -> update();
        ui -> b8 -> update();
        ui -> c8 -> update();
        ui -> d8 -> update();
        ui -> e8 -> update();
        ui -> f8 -> update();
        ui -> g8 -> update();
        ui -> h8 -> update();

    }
    //echiquier.imprimir_tablero();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_a1_clicked()
{
    ui -> a1 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[0][0].pulsado == 0){
        ui -> a1 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[0][0].pulsado = 1;
    }else{
        ui -> a1 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[0][0].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 0;
        escaque_origen.second = 0;
        estado_movimiento = false;
        boton_origen = ui -> a1;
    }else{
        pair<int,int> escaque_destino(0,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> a1, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> a1 -> update();
}


void MainWindow::on_a2_clicked()
{
    ui -> a2 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[0][1].pulsado == 0){
        ui -> a2 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[0][1].pulsado = 1;
    }else{
        ui -> a2 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[0][1].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 0;
        escaque_origen.second = 1;
        estado_movimiento = false;
        boton_origen = ui -> a2;
    }else{
        pair<int,int> escaque_destino(0,1);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> a2, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> a2 -> update();

}

void MainWindow::on_a3_clicked()
{
    ui -> a3 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[0][2].pulsado == 0){
        ui -> a3 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[0][2].pulsado = 1;
    }else{
        ui -> a3 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[0][2].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 0;
        escaque_origen.second = 2;
        estado_movimiento = false;
        boton_origen = ui -> a3;
    }else{
        pair<int,int> escaque_destino(0,2);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> a3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> a3 -> update();
}


void MainWindow::on_a4_clicked()
{
    ui -> a4 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[0][3].pulsado == 0){
        ui -> a4 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[0][3].pulsado = 1;
    }else{
        ui -> a4 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[0][3].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 0;
        escaque_origen.second = 3;
        estado_movimiento = false;
        boton_origen = ui -> a4;
    }else{
        pair<int,int> escaque_destino(0,3);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> a4, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> a4 -> update();
}

void MainWindow::on_a5_clicked()
{
    ui -> a5 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[0][4].pulsado == 0){
        ui -> a5 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[0][4].pulsado = 1;
    }else{
        ui -> a5 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[0][4].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 0;
        escaque_origen.second = 4;
        estado_movimiento = false;
        boton_origen = ui -> a5;
    }else{
        pair<int,int> escaque_destino(0,4);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> a5, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> a5 -> update();
}


void MainWindow::on_a6_clicked()
{
    ui -> a6 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[0][5].pulsado == 0){
        ui -> a6 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[0][5].pulsado = 1;
    }else{
        ui -> a6 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[0][5].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 0;
        escaque_origen.second = 5;
        estado_movimiento = false;
        boton_origen = ui -> a6;
    }else{
        pair<int,int> escaque_destino(0,5);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> a6, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> a6 -> update();
}

void MainWindow::on_a7_clicked()
{
    ui -> a7 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[0][6].pulsado == 0){
        ui -> a7 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[0][6].pulsado = 1;
    }else{
        ui -> a7 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[0][6].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 0;
        escaque_origen.second = 6;
        estado_movimiento = false;
        boton_origen = ui -> a7;
    }else{
        pair<int,int> escaque_destino(0,6);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> a7, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> a7 -> update();
}


void MainWindow::on_a8_clicked()
{
    ui -> a8 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[0][7].pulsado == 0){
        ui -> a8 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[0][7].pulsado = 1;
    }else{
        ui -> a8 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[0][7].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 0;
        escaque_origen.second = 7;
        estado_movimiento = false;
        boton_origen = ui -> a8;
    }else{
        pair<int,int> escaque_destino(0,7);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> a8, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> a8 -> update();
}

void MainWindow::on_b1_clicked()
{
    ui -> b1 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[1][0].pulsado == 0){
        ui -> b1 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[1][0].pulsado = 1;
    }else{
        ui -> b1 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[1][0].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 1;
        escaque_origen.second = 0;
        estado_movimiento = false;
        boton_origen = ui -> b1;
    }else{
        pair<int,int> escaque_destino(1,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> b1, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> b1 -> update();
}


void MainWindow::on_b2_clicked()
{
    ui -> b2 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[1][1].pulsado == 0){
        ui -> b2 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[1][1].pulsado = 1;
    }else{
        ui -> b2 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[1][1].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 1;
        escaque_origen.second = 1;
        estado_movimiento = false;
        boton_origen = ui -> b2;
    }else{
        pair<int,int> escaque_destino(1,1);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> b2, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> b2 -> update();
}

void MainWindow::on_b3_clicked()
{
    ui -> b3 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[1][2].pulsado == 0){
        ui -> b3 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[1][2].pulsado = 1;
    }else{
        ui -> b3 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[1][2].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 1;
        escaque_origen.second = 2;
        estado_movimiento = false;
        boton_origen = ui -> b3;
    }else{
        pair<int,int> escaque_destino(1,2);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> b3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> b3 -> update();
}


void MainWindow::on_b4_clicked()
{
    ui -> b4 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[1][3].pulsado == 0){
        ui -> b4 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[1][3].pulsado = 1;
    }else{
        ui -> b4 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[1][3].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 1;
        escaque_origen.second = 3;
        estado_movimiento = false;
        boton_origen = ui -> b3;
    }else{
        pair<int,int> escaque_destino(1,3);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> b3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> b4 -> update();
}

void MainWindow::on_b5_clicked()
{
    ui -> b5 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[1][4].pulsado == 0){
        ui -> b5 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[1][4].pulsado = 1;
    }else{
        ui -> b5 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[1][4].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 1;
        escaque_origen.second = 4;
        estado_movimiento = false;
        boton_origen = ui -> b5;
    }else{
        pair<int,int> escaque_destino(1,4);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> b5, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> b5 -> update();
}


void MainWindow::on_b6_clicked()
{
    ui -> b6 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[1][5].pulsado == 0){
        ui -> b6 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[1][5].pulsado = 1;
    }else{
        ui -> b6 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[1][5].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 1;
        escaque_origen.second = 5;
        estado_movimiento = false;
        boton_origen = ui -> b6;
    }else{
        pair<int,int> escaque_destino(1,5);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> b6, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> b6 -> update();
}

void MainWindow::on_b7_clicked()
{
    ui -> b7 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[1][6].pulsado == 0){
        ui -> b7 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[1][6].pulsado = 1;
    }else{
        ui -> b7 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[1][6].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 1;
        escaque_origen.second = 6;
        estado_movimiento = false;
        boton_origen = ui -> b7;
    }else{
        pair<int,int> escaque_destino(1,6);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> b7, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> b7 -> update();
}


void MainWindow::on_b8_clicked()
{
    ui -> b8 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[1][7].pulsado == 0){
        ui -> b8 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[1][7].pulsado = 1;
    }else{
        ui -> b8 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[1][7].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 1;
        escaque_origen.second = 7;
        estado_movimiento = false;
        boton_origen = ui -> b8;
    }else{
        pair<int,int> escaque_destino(1,7);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> b8, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> b8 -> update();
}

void MainWindow::on_c1_clicked()
{
    ui -> c1 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[2][0].pulsado == 0){
        ui -> c1 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[2][0].pulsado = 1;
    }else{
        ui -> c1 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[2][0].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 2;
        escaque_origen.second = 0;
        estado_movimiento = false;
        boton_origen = ui -> c1;
    }else{
        pair<int,int> escaque_destino(2,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> c1, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> c1 -> update();
}


void MainWindow::on_c2_clicked()
{
    ui -> c2 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[2][1].pulsado == 0){
        ui -> c2 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[2][1].pulsado = 1;
    }else{
        ui -> c2 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[2][1].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 2;
        escaque_origen.second = 1;
        estado_movimiento = false;
        boton_origen = ui -> c2;
    }else{
        pair<int,int> escaque_destino(2,1);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> c2, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> c2 -> update();
}

void MainWindow::on_c3_clicked()
{
    ui -> c3 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[2][2].pulsado == 0){
        ui -> c3 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[2][2].pulsado = 1;
    }else{
        ui -> c3 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[2][2].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 2;
        escaque_origen.second = 2;
        estado_movimiento = false;
        boton_origen = ui -> c3;
    }else{
        pair<int,int> escaque_destino(2,2);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> c3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> c3 -> update();
}


void MainWindow::on_c4_clicked()
{
    ui -> c4 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[2][3].pulsado == 0){
        ui -> c4 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[2][3].pulsado = 1;
    }else{
        ui -> c4 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[2][3].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 2;
        escaque_origen.second = 3;
        estado_movimiento = false;
        boton_origen = ui -> c4;
    }else{
        pair<int,int> escaque_destino(2,3);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> c4, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> c4 -> update();
}

void MainWindow::on_c5_clicked()
{
    ui -> c5 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[2][4].pulsado == 0){
        ui -> c5 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[2][4].pulsado = 1;
    }else{
        ui -> c5 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[2][4].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 2;
        escaque_origen.second = 4;
        estado_movimiento = false;
        boton_origen = ui -> c5;
    }else{
        pair<int,int> escaque_destino(2,4);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> c5, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> c5 -> update();
}


void MainWindow::on_c6_clicked()
{
    ui -> c6 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[2][5].pulsado == 0){
        ui -> c6 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[2][5].pulsado = 1;
    }else{
        ui -> c6 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[2][5].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 2;
        escaque_origen.second = 5;
        estado_movimiento = false;
        boton_origen = ui -> c6;
    }else{
        pair<int,int> escaque_destino(2,5);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> c6, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> c6 -> update();
}

void MainWindow::on_c7_clicked()
{
    ui -> c7 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[2][6].pulsado == 0){
        ui -> c7 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[2][6].pulsado = 1;
    }else{
        ui -> c7 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[2][6].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 2;
        escaque_origen.second = 6;
        estado_movimiento = false;
        boton_origen = ui -> c7;
    }else{
        pair<int,int> escaque_destino(2,6);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> c7, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> c7 -> update();
}


void MainWindow::on_c8_clicked()
{
    ui -> c8 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[2][7].pulsado == 0){
        ui -> c8 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[2][7].pulsado = 1;
    }else{
        ui -> c8 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[2][7].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 2;
        escaque_origen.second = 7;
        estado_movimiento = false;
        boton_origen = ui -> c8;
    }else{
        pair<int,int> escaque_destino(2,7);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> c8, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> c8 -> update();
}

void MainWindow::on_d1_clicked()
{
    ui -> d1 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[3][0].pulsado == 0){
        ui -> d1 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[3][0].pulsado = 1;
    }else{
        ui -> d1 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[3][0].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 3;
        escaque_origen.second = 0;
        estado_movimiento = false;
        boton_origen = ui -> d1;
    }else{
        pair<int,int> escaque_destino(3,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> d1, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> d1 -> update();
}


void MainWindow::on_d2_clicked()
{
    ui -> d2 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[3][1].pulsado == 0){
        ui -> d2 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[3][1].pulsado = 1;
    }else{
        ui -> d2 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[3][1].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 3;
        escaque_origen.second = 1;
        estado_movimiento = false;
        boton_origen = ui -> d2;
    }else{
        pair<int,int> escaque_destino(3,1);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> d2, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> d2 -> update();
}

void MainWindow::on_d3_clicked()
{
    ui -> d3 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[3][2].pulsado == 0){
        ui -> d3 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[3][2].pulsado = 1;
    }else{
        ui -> d3 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[3][2].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 3;
        escaque_origen.second = 2;
        estado_movimiento = false;
        boton_origen = ui -> d3;
    }else{
        pair<int,int> escaque_destino(3,2);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> d3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> d3 -> update();
}


void MainWindow::on_d4_clicked()
{
    ui -> d4 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[3][3].pulsado == 0){
        ui -> d4 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[3][3].pulsado = 1;
    }else{
        ui -> d4 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[3][3].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 3;
        escaque_origen.second = 3;
        estado_movimiento = false;
        boton_origen = ui -> d4;
    }else{
        pair<int,int> escaque_destino(0,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> d4, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> d4 -> update();
}

void MainWindow::on_d5_clicked()
{
    ui -> d5 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[3][4].pulsado == 0){
        ui -> d5 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[3][4].pulsado = 1;
    }else{
        ui -> d5 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[3][4].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 3;
        escaque_origen.second = 4;
        estado_movimiento = false;
        boton_origen = ui -> d5;
    }else{
        pair<int,int> escaque_destino(3,4);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> d5, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> d5 -> update();
}


void MainWindow::on_d6_clicked()
{
    ui -> d6 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[3][5].pulsado == 0){
        ui -> d6 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[3][5].pulsado = 1;
    }else{
        ui -> d6 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[3][5].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 3;
        escaque_origen.second = 5;
        estado_movimiento = false;
        boton_origen = ui -> d6;
    }else{
        pair<int,int> escaque_destino(3,5);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> d6, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> d6 -> update();
}

void MainWindow::on_d7_clicked()
{
    ui -> d7 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[3][6].pulsado == 0){
        ui -> d7 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[3][6].pulsado = 1;
    }else{
        ui -> d7 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[3][6].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 3;
        escaque_origen.second = 6;
        estado_movimiento = false;
        boton_origen = ui -> d7;
    }else{
        pair<int,int> escaque_destino(3,6);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> d7, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> d7 -> update();
}


void MainWindow::on_d8_clicked()
{
    ui -> d8 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[3][7].pulsado == 0){
        ui -> d8 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[3][7].pulsado = 1;
    }else{
        ui -> d8 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[3][7].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 3;
        escaque_origen.second = 7;
        estado_movimiento = false;
        boton_origen = ui -> d7;
    }else{
        pair<int,int> escaque_destino(3,7);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> d8, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> d8 -> update();
}

void MainWindow::on_e1_clicked()
{
    ui -> e1 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[4][0].pulsado == 0){
        ui -> e1 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[4][0].pulsado = 1;
    }else{
        ui -> e1 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[4][0].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 4;
        escaque_origen.second = 0;
        estado_movimiento = false;
        boton_origen = ui -> e1;
    }else{
        pair<int,int> escaque_destino(4,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> e1, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> e1 -> update();
}


void MainWindow::on_e2_clicked()
{
    ui -> e2 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[4][1].pulsado == 0){
        ui -> e2 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[4][1].pulsado = 1;
    }else{
        ui -> e2 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[4][1].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 4;
        escaque_origen.second = 1;
        estado_movimiento = false;
        boton_origen = ui -> e2;
    }else{
        pair<int,int> escaque_destino(4,1);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> e2, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> e2 -> update();
}

void MainWindow::on_e3_clicked()
{
    ui -> e3 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[4][2].pulsado == 0){
        ui -> e3 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[4][2].pulsado = 1;
    }else{
        ui -> e3 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[4][2].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 4;
        escaque_origen.second = 2;
        estado_movimiento = false;
        boton_origen = ui -> e3;
    }else{
        pair<int,int> escaque_destino(4,2);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> e3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> e3 -> update();
}


void MainWindow::on_e4_clicked()
{
    ui -> e4 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[4][3].pulsado == 0){
        ui -> e4 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[4][3].pulsado = 1;
    }else{
        ui -> e4 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[4][3].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 4;
        escaque_origen.second = 3;
        estado_movimiento = false;
        boton_origen = ui -> e4;
    }else{
        pair<int,int> escaque_destino(4,3);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> e4, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> e4 -> update();
}

void MainWindow::on_e5_clicked()
{
    ui -> e5 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[4][4].pulsado == 0){
        ui -> e5 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[4][4].pulsado = 1;
    }else{
        ui -> e5 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[4][4].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 4;
        escaque_origen.second = 4;
        estado_movimiento = false;
        boton_origen = ui -> e5;
    }else{
        pair<int,int> escaque_destino(4,4);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> e5, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> e5 -> update();
}


void MainWindow::on_e6_clicked()
{
    ui -> e6 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[4][5].pulsado == 0){
        ui -> e6 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[4][5].pulsado = 1;
    }else{
        ui -> e6 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[4][5].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 4;
        escaque_origen.second = 5;
        estado_movimiento = false;
        boton_origen = ui -> e6;
    }else{
        pair<int,int> escaque_destino(4,5);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> e6, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> e6 -> update();
}

void MainWindow::on_e7_clicked()
{
    ui -> e7 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[4][6].pulsado == 0){
        ui -> e7 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[4][6].pulsado = 1;
    }else{
        ui -> e7 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[4][6].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 4;
        escaque_origen.second = 6;
        estado_movimiento = false;
        boton_origen = ui -> e7;
    }else{
        pair<int,int> escaque_destino(4,6);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> e7, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> e7 -> update();
}


void MainWindow::on_e8_clicked()
{
    ui -> e8 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[4][7].pulsado == 0){
        ui -> e8 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[4][7].pulsado = 1;
    }else{
        ui -> e8 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[4][7].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 4;
        escaque_origen.second = 7;
        estado_movimiento = false;
        boton_origen = ui -> e8;
    }else{
        pair<int,int> escaque_destino(4,7);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> e8, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> e8 -> update();
}

void MainWindow::on_f1_clicked()
{
    ui -> f1 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[5][0].pulsado == 0){
        ui -> f1 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[5][0].pulsado = 1;
    }else{
        ui -> f1 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[5][0].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 5;
        escaque_origen.second = 0;
        estado_movimiento = false;
        boton_origen = ui -> f1;
    }else{
        pair<int,int> escaque_destino(5,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> f1, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> f1 -> update();
}


void MainWindow::on_f2_clicked()
{
    ui -> f2 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[5][1].pulsado == 0){
        ui -> f2 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[5][1].pulsado = 1;
    }else{
        ui -> f2 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[5][1].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 5;
        escaque_origen.second = 1;
        estado_movimiento = false;
        boton_origen = ui -> f2;
    }else{
        pair<int,int> escaque_destino(5,1);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> f2, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }


    ui -> f2 -> update();
}

void MainWindow::on_f3_clicked()
{
    ui -> f3 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[5][2].pulsado == 0){
        ui -> f3 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[5][2].pulsado = 1;
    }else{
        ui -> f3 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[5][2].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 5;
        escaque_origen.second = 2;
        estado_movimiento = false;
        boton_origen = ui -> f3;
    }else{
        pair<int,int> escaque_destino(5,2);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> f3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> f3 -> update();
}


void MainWindow::on_f4_clicked()
{
    ui -> f4 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[5][3].pulsado == 0){
        ui -> f4 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[5][3].pulsado = 1;
    }else{
        ui -> f4 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[5][3].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 5;
        escaque_origen.second = 3;
        estado_movimiento = false;
        boton_origen = ui -> f4;
    }else{
        pair<int,int> escaque_destino(5,3);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> f4, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> f4 -> update();
}

void MainWindow::on_f5_clicked()
{
    ui -> f5 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[5][4].pulsado == 0){
        ui -> f5 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[5][4].pulsado = 1;
    }else{
        ui -> f5 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[5][4].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 5;
        escaque_origen.second = 4;
        estado_movimiento = false;
        boton_origen = ui -> f5;
    }else{
        pair<int,int> escaque_destino(5,4);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> f5, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> f5 -> update();
}


void MainWindow::on_f6_clicked()
{
    ui -> f6 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[5][5].pulsado == 0){
        ui -> f6 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[5][5].pulsado = 1;
    }else{
        ui -> f6 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[5][5].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 5;
        escaque_origen.second = 5;
        estado_movimiento = false;
        boton_origen = ui -> f6;
    }else{
        pair<int,int> escaque_destino(5,5);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> f6, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> f6 -> update();
}

void MainWindow::on_f7_clicked()
{
    ui -> f7 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[5][6].pulsado == 0){
        ui -> f7 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[5][6].pulsado = 1;
    }else{
        ui -> f7 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[5][6].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 5;
        escaque_origen.second = 6;
        estado_movimiento = false;
        boton_origen = ui -> f7;
    }else{
        pair<int,int> escaque_destino(5,6);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> f7, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> f7 -> update();
}


void MainWindow::on_f8_clicked()
{
    ui -> f8 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[5][7].pulsado == 0){
        ui -> f8 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[5][7].pulsado = 1;
    }else{
        ui -> f8 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[5][7].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 5;
        escaque_origen.second = 7;
        estado_movimiento = false;
        boton_origen = ui -> f8;
    }else{
        pair<int,int> escaque_destino(5,7);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> f8, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> f8 -> update();
}

void MainWindow::on_g1_clicked()
{
    ui -> g1 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[6][0].pulsado == 0){
        ui -> g1 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[6][0].pulsado = 1;
    }else{
        ui -> g1 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[6][0].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 6;
        escaque_origen.second = 0;
        estado_movimiento = false;
        boton_origen = ui -> g1;
    }else{
        pair<int,int> escaque_destino(6,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> g1, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> g1 -> update();
}


void MainWindow::on_g2_clicked()
{
    ui -> g2 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[6][1].pulsado == 0){
        ui -> g2 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[6][1].pulsado = 1;
    }else{
        ui -> g2 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[6][1].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 6;
        escaque_origen.second = 1;
        estado_movimiento = false;
        boton_origen = ui -> g2;
    }else{
        pair<int,int> escaque_destino(6,1);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> g2, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> g2 -> update();
}

void MainWindow::on_g3_clicked()
{
    ui -> g3 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[6][2].pulsado == 0){
        ui -> g3 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[6][2].pulsado = 1;
    }else{
        ui -> g3 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[6][2].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 6;
        escaque_origen.second = 2;
        estado_movimiento = false;
        boton_origen = ui -> g3;
    }else{
        pair<int,int> escaque_destino(6,2);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> g3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> g3 -> update();
}


void MainWindow::on_g4_clicked()
{
    ui -> g4 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[6][3].pulsado == 0){
        ui -> g4 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[6][3].pulsado = 1;
    }else{
        ui -> g4 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[6][3].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 6;
        escaque_origen.second = 3;
        estado_movimiento = false;
        boton_origen = ui -> g4;
    }else{
        pair<int,int> escaque_destino(6,3);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> g4, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> g4 -> update();
}

void MainWindow::on_g5_clicked()
{
    ui -> g5 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[6][4].pulsado == 0){
        ui -> g5 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[6][4].pulsado = 1;
    }else{
        ui -> g5 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[6][4].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 6;
        escaque_origen.second = 4;
        estado_movimiento = false;
        boton_origen = ui -> g5;
    }else{
        pair<int,int> escaque_destino(6,4);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> g5, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> g5 -> update();
}


void MainWindow::on_g6_clicked()
{
    ui -> g6 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[6][5].pulsado == 0){
        ui -> g6 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[6][5].pulsado = 1;
    }else{
        ui -> g6 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[6][5].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 6;
        escaque_origen.second = 5;
        estado_movimiento = false;
        boton_origen = ui -> g6;
    }else{
        pair<int,int> escaque_destino(6,5);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> g6, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> g6 -> update();
}

void MainWindow::on_g7_clicked()
{
    ui -> g7 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[6][6].pulsado == 0){
        ui -> g7 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[6][6].pulsado = 1;
    }else{
        ui -> g7 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[6][6].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 6;
        escaque_origen.second = 6;
        estado_movimiento = false;
        boton_origen = ui -> g7;
    }else{
        pair<int,int> escaque_destino(6,6);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> g7, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> g7 -> update();
}


void MainWindow::on_g8_clicked()
{
    ui -> g8 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[6][7].pulsado == 0){
        ui -> g8 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[6][7].pulsado = 1;
    }else{
        ui -> g8 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[6][7].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 6;
        escaque_origen.second = 7;
        estado_movimiento = false;
        boton_origen = ui -> g8;
    }else{
        pair<int,int> escaque_destino(6,7);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> g8, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> g8 -> update();
}

void MainWindow::on_h1_clicked()
{
    ui -> h1 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[7][0].pulsado == 0){
        ui -> h1 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[7][0].pulsado = 1;
    }else{
        ui -> h1 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[7][0].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 7;
        escaque_origen.second = 0;
        estado_movimiento = false;
        boton_origen = ui -> h1;
    }else{
        pair<int,int> escaque_destino(7,0);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> h1, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> h1 -> update();
}


void MainWindow::on_h2_clicked()
{
    ui -> h2 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[7][1].pulsado == 0){
        ui -> h2 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[7][1].pulsado = 1;
    }else{
        ui -> h2 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[7][1].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 7;
        escaque_origen.second = 1;
        estado_movimiento = false;
        boton_origen = ui -> h2;
    }else{
        pair<int,int> escaque_destino(7,1);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> h2, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> h2 -> update();
}

void MainWindow::on_h3_clicked()
{
    ui -> h3 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[7][2].pulsado == 0){
        ui -> h3 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[7][2].pulsado = 1;
    }else{
        ui -> h3 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[7][2].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 7;
        escaque_origen.second = 2;
        estado_movimiento = false;
        boton_origen = ui -> h3;
    }else{
        pair<int,int> escaque_destino(7,2);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> h3, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> h3 -> update();
}


void MainWindow::on_h4_clicked()
{
    ui -> h4 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[7][3].pulsado == 0){
        ui -> h4 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[7][3].pulsado = 1;
    }else{
        ui -> h4 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[7][3].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 7;
        escaque_origen.second = 3;
        estado_movimiento = false;
        boton_origen = ui -> h4;
    }else{
        pair<int,int> escaque_destino(7,3);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> h4, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> h4 -> update();
}

void MainWindow::on_h5_clicked()
{
    ui -> h5 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[7][4].pulsado == 0){
        ui -> h5 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[7][4].pulsado = 1;
    }else{
        ui -> h5 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[7][4].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 7;
        escaque_origen.second = 4;
        estado_movimiento = false;
        boton_origen = ui -> h5;
    }else{
        pair<int,int> escaque_destino(7,4);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> h5, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> h5 -> update();
}


void MainWindow::on_h6_clicked()
{
    ui -> h6 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[7][5].pulsado == 0){
        ui -> h6 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[7][5].pulsado = 1;
    }else{
        ui -> h6 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[7][5].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 7;
        escaque_origen.second = 5;
        estado_movimiento = false;
        boton_origen = ui -> h6;
    }else{
        pair<int,int> escaque_destino(7,5);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> h6, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> h6 -> update();
}

void MainWindow::on_h7_clicked()
{
    ui -> h7 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[7][6].pulsado == 0){
        ui -> h7 -> setPalette(MainWindow::cian);
        MainWindow::echiquier.mat_escaque[7][6].pulsado = 1;
    }else{
        ui -> h7 -> setPalette(MainWindow::blanco);
        MainWindow::echiquier.mat_escaque[7][6].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 7;
        escaque_origen.second = 6;
        estado_movimiento = false;
        boton_origen = ui -> h7;
    }else{
        pair<int,int> escaque_destino(7,6);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> h7, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> h7 -> update();
}


void MainWindow::on_h8_clicked()
{
    ui -> h8 -> setAutoFillBackground(true);
    if (MainWindow::echiquier.mat_escaque[7][7].pulsado == 0){
        ui -> h8 -> setPalette(MainWindow::azul);
        MainWindow::echiquier.mat_escaque[7][7].pulsado = 1;
    }else{
        ui -> h8 -> setPalette(MainWindow::gris);
        MainWindow::echiquier.mat_escaque[7][7].pulsado = 0;
    }

    if (estado_movimiento){
        escaque_origen.first = 7;
        escaque_origen.second = 7;
        estado_movimiento = false;
        boton_origen = ui -> h8;
    }else{
        pair<int,int> escaque_destino(7,7);
        boton_origen->setIcon(iconos[0]);
        estado_movimiento = mueve_icono(&echiquier, ui -> h8, escaque_origen,escaque_destino,estado_movimiento,iconos);
    }

    ui -> h8 -> update();
}
