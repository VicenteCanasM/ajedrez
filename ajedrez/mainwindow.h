#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablero.h"
#include "piezas.h"
#include <vector>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void limpia_tablero();
    tablero echiquier;//(vector <vector <int>>);
    QPalette blanco, gris, azul, cian;
    //vector < QIcon > iconos;
    bool flagmov;
    pair<int,int> pos_origen;
    int pos_o;
    vector<pair<int,int>> movs_pieza;
    vector <peon> v_peon;
    vector <caballo> v_caballo;
    vector <alfil> v_alfil;
    vector <torre> v_torre;
    vector <dama> v_dama;
    vector <rey> v_rey;


private slots:
    void boton_pulsado(); // Prueba para el connect

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
