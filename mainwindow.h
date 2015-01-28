#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "audio_analyser.h"
#include "Plot.h"


void data_graph(double Gain,int colonne);
void tab_write();

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public slots:
    void mesureRLR();
    void mesureSLR();
    void calibrationSLR();
    void set_curve();


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    double m_SLR;
    double m_RLR;
    double m_coeff_SLR;
    double m_coeff_RLR;
    double m_validation_RLR;
    double m_RLR_ref;
    double m_MRP;
    double m_dBV_inf;
    double m_dBV_sup;
    double m_precision;
    double m_gain;
    Audio_analyser Dlg;
    Plot *d_curve;

};

#endif // MAINWINDOW_H
