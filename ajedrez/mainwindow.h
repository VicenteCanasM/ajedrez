#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablero.h"
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
    tablero echiquier;//(vector <vector <int>>);
    QPalette blanco, gris, azul, cian;

private slots:
    void on_a1_clicked();
    void on_a2_clicked();
    void on_a3_clicked();
    void on_a4_clicked();
    void on_a5_clicked();
    void on_a6_clicked();
    void on_a7_clicked();
    void on_a8_clicked();
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_c1_clicked();
    void on_c2_clicked();
    void on_c3_clicked();
    void on_c4_clicked();
    void on_c5_clicked();
    void on_c6_clicked();
    void on_c7_clicked();
    void on_c8_clicked();
    void on_d1_clicked();
    void on_d2_clicked();
    void on_d3_clicked();
    void on_d4_clicked();
    void on_d5_clicked();
    void on_d6_clicked();
    void on_d7_clicked();
    void on_d8_clicked();
    void on_e1_clicked();
    void on_e2_clicked();
    void on_e3_clicked();
    void on_e4_clicked();
    void on_e5_clicked();
    void on_e6_clicked();
    void on_e7_clicked();
    void on_e8_clicked();
    void on_f1_clicked();
    void on_f2_clicked();
    void on_f3_clicked();
    void on_f4_clicked();
    void on_f5_clicked();
    void on_f6_clicked();
    void on_f7_clicked();
    void on_f8_clicked();
    void on_g1_clicked();
    void on_g2_clicked();
    void on_g3_clicked();
    void on_g4_clicked();
    void on_g5_clicked();
    void on_g6_clicked();
    void on_g7_clicked();
    void on_g8_clicked();
    void on_h1_clicked();
    void on_h2_clicked();
    void on_h3_clicked();
    void on_h4_clicked();
    void on_h5_clicked();
    void on_h6_clicked();
    void on_h7_clicked();
    void on_h8_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
