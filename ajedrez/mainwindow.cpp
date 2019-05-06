#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "funciones.h"
#include "QDebug"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vector < vector < int >> pos_inicial(8, vector <int>(8,2));
    for (unsigned long i = 0; i < 8; i++){
        for (unsigned long j = 0; j < 8; j++){
            if (i < 2) pos_inicial[j][i] = 0;
            else if (i > 5) pos_inicial[j][i] = 1;
        }
    }
    vector < vector < bool >> reyes(8, vector <bool>(8, false));
    reyes[4][0] = true;
    reyes[4][7] = true;

    gris.setColor(QPalette::Button,QColor(Qt::gray));
    blanco.setColor(QPalette::Button, QColor(Qt::white));
    azul.setColor(QPalette::Button,QColor(Qt::darkCyan));
    cian.setColor(QPalette::Button, QColor(Qt::cyan));

    /*vector < QIcon > iconos(13);
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
    iconos[12] = QIcon("pieces/merida_new/bk.svg");*/

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
    //echiquier.imprimir_tablero();
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

        // Vectores de almacenado de las piezas
        peon pw1(0, 1, 0);  v_peon.push_back(pw1);
        peon pw2(1, 1, 0);  v_peon.push_back(pw2);
        peon pw3(2, 1, 0);  v_peon.push_back(pw3);
        peon pw4(3, 1, 0);  v_peon.push_back(pw4);
        peon pw5(4, 1, 0);  v_peon.push_back(pw5);
        peon pw6(5, 1, 0);  v_peon.push_back(pw6);
        peon pw7(6, 1, 0);  v_peon.push_back(pw7);
        peon pw8(7, 1, 0);  v_peon.push_back(pw8);
        peon pk1(0, 6, 1);  v_peon.push_back(pk1);
        peon pk2(1, 6, 1);  v_peon.push_back(pk2);
        peon pk3(2, 6, 1);  v_peon.push_back(pk3);
        peon pk4(3, 6, 1);  v_peon.push_back(pk4);
        peon pk5(4, 6, 1);  v_peon.push_back(pk5);
        peon pk6(5, 6, 1);  v_peon.push_back(pk6);
        peon pk7(6, 6, 1);  v_peon.push_back(pk7);
        peon pk8(7, 6, 1);  v_peon.push_back(pk8);

        caballo cw1(1, 0, 0);   v_caballo.push_back(cw1);
        caballo cw2(6, 0, 0);   v_caballo.push_back(cw2);
        caballo ck1(1, 7, 1);   v_caballo.push_back(ck1);
        caballo ck2(6, 7, 1);   v_caballo.push_back(ck2);

        alfil aw1(2, 0, 0);   v_alfil.push_back(aw1);
        alfil aw2(5, 0, 0);   v_alfil.push_back(aw2);
        alfil ak1(2, 7, 1);   v_alfil.push_back(ak1);
        alfil ak2(5, 7, 1);   v_alfil.push_back(ak2);

        torre tw1(1, 0, 0);   v_torre.push_back(tw1);
        torre tw2(6, 0, 0);   v_torre.push_back(tw2);
        torre tk1(1, 7, 1);   v_torre.push_back(tk1);
        torre tk2(6, 7, 1);   v_torre.push_back(tk2);

        dama dw1(3, 0, 0);   v_dama.push_back(dw1);
        dama dk1(3, 0, 1);   v_dama.push_back(dk1);

        rey rw1(4, 0, 0);   v_rey.push_back(rw1);
        rey rk1(4, 0, 1);   v_rey.push_back(rk1);


        // Prueba para connect
        connect(ui->a1,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->a2,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->a3,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->a4,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->a5,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->a6,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->a7,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->a8,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->b1,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->b2,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->b3,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->b4,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->b5,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->b6,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->b7,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->b8,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->c1,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->c2,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->c3,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->c4,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->c5,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->c6,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->c7,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->c8,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->d1,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->d2,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->d3,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->d4,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->d5,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->d6,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->d7,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->d8,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->e1,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->e2,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->e3,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->e4,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->e5,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->e6,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->e7,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->e8,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->f1,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->f2,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->f3,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->f4,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->f5,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->f6,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->f7,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->f8,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->g1,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->g2,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->g3,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->g4,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->g5,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->g6,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->g7,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->g8,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->h1,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->h2,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->h3,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->h4,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->h5,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->h6,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->h7,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
        connect(ui->h8,SIGNAL(clicked()),this,SLOT(boton_pulsado()));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Prueba para el connect
void MainWindow::boton_pulsado(){
    QPushButton *boton = (QPushButton*)sender();
    QString name = boton->objectName();
    limpia_tablero();
    int pos = 0;
    if (name == "a1"){
        pos = 1;
        ui -> a1 -> setAutoFillBackground(true);
        ui -> a1 -> setPalette(azul);
    }
    else if (name == "a2"){
        pos = 2;
        ui -> a2 -> setAutoFillBackground(true);
        ui -> a2 -> setPalette(cian);
    }
    else if (name == "a3"){
        pos = 3;
        ui -> a3 -> setAutoFillBackground(true);
        ui -> a3 -> setPalette(azul);
    }
    else if (name == "a4"){
        pos = 4;
        ui -> a4 -> setAutoFillBackground(true);
        ui -> a4 -> setPalette(cian);
    }
    else if (name == "a5"){
        pos = 5;
        ui -> a5 -> setAutoFillBackground(true);
        ui -> a5 -> setPalette(azul);
    }
    else if (name == "a6"){
        pos = 6;
        ui -> a6 -> setAutoFillBackground(true);
        ui -> a6 -> setPalette(cian);
    }
    else if (name == "a7"){
        pos = 7;
        ui -> a7 -> setAutoFillBackground(true);
        ui -> a7 -> setPalette(azul);
    }
    else if (name == "a8"){
        pos = 8;
        ui -> a8 -> setAutoFillBackground(true);
        ui -> a8 -> setPalette(cian);
    }
    else if (name == "b1"){
        pos = 9;
        ui -> b1 -> setAutoFillBackground(true);
        ui -> b1 -> setPalette(cian);
    }
    else if (name == "b2"){
        pos = 10;
        ui -> b2 -> setAutoFillBackground(true);
        ui -> b2 -> setPalette(azul);
    }
    else if (name == "b3"){
        pos = 11;
        ui -> b3 -> setAutoFillBackground(true);
        ui -> b3 -> setPalette(cian);
    }
    else if (name == "b4"){
        pos = 12;
        ui -> b4 -> setAutoFillBackground(true);
        ui -> b4 -> setPalette(azul);
    }
    else if (name == "b5"){
        pos = 13;
        ui -> b5 -> setAutoFillBackground(true);
        ui -> b5 -> setPalette(cian);
    }
    else if (name == "b6"){
        pos = 14;
        ui -> b6 -> setAutoFillBackground(true);
        ui -> b6 -> setPalette(azul);
    }
    else if (name == "b7"){
        pos = 15;
        ui -> b7 -> setAutoFillBackground(true);
        ui -> b7 -> setPalette(cian);
    }
    else if (name == "b8"){
        pos = 16;
        ui -> b8 -> setAutoFillBackground(true);
        ui -> b8 -> setPalette(azul);
    }
    else if (name == "c1"){
        pos = 17;
        ui -> c1 -> setAutoFillBackground(true);
        ui -> c1 -> setPalette(azul);
    }
    else if (name == "c2"){
        pos = 18;
        ui -> c2 -> setAutoFillBackground(true);
        ui -> c2 -> setPalette(cian);
    }
    else if (name == "c3"){
        pos = 19;
        ui -> c3 -> setAutoFillBackground(true);
        ui -> c3 -> setPalette(azul);
    }
    else if (name == "c4"){
        pos = 20;
        ui -> c4 -> setAutoFillBackground(true);
        ui -> c4 -> setPalette(cian);
    }
    else if (name == "c5"){
        pos = 21;
        ui -> c5 -> setAutoFillBackground(true);
        ui -> c5 -> setPalette(azul);
    }
    else if (name == "c6"){
        pos = 22;
        ui -> c6 -> setAutoFillBackground(true);
        ui -> c6 -> setPalette(cian);
    }
    else if (name == "c7"){
        pos = 23;
        ui -> c7 -> setAutoFillBackground(true);
        ui -> c7 -> setPalette(azul);
    }
    else if (name == "c8"){
        pos = 24;
        ui -> c8 -> setAutoFillBackground(true);
        ui -> c8 -> setPalette(cian);
    }
    else if (name == "d1"){
        pos = 25;
        ui -> d1 -> setAutoFillBackground(true);
        ui -> d1 -> setPalette(cian);
    }
    else if (name == "d2"){
        pos = 26;
        ui -> d2 -> setAutoFillBackground(true);
        ui -> d2 -> setPalette(azul);
    }
    else if (name == "d3"){
        pos = 27;
        ui -> d3 -> setAutoFillBackground(true);
        ui -> d3 -> setPalette(cian);
    }
    else if (name == "d4"){
        pos = 28;
        ui -> d4 -> setAutoFillBackground(true);
        ui -> d4 -> setPalette(azul);
    }
    else if (name == "d5"){
        pos = 29;
        ui -> d5 -> setAutoFillBackground(true);
        ui -> d5 -> setPalette(cian);
    }
    else if (name == "d6"){
        pos = 30;
        ui -> d6 -> setAutoFillBackground(true);
        ui -> d6 -> setPalette(azul);
    }
    else if (name == "d7"){
        pos = 31;
        ui -> d7 -> setAutoFillBackground(true);
        ui -> d7 -> setPalette(cian);
    }
    else if (name == "d8"){
        pos = 32;
        ui -> d8 -> setAutoFillBackground(true);
        ui -> d8 -> setPalette(azul);
    }
    else if (name == "e1"){
        pos = 33;
        ui -> e1 -> setAutoFillBackground(true);
        ui -> e1 -> setPalette(azul);
    }
    else if (name == "e2"){
        pos = 34;
        ui -> e2 -> setAutoFillBackground(true);
        ui -> e2 -> setPalette(cian);
    }
    else if (name == "e3"){
        pos = 35;
        ui -> e3 -> setAutoFillBackground(true);
        ui -> e3 -> setPalette(azul);
    }
    else if (name == "e4"){
        pos = 36;
        ui -> e4 -> setAutoFillBackground(true);
        ui -> e4 -> setPalette(cian);
    }
    else if (name == "e5"){
        pos = 37;
        ui -> e5 -> setAutoFillBackground(true);
        ui -> e5 -> setPalette(azul);
    }
    else if (name == "e6"){
        pos = 38;
        ui -> e6 -> setAutoFillBackground(true);
        ui -> e6 -> setPalette(cian);
    }
    else if (name == "e7"){
        pos = 39;
        ui -> e7 -> setAutoFillBackground(true);
        ui -> e7 -> setPalette(azul);
    }
    else if (name == "e8"){
        pos = 40;
        ui -> e8 -> setAutoFillBackground(true);
        ui -> e8 -> setPalette(cian);
    }
    else if (name == "f1"){
        pos = 41;
        ui -> f1 -> setAutoFillBackground(true);
        ui -> f1 -> setPalette(cian);
    }
    else if (name == "f2"){
        pos = 42;
        ui -> f2 -> setAutoFillBackground(true);
        ui -> f2 -> setPalette(azul);
    }
    else if (name == "f3"){
        pos = 43;
        ui -> f3 -> setAutoFillBackground(true);
        ui -> f3 -> setPalette(cian);
    }
    else if (name == "f4"){
        pos = 44;
        ui -> f4 -> setAutoFillBackground(true);
        ui -> f4 -> setPalette(azul);
    }
    else if (name == "f5"){
        pos = 45;
        ui -> f5 -> setAutoFillBackground(true);
        ui -> f5 -> setPalette(cian);
    }
    else if (name == "f6"){
        pos = 46;
        ui -> f6 -> setAutoFillBackground(true);
        ui -> f6 -> setPalette(azul);
    }
    else if (name == "f7"){
        pos = 47;
        ui -> f7 -> setAutoFillBackground(true);
        ui -> f7 -> setPalette(cian);
    }
    else if (name == "f8"){
        pos = 48;
        ui -> f8 -> setAutoFillBackground(true);
        ui -> f8 -> setPalette(azul);
    }
    else if (name == "g1"){
        pos = 49;
        ui -> g1 -> setAutoFillBackground(true);
        ui -> g1 -> setPalette(azul);
    }
    else if (name == "g2"){
        pos = 50;
        ui -> g2 -> setAutoFillBackground(true);
        ui -> g2 -> setPalette(cian);
    }
    else if (name == "g3"){
        pos = 51;
        ui -> g3 -> setAutoFillBackground(true);
        ui -> g3 -> setPalette(azul);
    }
    else if (name == "g4"){
        pos = 52;
        ui -> g4 -> setAutoFillBackground(true);
        ui -> g4 -> setPalette(cian);
    }
    else if (name == "g5"){
        pos = 53;
        ui -> g5 -> setAutoFillBackground(true);
        ui -> g5 -> setPalette(azul);
    }
    else if (name == "g6"){
        pos = 54;
        ui -> g6 -> setAutoFillBackground(true);
        ui -> g6 -> setPalette(cian);
    }
    else if (name == "g7"){
        pos = 55;
        ui -> g7 -> setAutoFillBackground(true);
        ui -> g7 -> setPalette(azul);
    }
    else if (name == "g8"){
        pos = 56;
        ui -> g8 -> setAutoFillBackground(true);
        ui -> g8 -> setPalette(cian);
    }
    else if (name == "h1"){
        pos = 57;
        ui -> h1 -> setAutoFillBackground(true);
        ui -> h1 -> setPalette(cian);
    }
    else if (name == "h2"){
        pos = 58;
        ui -> h2 -> setAutoFillBackground(true);
        ui -> h2 -> setPalette(azul);
    }
    else if (name == "h3"){
        pos = 59;
        ui -> h3 -> setAutoFillBackground(true);
        ui -> h3 -> setPalette(cian);
    }
    else if (name == "h4"){
        pos = 60;
        ui -> h4 -> setAutoFillBackground(true);
        ui -> h4 -> setPalette(azul);
    }
    else if (name == "h5"){
        pos = 61;
        ui -> h5 -> setAutoFillBackground(true);
        ui -> h5 -> setPalette(cian);
    }
    else if (name == "h6"){
        pos = 62;
        ui -> h6 -> setAutoFillBackground(true);
        ui -> h6 -> setPalette(azul);
    }
    else if (name == "h7"){
        pos = 63;
        ui -> h7 -> setAutoFillBackground(true);
        ui -> h7 -> setPalette(cian);
    }
    else if (name == "h8"){
        pos = 64;
        ui -> h8 -> setAutoFillBackground(true);
        ui -> h8 -> setPalette(azul);
    }

    // Sacar coordenadas a partir del vector
    pair<int,int> coord;
    int n = 0;
    int pos_aux = pos;
    while (n > -1){ // Obtiene coordenadas mediante la posicion
        if(pos_aux > 8){
            pos_aux = pos_aux-8;
            n++;
        }
        else{
            coord.first = n;
            coord.second = pos_aux-1;
            n = -1;
        }
    }

    // Identificar pieza elegida y su mov_set (movs_posibles)
    bool mov_realizado = 0;

    if (flagmov == 0){
        pos_o = pos;
        pos_origen.first = coord.first;
        pos_origen.second = coord.second;
        if (echiquier.mat_escaque[pos_origen.first][pos_origen.second].t_icon != 0){
            for (unsigned int i = 0; i < v_peon.size(); i++){
                if (mov_realizado == 0){
                    if(v_peon[i].pos.first == pos_origen.first && v_peon[i].pos.second == pos_origen.second){
                        v_peon[i].movs(echiquier);
                        movs_pieza = v_peon[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_caballo.size(); i++){
                if (mov_realizado == 0){
                    if(v_caballo[i].pos.first == pos_origen.first && v_caballo[i].pos.second == pos_origen.second){
                        v_caballo[i].movs(echiquier);
                        movs_pieza = v_caballo[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_alfil.size(); i++){
                if (mov_realizado == 0){
                    if(v_alfil[i].pos.first == pos_origen.first && v_alfil[i].pos.second == pos_origen.second){
                        v_alfil[i].movs(echiquier);
                        movs_pieza = v_alfil[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_torre.size(); i++){
                if (mov_realizado == 0){
                    if(v_torre[i].pos.first == pos_origen.first && v_torre[i].pos.second == pos_origen.second){
                        v_torre[i].movs(echiquier);
                        movs_pieza = v_torre[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_dama.size(); i++){
                if (mov_realizado == 0){
                    if(v_dama[i].pos.first == pos_origen.first && v_dama[i].pos.second == pos_origen.second){
                        v_dama[i].movs(echiquier);
                        movs_pieza = v_dama[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_rey.size(); i++){
                if (mov_realizado == 0){
                    if(v_rey[i].pos.first == pos_origen.first && v_rey[i].pos.second == pos_origen.second){
                        v_rey[i].movs(echiquier, v_peon, v_caballo, v_alfil, v_torre, v_rey, v_dama);
                        movs_pieza = v_rey[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            flagmov = 1;
        }
        else limpia_tablero();
    }
    else {
        for (unsigned int k = 0; k < movs_pieza.size(); k++){
            if (movs_pieza[k].first == coord.first && movs_pieza[k].second == coord.second){
                // Cambiar iconos
                int ind = echiquier.mat_escaque[pos_origen.first][pos_origen.second].t_icon;
                QString icono_path = nuevo_icono(ind);
                QIcon icono_o = QIcon(icono_path);
                icono_path = nuevo_icono(0);
                QIcon icono_d = QIcon(icono_path);

                // Cambiar atributo t_icon
                echiquier.mat_escaque[coord.first][coord.second].t_icon = echiquier.mat_escaque[pos_origen.first][pos_origen.second].t_icon;
                echiquier.mat_escaque[pos_origen.first][pos_origen.second].t_icon = 0;

                // Cambiar posicion de la pieza
                mov_realizado = 0;
                for (unsigned int i = 0; i < v_peon.size(); i++){
                    if (mov_realizado == 0){
                        if(v_peon[i].pos.first == pos_origen.first && v_peon[i].pos.second == pos_origen.second){
                            v_peon[i].pos.first = coord.first;
                            v_peon[i].pos.second = coord.second;
                            echiquier.mat_escaque[pos_origen.first][pos_origen.second].ocupado = 2;
                            if (v_peon[i].jugador == 0) echiquier.mat_escaque[coord.first][coord.second].ocupado = 0;
                            else echiquier.mat_escaque[coord.first][coord.second].ocupado = 1;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_caballo.size(); i++){
                    if (mov_realizado == 0){
                        if(v_caballo[i].pos.first == pos_origen.first && v_caballo[i].pos.second == pos_origen.second){
                            v_caballo[i].pos.first = coord.first;
                            v_caballo[i].pos.second = coord.second;
                            echiquier.mat_escaque[pos_origen.first][pos_origen.second].ocupado = 2;
                            if (v_caballo[i].jugador == 0) echiquier.mat_escaque[coord.first][coord.second].ocupado = 0;
                            else echiquier.mat_escaque[coord.first][coord.second].ocupado = 1;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_alfil.size(); i++){
                    if (mov_realizado == 0){
                        if(v_alfil[i].pos.first == pos_origen.first && v_alfil[i].pos.second == pos_origen.second){
                            v_alfil[i].pos.first = coord.first;
                            v_alfil[i].pos.second = coord.second;
                            echiquier.mat_escaque[pos_origen.first][pos_origen.second].ocupado = 2;
                            if (v_alfil[i].jugador == 0) echiquier.mat_escaque[coord.first][coord.second].ocupado = 0;
                            else echiquier.mat_escaque[coord.first][coord.second].ocupado = 1;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_torre.size(); i++){
                    if (mov_realizado == 0){
                        if(v_torre[i].pos.first == pos_origen.first && v_torre[i].pos.second == pos_origen.second){
                            v_torre[i].pos.first = coord.first;
                            v_torre[i].pos.second = coord.second;
                            echiquier.mat_escaque[pos_origen.first][pos_origen.second].ocupado = 2;
                            if (v_torre[i].jugador == 0) echiquier.mat_escaque[coord.first][coord.second].ocupado = 0;
                            else echiquier.mat_escaque[coord.first][coord.second].ocupado = 1;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_dama.size(); i++){
                    if (mov_realizado == 0){
                        if(v_dama[i].pos.first == pos_origen.first && v_dama[i].pos.second == pos_origen.second){
                            v_dama[i].pos.first = coord.first;
                            v_dama[i].pos.second = coord.second;
                            echiquier.mat_escaque[pos_origen.first][pos_origen.second].ocupado = 2;
                            if (v_dama[i].jugador == 0) echiquier.mat_escaque[coord.first][coord.second].ocupado = 0;
                            else echiquier.mat_escaque[coord.first][coord.second].ocupado = 1;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_rey.size(); i++){
                    if (mov_realizado == 0){
                        if(v_rey[i].pos.first == pos_origen.first && v_rey[i].pos.second == pos_origen.second){
                            v_rey[i].pos.first = coord.first;
                            v_rey[i].pos.second = coord.second;
                            echiquier.mat_escaque[pos_origen.first][pos_origen.second].ocupado = 2;
                            if (v_rey[i].jugador == 0) echiquier.mat_escaque[coord.first][coord.second].ocupado = 0;
                            else echiquier.mat_escaque[coord.first][coord.second].ocupado = 1;
                            mov_realizado = 1;
                        }
                    }
                }

                // Reasignacion de iconos
                if (pos_o == 1) ui -> a1 -> setIcon(icono_d);
                else if (pos_o == 2) ui -> a2 -> setIcon(icono_d);
                else if (pos_o == 3) ui -> a3 -> setIcon(icono_d);
                else if (pos_o == 4) ui -> a4 -> setIcon(icono_d);
                else if (pos_o == 5) ui -> a5 -> setIcon(icono_d);
                else if (pos_o == 6) ui -> a6 -> setIcon(icono_d);
                else if (pos_o == 7) ui -> a7 -> setIcon(icono_d);
                else if (pos_o == 8) ui -> a8 -> setIcon(icono_d);
                else if (pos_o == 9) ui -> b1 -> setIcon(icono_d);
                else if (pos_o == 10) ui -> b2 -> setIcon(icono_d);
                else if (pos_o == 11) ui -> b3 -> setIcon(icono_d);
                else if (pos_o == 12) ui -> b4 -> setIcon(icono_d);
                else if (pos_o == 13) ui -> b5 -> setIcon(icono_d);
                else if (pos_o == 14) ui -> b6 -> setIcon(icono_d);
                else if (pos_o == 15) ui -> b7 -> setIcon(icono_d);
                else if (pos_o == 16) ui -> b8 -> setIcon(icono_d);
                else if (pos_o == 17) ui -> c1 -> setIcon(icono_d);
                else if (pos_o == 18) ui -> c2 -> setIcon(icono_d);
                else if (pos_o == 19) ui -> c3 -> setIcon(icono_d);
                else if (pos_o == 20) ui -> c4 -> setIcon(icono_d);
                else if (pos_o == 21) ui -> c5 -> setIcon(icono_d);
                else if (pos_o == 22) ui -> c6 -> setIcon(icono_d);
                else if (pos_o == 23) ui -> c7 -> setIcon(icono_d);
                else if (pos_o == 24) ui -> c8 -> setIcon(icono_d);
                else if (pos_o == 25) ui -> d1 -> setIcon(icono_d);
                else if (pos_o == 26) ui -> d2 -> setIcon(icono_d);
                else if (pos_o == 27) ui -> d3 -> setIcon(icono_d);
                else if (pos_o == 28) ui -> d4 -> setIcon(icono_d);
                else if (pos_o == 29) ui -> d5 -> setIcon(icono_d);
                else if (pos_o == 30) ui -> d6 -> setIcon(icono_d);
                else if (pos_o == 31) ui -> d7 -> setIcon(icono_d);
                else if (pos_o == 32) ui -> d8 -> setIcon(icono_d);
                else if (pos_o == 33) ui -> e1 -> setIcon(icono_d);
                else if (pos_o == 34) ui -> e2 -> setIcon(icono_d);
                else if (pos_o == 35) ui -> e3 -> setIcon(icono_d);
                else if (pos_o == 36) ui -> e4 -> setIcon(icono_d);
                else if (pos_o == 37) ui -> e5 -> setIcon(icono_d);
                else if (pos_o == 38) ui -> e6 -> setIcon(icono_d);
                else if (pos_o == 39) ui -> e7 -> setIcon(icono_d);
                else if (pos_o == 40) ui -> e8 -> setIcon(icono_d);
                else if (pos_o == 41) ui -> f1 -> setIcon(icono_d);
                else if (pos_o == 42) ui -> f2 -> setIcon(icono_d);
                else if (pos_o == 43) ui -> f3 -> setIcon(icono_d);
                else if (pos_o == 44) ui -> f4 -> setIcon(icono_d);
                else if (pos_o == 45) ui -> f5 -> setIcon(icono_d);
                else if (pos_o == 46) ui -> f6 -> setIcon(icono_d);
                else if (pos_o == 47) ui -> f7 -> setIcon(icono_d);
                else if (pos_o == 48) ui -> f8 -> setIcon(icono_d);
                else if (pos_o == 49) ui -> g1 -> setIcon(icono_d);
                else if (pos_o == 50) ui -> g2 -> setIcon(icono_d);
                else if (pos_o == 51) ui -> g3 -> setIcon(icono_d);
                else if (pos_o == 52) ui -> g4 -> setIcon(icono_d);
                else if (pos_o == 53) ui -> g5 -> setIcon(icono_d);
                else if (pos_o == 54) ui -> g6 -> setIcon(icono_d);
                else if (pos_o == 55) ui -> g7 -> setIcon(icono_d);
                else if (pos_o == 56) ui -> g8 -> setIcon(icono_d);
                else if (pos_o == 57) ui -> h1 -> setIcon(icono_d);
                else if (pos_o == 58) ui -> h2 -> setIcon(icono_d);
                else if (pos_o == 59) ui -> h3 -> setIcon(icono_d);
                else if (pos_o == 60) ui -> h4 -> setIcon(icono_d);
                else if (pos_o == 61) ui -> h5 -> setIcon(icono_d);
                else if (pos_o == 62) ui -> h6 -> setIcon(icono_d);
                else if (pos_o == 63) ui -> h7 -> setIcon(icono_d);
                else if (pos_o == 64) ui -> h8 -> setIcon(icono_d);
                //---
                if (pos == 1) ui -> a1 -> setIcon(icono_o);
                else if (pos == 2) ui -> a2 -> setIcon(icono_o);
                else if (pos == 3) ui -> a3 -> setIcon(icono_o);
                else if (pos == 4) ui -> a4 -> setIcon(icono_o);
                else if (pos == 5) ui -> a5 -> setIcon(icono_o);
                else if (pos == 6) ui -> a6 -> setIcon(icono_o);
                else if (pos == 7) ui -> a7 -> setIcon(icono_o);
                else if (pos == 8) ui -> a8 -> setIcon(icono_o);
                else if (pos == 9) ui -> b1 -> setIcon(icono_o);
                else if (pos == 10) ui -> b2 -> setIcon(icono_o);
                else if (pos == 11) ui -> b3 -> setIcon(icono_o);
                else if (pos == 12) ui -> b4 -> setIcon(icono_o);
                else if (pos == 13) ui -> b5 -> setIcon(icono_o);
                else if (pos == 14) ui -> b6 -> setIcon(icono_o);
                else if (pos == 15) ui -> b7 -> setIcon(icono_o);
                else if (pos == 16) ui -> b8 -> setIcon(icono_o);
                else if (pos == 17) ui -> c1 -> setIcon(icono_o);
                else if (pos == 18) ui -> c2 -> setIcon(icono_o);
                else if (pos == 19) ui -> c3 -> setIcon(icono_o);
                else if (pos == 20) ui -> c4 -> setIcon(icono_o);
                else if (pos == 21) ui -> c5 -> setIcon(icono_o);
                else if (pos == 22) ui -> c6 -> setIcon(icono_o);
                else if (pos == 23) ui -> c7 -> setIcon(icono_o);
                else if (pos == 24) ui -> c8 -> setIcon(icono_o);
                else if (pos == 25) ui -> d1 -> setIcon(icono_o);
                else if (pos == 26) ui -> d2 -> setIcon(icono_o);
                else if (pos == 27) ui -> d3 -> setIcon(icono_o);
                else if (pos == 28) ui -> d4 -> setIcon(icono_o);
                else if (pos == 29) ui -> d5 -> setIcon(icono_o);
                else if (pos == 30) ui -> d6 -> setIcon(icono_o);
                else if (pos == 31) ui -> d7 -> setIcon(icono_o);
                else if (pos == 32) ui -> d8 -> setIcon(icono_o);
                else if (pos == 33) ui -> e1 -> setIcon(icono_o);
                else if (pos == 34) ui -> e2 -> setIcon(icono_o);
                else if (pos == 35) ui -> e3 -> setIcon(icono_o);
                else if (pos == 36) ui -> e4 -> setIcon(icono_o);
                else if (pos == 37) ui -> e5 -> setIcon(icono_o);
                else if (pos == 38) ui -> e6 -> setIcon(icono_o);
                else if (pos == 39) ui -> e7 -> setIcon(icono_o);
                else if (pos == 40) ui -> e8 -> setIcon(icono_o);
                else if (pos == 41) ui -> f1 -> setIcon(icono_o);
                else if (pos == 42) ui -> f2 -> setIcon(icono_o);
                else if (pos == 43) ui -> f3 -> setIcon(icono_o);
                else if (pos == 44) ui -> f4 -> setIcon(icono_o);
                else if (pos == 45) ui -> f5 -> setIcon(icono_o);
                else if (pos == 46) ui -> f6 -> setIcon(icono_o);
                else if (pos == 47) ui -> f7 -> setIcon(icono_o);
                else if (pos == 48) ui -> f8 -> setIcon(icono_o);
                else if (pos == 49) ui -> g1 -> setIcon(icono_o);
                else if (pos == 50) ui -> g2 -> setIcon(icono_o);
                else if (pos == 51) ui -> g3 -> setIcon(icono_o);
                else if (pos == 52) ui -> g4 -> setIcon(icono_o);
                else if (pos == 53) ui -> g5 -> setIcon(icono_o);
                else if (pos == 54) ui -> g6 -> setIcon(icono_o);
                else if (pos == 55) ui -> g7 -> setIcon(icono_o);
                else if (pos == 56) ui -> g8 -> setIcon(icono_o);
                else if (pos == 57) ui -> h1 -> setIcon(icono_o);
                else if (pos == 58) ui -> h2 -> setIcon(icono_o);
                else if (pos == 59) ui -> h3 -> setIcon(icono_o);
                else if (pos == 60) ui -> h4 -> setIcon(icono_o);
                else if (pos == 61) ui -> h5 -> setIcon(icono_o);
                else if (pos == 62) ui -> h6 -> setIcon(icono_o);
                else if (pos == 63) ui -> h7 -> setIcon(icono_o);
                else if (pos == 64) ui -> h8 -> setIcon(icono_o);
            }
        }

        // Cambiar iconos
        /*int ind = echiquier.mat_escaque[pos_origen.first][pos_origen.second].t_icon;
        QString icono_path = nuevo_icono(ind);
        QIcon icono_o = QIcon(icono_path);
        icono_path = nuevo_icono(0);
        QIcon icono_d = QIcon(icono_path);

        // Cambiar atributo t_icon
        echiquier.mat_escaque[coord.first][coord.second].t_icon = echiquier.mat_escaque[pos_origen.first][pos_origen.second].t_icon;
        echiquier.mat_escaque[pos_origen.first][pos_origen.second].t_icon = 0;

        // Cambiar posicion de la pieza
        mov_realizado = 0;
        for (unsigned int i = 0; i < v_peon.size(); i++){
            if (mov_realizado == 0){
                if(v_peon[i].pos.first == pos_origen.first && v_peon[i].pos.second == pos_origen.second){
                    v_peon[i].pos.first = coord.first;
                    v_peon[i].pos.second = coord.second;
                    mov_realizado = 1;
                }
            }
        }
        for (unsigned int i = 0; i < v_caballo.size(); i++){
            if (mov_realizado == 0){
                if(v_caballo[i].pos.first == pos_origen.first && v_caballo[i].pos.second == pos_origen.second){
                    v_caballo[i].pos.first = coord.first;
                    v_caballo[i].pos.second = coord.second;
                    mov_realizado = 1;
                }
            }
        }
        for (unsigned int i = 0; i < v_alfil.size(); i++){
            if (mov_realizado == 0){
                if(v_alfil[i].pos.first == pos_origen.first && v_alfil[i].pos.second == pos_origen.second){
                    v_alfil[i].pos.first = coord.first;
                    v_alfil[i].pos.second = coord.second;
                    mov_realizado = 1;
                }
            }
        }
        for (unsigned int i = 0; i < v_torre.size(); i++){
            if (mov_realizado == 0){
                if(v_torre[i].pos.first == pos_origen.first && v_torre[i].pos.second == pos_origen.second){
                    v_torre[i].pos.first = coord.first;
                    v_torre[i].pos.second = coord.second;
                    mov_realizado = 1;
                }
            }
        }
        for (unsigned int i = 0; i < v_dama.size(); i++){
            if (mov_realizado == 0){
                if(v_dama[i].pos.first == pos_origen.first && v_dama[i].pos.second == pos_origen.second){
                    v_dama[i].pos.first = coord.first;
                    v_dama[i].pos.second = coord.second;
                    mov_realizado = 1;
                }
            }
        }
        for (unsigned int i = 0; i < v_rey.size(); i++){
            if (mov_realizado == 0){
                if(v_rey[i].pos.first == pos_origen.first && v_rey[i].pos.second == pos_origen.second){
                    v_rey[i].pos.first = coord.first;
                    v_rey[i].pos.second = coord.second;
                    mov_realizado = 1;
                }
            }
        }

        // Reasignacion de iconos
        if (pos_o == 1) ui -> a1 -> setIcon(icono_d);
        else if (pos_o == 2) ui -> a2 -> setIcon(icono_d);
        else if (pos_o == 3) ui -> a3 -> setIcon(icono_d);
        else if (pos_o == 4) ui -> a4 -> setIcon(icono_d);
        else if (pos_o == 5) ui -> a5 -> setIcon(icono_d);
        else if (pos_o == 6) ui -> a6 -> setIcon(icono_d);
        else if (pos_o == 7) ui -> a7 -> setIcon(icono_d);
        else if (pos_o == 8) ui -> a8 -> setIcon(icono_d);
        else if (pos_o == 9) ui -> b1 -> setIcon(icono_d);
        else if (pos_o == 10) ui -> b2 -> setIcon(icono_d);
        else if (pos_o == 11) ui -> b3 -> setIcon(icono_d);
        else if (pos_o == 12) ui -> b4 -> setIcon(icono_d);
        else if (pos_o == 13) ui -> b5 -> setIcon(icono_d);
        else if (pos_o == 14) ui -> b6 -> setIcon(icono_d);
        else if (pos_o == 15) ui -> b7 -> setIcon(icono_d);
        else if (pos_o == 16) ui -> b8 -> setIcon(icono_d);
        else if (pos_o == 17) ui -> c1 -> setIcon(icono_d);
        else if (pos_o == 18) ui -> c2 -> setIcon(icono_d);
        else if (pos_o == 19) ui -> c3 -> setIcon(icono_d);
        else if (pos_o == 20) ui -> c4 -> setIcon(icono_d);
        else if (pos_o == 21) ui -> c5 -> setIcon(icono_d);
        else if (pos_o == 22) ui -> c6 -> setIcon(icono_d);
        else if (pos_o == 23) ui -> c7 -> setIcon(icono_d);
        else if (pos_o == 24) ui -> c8 -> setIcon(icono_d);
        else if (pos_o == 25) ui -> d1 -> setIcon(icono_d);
        else if (pos_o == 26) ui -> d2 -> setIcon(icono_d);
        else if (pos_o == 27) ui -> d3 -> setIcon(icono_d);
        else if (pos_o == 28) ui -> d4 -> setIcon(icono_d);
        else if (pos_o == 29) ui -> d5 -> setIcon(icono_d);
        else if (pos_o == 30) ui -> d6 -> setIcon(icono_d);
        else if (pos_o == 31) ui -> d7 -> setIcon(icono_d);
        else if (pos_o == 32) ui -> d8 -> setIcon(icono_d);
        else if (pos_o == 33) ui -> e1 -> setIcon(icono_d);
        else if (pos_o == 34) ui -> e2 -> setIcon(icono_d);
        else if (pos_o == 35) ui -> e3 -> setIcon(icono_d);
        else if (pos_o == 36) ui -> e4 -> setIcon(icono_d);
        else if (pos_o == 37) ui -> e5 -> setIcon(icono_d);
        else if (pos_o == 38) ui -> e6 -> setIcon(icono_d);
        else if (pos_o == 39) ui -> e7 -> setIcon(icono_d);
        else if (pos_o == 40) ui -> e8 -> setIcon(icono_d);
        else if (pos_o == 41) ui -> f1 -> setIcon(icono_d);
        else if (pos_o == 42) ui -> f2 -> setIcon(icono_d);
        else if (pos_o == 43) ui -> f3 -> setIcon(icono_d);
        else if (pos_o == 44) ui -> f4 -> setIcon(icono_d);
        else if (pos_o == 45) ui -> f5 -> setIcon(icono_d);
        else if (pos_o == 46) ui -> f6 -> setIcon(icono_d);
        else if (pos_o == 47) ui -> f7 -> setIcon(icono_d);
        else if (pos_o == 48) ui -> f8 -> setIcon(icono_d);
        else if (pos_o == 49) ui -> g1 -> setIcon(icono_d);
        else if (pos_o == 50) ui -> g2 -> setIcon(icono_d);
        else if (pos_o == 51) ui -> g3 -> setIcon(icono_d);
        else if (pos_o == 52) ui -> g4 -> setIcon(icono_d);
        else if (pos_o == 53) ui -> g5 -> setIcon(icono_d);
        else if (pos_o == 54) ui -> g6 -> setIcon(icono_d);
        else if (pos_o == 55) ui -> g7 -> setIcon(icono_d);
        else if (pos_o == 56) ui -> g8 -> setIcon(icono_d);
        else if (pos_o == 57) ui -> h1 -> setIcon(icono_d);
        else if (pos_o == 58) ui -> h2 -> setIcon(icono_d);
        else if (pos_o == 59) ui -> h3 -> setIcon(icono_d);
        else if (pos_o == 60) ui -> h4 -> setIcon(icono_d);
        else if (pos_o == 61) ui -> h5 -> setIcon(icono_d);
        else if (pos_o == 62) ui -> h6 -> setIcon(icono_d);
        else if (pos_o == 63) ui -> h7 -> setIcon(icono_d);
        else if (pos_o == 64) ui -> h8 -> setIcon(icono_d);
        //---
        if (pos == 1) ui -> a1 -> setIcon(icono_o);
        else if (pos == 2) ui -> a2 -> setIcon(icono_o);
        else if (pos == 3) ui -> a3 -> setIcon(icono_o);
        else if (pos == 4) ui -> a4 -> setIcon(icono_o);
        else if (pos == 5) ui -> a5 -> setIcon(icono_o);
        else if (pos == 6) ui -> a6 -> setIcon(icono_o);
        else if (pos == 7) ui -> a7 -> setIcon(icono_o);
        else if (pos == 8) ui -> a8 -> setIcon(icono_o);
        else if (pos == 9) ui -> b1 -> setIcon(icono_o);
        else if (pos == 10) ui -> b2 -> setIcon(icono_o);
        else if (pos == 11) ui -> b3 -> setIcon(icono_o);
        else if (pos == 12) ui -> b4 -> setIcon(icono_o);
        else if (pos == 13) ui -> b5 -> setIcon(icono_o);
        else if (pos == 14) ui -> b6 -> setIcon(icono_o);
        else if (pos == 15) ui -> b7 -> setIcon(icono_o);
        else if (pos == 16) ui -> b8 -> setIcon(icono_o);
        else if (pos == 17) ui -> c1 -> setIcon(icono_o);
        else if (pos == 18) ui -> c2 -> setIcon(icono_o);
        else if (pos == 19) ui -> c3 -> setIcon(icono_o);
        else if (pos == 20) ui -> c4 -> setIcon(icono_o);
        else if (pos == 21) ui -> c5 -> setIcon(icono_o);
        else if (pos == 22) ui -> c6 -> setIcon(icono_o);
        else if (pos == 23) ui -> c7 -> setIcon(icono_o);
        else if (pos == 24) ui -> c8 -> setIcon(icono_o);
        else if (pos == 25) ui -> d1 -> setIcon(icono_o);
        else if (pos == 26) ui -> d2 -> setIcon(icono_o);
        else if (pos == 27) ui -> d3 -> setIcon(icono_o);
        else if (pos == 28) ui -> d4 -> setIcon(icono_o);
        else if (pos == 29) ui -> d5 -> setIcon(icono_o);
        else if (pos == 30) ui -> d6 -> setIcon(icono_o);
        else if (pos == 31) ui -> d7 -> setIcon(icono_o);
        else if (pos == 32) ui -> d8 -> setIcon(icono_o);
        else if (pos == 33) ui -> e1 -> setIcon(icono_o);
        else if (pos == 34) ui -> e2 -> setIcon(icono_o);
        else if (pos == 35) ui -> e3 -> setIcon(icono_o);
        else if (pos == 36) ui -> e4 -> setIcon(icono_o);
        else if (pos == 37) ui -> e5 -> setIcon(icono_o);
        else if (pos == 38) ui -> e6 -> setIcon(icono_o);
        else if (pos == 39) ui -> e7 -> setIcon(icono_o);
        else if (pos == 40) ui -> e8 -> setIcon(icono_o);
        else if (pos == 41) ui -> f1 -> setIcon(icono_o);
        else if (pos == 42) ui -> f2 -> setIcon(icono_o);
        else if (pos == 43) ui -> f3 -> setIcon(icono_o);
        else if (pos == 44) ui -> f4 -> setIcon(icono_o);
        else if (pos == 45) ui -> f5 -> setIcon(icono_o);
        else if (pos == 46) ui -> f6 -> setIcon(icono_o);
        else if (pos == 47) ui -> f7 -> setIcon(icono_o);
        else if (pos == 48) ui -> f8 -> setIcon(icono_o);
        else if (pos == 49) ui -> g1 -> setIcon(icono_o);
        else if (pos == 50) ui -> g2 -> setIcon(icono_o);
        else if (pos == 51) ui -> g3 -> setIcon(icono_o);
        else if (pos == 52) ui -> g4 -> setIcon(icono_o);
        else if (pos == 53) ui -> g5 -> setIcon(icono_o);
        else if (pos == 54) ui -> g6 -> setIcon(icono_o);
        else if (pos == 55) ui -> g7 -> setIcon(icono_o);
        else if (pos == 56) ui -> g8 -> setIcon(icono_o);
        else if (pos == 57) ui -> h1 -> setIcon(icono_o);
        else if (pos == 58) ui -> h2 -> setIcon(icono_o);
        else if (pos == 59) ui -> h3 -> setIcon(icono_o);
        else if (pos == 60) ui -> h4 -> setIcon(icono_o);
        else if (pos == 61) ui -> h5 -> setIcon(icono_o);
        else if (pos == 62) ui -> h6 -> setIcon(icono_o);
        else if (pos == 63) ui -> h7 -> setIcon(icono_o);
        else if (pos == 64) ui -> h8 -> setIcon(icono_o);*/
        flagmov = 0;
        limpia_tablero();
    }
    echiquier.imprimir_tablero_jugador();

}

// Colorea el tablero con los colores originales
void MainWindow::limpia_tablero(){
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
}
