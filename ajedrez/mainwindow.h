#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablero.h"
#include <vector>
#include <QIcon>
#include "funciones.h"
#include <QMessageBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    tablero echiquier;//(vector <vector <int>>);
    QPalette blanco, gris, azul, cian, rojo, rojo_oscuro;
    bool estado_movimiento;
    pair <int, int> escaque_origen;
    vector < QIcon > iconos;
    QPushButton *boton_origen;
    vector < vector < QPushButton *>> botones;
    int turno;
    vector <peon> v_peon;
    vector <caballo> v_caballo;
    vector <alfil> v_alfil;
    vector <torre> v_torre;
    vector <dama> v_dama;
    vector <rey> v_rey;
    vector < vector < pair <int,int>>> registro;
    int size_list;
    int n_reg;
    QString id_pieza;
    QString mov_blancas;
    bool fin_de_partida;
    int peon_atq;

    vector<pair<int,int>> movs_posibles;
    vector <pair<int,int>> atq_posibles;
    vector <int> puntuaciones;

private slots:
    void boton_pulsado();


    void on_boton_deshacer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
