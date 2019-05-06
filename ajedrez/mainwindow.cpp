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

    vector < vector < QPushButton *>> aux(8, vector < QPushButton*>(8));

    aux[0][0] = ui -> a1;
    aux[0][1] = ui -> a2;
    aux[0][2] = ui -> a3;
    aux[0][3] = ui -> a4;
    aux[0][4] = ui -> a5;
    aux[0][5] = ui -> a6;
    aux[0][6] = ui -> a7;
    aux[0][7] = ui -> a8;
    aux[1][0] = ui -> b1;
    aux[1][1] = ui -> b2;
    aux[1][2] = ui -> b3;
    aux[1][3] = ui -> b4;
    aux[1][4] = ui -> b5;
    aux[1][5] = ui -> b6;
    aux[1][6] = ui -> b7;
    aux[1][7] = ui -> b8;
    aux[2][0] = ui -> c1;
    aux[2][1] = ui -> c2;
    aux[2][2] = ui -> c3;
    aux[2][3] = ui -> c4;
    aux[2][4] = ui -> c5;
    aux[2][5] = ui -> c6;
    aux[2][6] = ui -> c7;
    aux[2][7] = ui -> c8;
    aux[3][0] = ui -> d1;
    aux[3][1] = ui -> d2;
    aux[3][2] = ui -> d3;
    aux[3][3] = ui -> d4;
    aux[3][4] = ui -> d5;
    aux[3][5] = ui -> d6;
    aux[3][6] = ui -> d7;
    aux[3][7] = ui -> d8;
    aux[4][0] = ui -> e1;
    aux[4][1] = ui -> e2;
    aux[4][2] = ui -> e3;
    aux[4][3] = ui -> e4;
    aux[4][4] = ui -> e5;
    aux[4][5] = ui -> e6;
    aux[4][6] = ui -> e7;
    aux[4][7] = ui -> e8;
    aux[5][0] = ui -> f1;
    aux[5][1] = ui -> f2;
    aux[5][2] = ui -> f3;
    aux[5][3] = ui -> f4;
    aux[5][4] = ui -> f5;
    aux[5][5] = ui -> f6;
    aux[5][6] = ui -> f7;
    aux[5][7] = ui -> f8;
    aux[6][0] = ui -> g1;
    aux[6][1] = ui -> g2;
    aux[6][2] = ui -> g3;
    aux[6][3] = ui -> g4;
    aux[6][4] = ui -> g5;
    aux[6][5] = ui -> g6;
    aux[6][6] = ui -> g7;
    aux[6][7] = ui -> g8;
    aux[7][0] = ui -> h1;
    aux[7][1] = ui -> h2;
    aux[7][2] = ui -> h3;
    aux[7][3] = ui -> h4;
    aux[7][4] = ui -> h5;
    aux[7][5] = ui -> h6;
    aux[7][6] = ui -> h7;
    aux[7][7] = ui -> h8;

    botones = aux;

    tablero aux2(pos_inicial);
    echiquier = aux2;
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

    limpia_tablero(echiquier,botones,blanco,gris);

    turno = 0;
    //echiquier.imprimir_tablero();
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

    torre tw1(0, 0, 0);   v_torre.push_back(tw1);
    torre tw2(7, 0, 0);   v_torre.push_back(tw2);
    torre tk1(0, 7, 1);   v_torre.push_back(tk1);
    torre tk2(7, 7, 1);   v_torre.push_back(tk2);

    dama dw1(3, 0, 0);   v_dama.push_back(dw1);
    dama dk1(3, 7, 1);   v_dama.push_back(dk1);

    rey rw1(4, 0, 0);   v_rey.push_back(rw1);
    rey rk1(4, 7, 1);   v_rey.push_back(rk1);

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::boton_pulsado(){
    QPushButton *boton = (QPushButton*)sender();
    QString name = boton->objectName();
    pair <int, int> pos = obten_pos(name);

    if (estado_movimiento){
        if (turno == echiquier.mat_escaque[pos.first][pos.second].ocupado){
            botones[pos.first][pos.second] -> autoFillBackground();
            if (echiquier.mat_escaque[pos.first][pos.second].color == 0)
                botones[pos.first][pos.second] -> setPalette(cian);
            else botones[pos.first][pos.second] -> setPalette(azul);
            escaque_origen = pos;
            estado_movimiento = false;
            bool mov_realizado = 0;
            movs_posibles.clear();
            for (unsigned int i = 0; i < v_peon.size(); i++){
                if (mov_realizado == 0){
                    if(v_peon[i].pos.first == escaque_origen.first && v_peon[i].pos.second == escaque_origen.second){
                        v_peon[i].movs(echiquier);
                        movs_posibles = v_peon[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_caballo.size(); i++){
                if (mov_realizado == 0){
                    if(v_caballo[i].pos.first == escaque_origen.first && v_caballo[i].pos.second == escaque_origen.second){
                        v_caballo[i].movs(echiquier);
                        movs_posibles = v_caballo[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_alfil.size(); i++){
                if (mov_realizado == 0){
                    if(v_alfil[i].pos.first == escaque_origen.first && v_alfil[i].pos.second == escaque_origen.second){
                        v_alfil[i].movs(echiquier);
                        movs_posibles = v_alfil[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_torre.size(); i++){
                if (mov_realizado == 0){
                    if(v_torre[i].pos.first == escaque_origen.first && v_torre[i].pos.second == escaque_origen.second){
                        v_torre[i].movs(echiquier);
                        movs_posibles = v_torre[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_dama.size(); i++){
                if (mov_realizado == 0){
                    if(v_dama[i].pos.first == escaque_origen.first && v_dama[i].pos.second == escaque_origen.second){
                        v_dama[i].movs(echiquier);
                        movs_posibles = v_dama[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }
            for (unsigned int i = 0; i < v_rey.size(); i++){
                if (mov_realizado == 0){
                    if(v_rey[i].pos.first == escaque_origen.first && v_rey[i].pos.second == escaque_origen.second){
                        v_rey[i].movs(echiquier, v_peon, v_caballo, v_alfil, v_torre, v_rey, v_dama);
                        movs_posibles = v_rey[i].mov_set;
                        mov_realizado = 1;
                    }
                }
            }

            colorea_tablero(echiquier,botones,cian,azul,movs_posibles);
        }
    }else{
        pair<int,int> escaque_destino = pos;
        bool casilla_correcta = false;
        for (unsigned int i = 0; i < movs_posibles.size(); i++){
            if (movs_posibles[i] == escaque_destino) casilla_correcta = true;
        }
        if (casilla_correcta){
            boton_origen = botones[escaque_origen.first][escaque_origen.second];
            QPushButton *boton_destino = botones[escaque_destino.first][escaque_destino.second];

            if (escaque_destino.first != escaque_origen.first || escaque_destino.second!= escaque_origen.second){
                mueve_icono(&echiquier, boton_destino, escaque_origen,escaque_destino,iconos);
                boton_origen->setIcon(iconos[0]);

                // Cambiar posicion de la pieza
                bool mov_realizado = 0;
                for (unsigned int i = 0; i < v_peon.size(); i++){
                    if (mov_realizado == 0){
                        if(v_peon[i].pos.first == escaque_origen.first && v_peon[i].pos.second == escaque_origen.second){
                            v_peon[i].pos.first = escaque_destino.first;
                            v_peon[i].pos.second = escaque_destino.second;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_caballo.size(); i++){
                    if (mov_realizado == 0){
                        if(v_caballo[i].pos.first == escaque_origen.first && v_caballo[i].pos.second == escaque_origen.second){
                            v_caballo[i].pos.first = escaque_destino.first;
                            v_caballo[i].pos.second = escaque_destino.second;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_alfil.size(); i++){
                    if (mov_realizado == 0){
                        if(v_alfil[i].pos.first == escaque_origen.first && v_alfil[i].pos.second == escaque_origen.second){
                            v_alfil[i].pos.first = escaque_destino.first;
                            v_alfil[i].pos.second = escaque_destino.second;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_torre.size(); i++){
                    if (mov_realizado == 0){
                        if(v_torre[i].pos.first == escaque_origen.first && v_torre[i].pos.second == escaque_origen.second){
                            v_torre[i].pos.first = escaque_destino.first;
                            v_torre[i].pos.second = escaque_destino.second;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_dama.size(); i++){
                    if (mov_realizado == 0){
                        if(v_dama[i].pos.first == escaque_origen.first && v_dama[i].pos.second == escaque_origen.second){
                            v_dama[i].pos.first = escaque_destino.first;
                            v_dama[i].pos.second = escaque_destino.second;
                            mov_realizado = 1;
                        }
                    }
                }
                for (unsigned int i = 0; i < v_rey.size(); i++){
                    if (mov_realizado == 0){
                        if(v_rey[i].pos.first == escaque_origen.first && v_rey[i].pos.second == escaque_origen.second){
                            v_rey[i].pos.first = escaque_destino.first;
                            v_rey[i].pos.second = escaque_destino.second;
                            mov_realizado = 1;
                        }
                    }
}
            }
            turno = ++turno%2;
        }

        limpia_tablero(echiquier,botones,blanco,gris);
        estado_movimiento = true;
    }

    botones[pos.first][pos.second] -> update();
    echiquier.imprimir_tablero_jugador();
}

