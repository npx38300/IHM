#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include "rssiup.h"
#include "audio_analyser.h"
#include "math.h"
#include "Plot.h"
#include "fstream"
#include "QPainter"

#include <iostream>

using namespace std;

/*  0- frequence
    1- WSI
    2- WRI
    3- LE
    4- Gene (CH1 OUT)
    5- HFRP (CH1 IN)
    6- Em PTE   (CH2 IN)
    7- SI_SLR
    8- Coeff_SLR
    9- Sje      (CH1 IN)
   10- Si_RLR
   11- Coeff_RLR*/

double data_base [14] [12] = {{200,76.9,85,8.4,0,0,0,0,0,0,0,0}
                              ,{250,62.6,74.7,4.9,0,0,0,0,0,0,0,0}
                              ,{315,62,79,1,0,0,0,0,0,0,0,0}
                              ,{400,44.7,63.7,-0.7,0,0,0,0,0,0,0,0}
                              ,{500,53.1,73.5,-2.2,0,0,0,0,0,0,0,0}
                              ,{630,48.5,69.1,-2.6,0,0,0,0,0,0,0,0}
                              ,{800,47.6,68,-3.2,0,0,0,0,0,0,0,0}
                              ,{1000,50.1,68.7,-2.3,0,0,0,0,0,0,0,0}
                              ,{1250,59.1,75.1,-1.2,0,0,0,0,0,0,0,0}
                              ,{1600,56.7,70.4,-0.1,0,0,0,0,0,0,0,0}
                              ,{2000,72.2,81.4,3.6,0,0,0,0,0,0,0,0}
                              ,{2500,72.6,76.5,7.4,0,0,0,0,0,0,0,0}
                              ,{3150,89.2,93.3,6.8,0,0,0,0,0,0,0,0}
                              ,{4000,117,113.8,8.8,0,0,0,0,0,0,0,0}};

//GUL;GLL;UL;LL
double shape[8][9]={{100,   -12,    0,      -10,    0,0,0,0,0}
                   ,{200,   0,      0,      2,      0,0,0,0,0}
                   ,{300,   0,      -14,    2,      -9,0,0,0,0}
                   ,{1000,  0,      -8,     2,      -7,0,0,0,0}
                   ,{2000,  4,      -8,     2,      -12,0,0,0,0}
                   ,{3000,  4,      -8,     2,      0,0,0,0,0}
                   ,{3400,  4,      -11,    2,      0,0,0,0,0}
                   ,{4000,  0,      0,      0,      0,0,0,0,0}};



void  MainWindow::set_curve()
{
    double frequence[14],amplitude[14];
    int i;

    for(i=0;i<14;i++)
    {
        frequence[i]=data_base[i][0];
        amplitude[i]=data_base[i][7];
    }

    d_curve->set_data_curve(frequence,amplitude,14);
    d_curve->setContentsMargins( 5, 5, 5, 0 );
    d_curve->move(200,300);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
       //Initialisation attributs
       m_SLR=0;
       m_coeff_SLR=0.175;
       m_coeff_RLR=0.175;
       m_validation_RLR=0;
       m_RLR_ref=-15.8;
       m_MRP=-4.7;
       m_dBV_inf=-20;
       m_dBV_sup=-10;
       m_precision=0.05;
       m_gain=1;

       //curve
       d_curve = new Plot(this);

       //construction
       ui->setupUi(this);

       //connecteur
       connect(ui->button_calibration,SIGNAL(clicked()),this,SLOT(calibrationSLR()));
       connect(ui->button_mesure,SIGNAL(clicked()),this,SLOT(mesureSLR()));
       connect(ui->button_mesure_RLR,SIGNAL(clicked()),this,SLOT(mesureRLR()));


       //Initialisation IHM
       ui->button_mesure->setEnabled(false);
       ui->calibration_check->setEnabled(false);
       ui->calibration_check->setChecked(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void tab_write()
{
    int i,y;
    string const SLR("D:/Sujet de Stage/Final/Final/data.txt");
    ofstream monFlux(SLR.c_str());
    if(monFlux) //On teste si tout est OK
    {
        for(i=0;i<14;i++)
        {
            for(y=0;y<12;y++)
            {
                monFlux<<data_base[i][y]<<";";
            }
            monFlux<<endl;
        }
        monFlux<<endl<<endl;
        for(i=0;i<8;i++)
        {
            for(y=5;y<9;y++)
            {
                monFlux<<shape[i][y]<<";";
            }
            monFlux<<endl;
        }
    }
}

void data_graph(double Gain,int colonne)
{

    int i;
    double offset(0);
    double max(data_base[0][colonne]),min(data_base[0][colonne]);
    switch(colonne)
    {
    case 7: //SLR
        for(i=1;i<14;i++)
        {
            if(data_base[i][colonne]>max) max=data_base[i][colonne];
            if(data_base[i][colonne]<min) min=data_base[i][colonne];
        }
        offset=fabs((max-min)/2+Gain);

        for(i=0;i<8;i++)
        {
            shape[i][5]=shape[i][1]-offset;
            shape[i][6]=shape[i][2]-offset;
        }
     break;

     case 10: //RLR
        for(i=1;i<14;i++)
        {
            if(data_base[i][colonne]>max) max=data_base[i][colonne];
            if(data_base[i][colonne]<min) min=data_base[i][colonne];
        }
        offset=fabs((max-min)/2+Gain);

        for(i=0;i<8;i++)
        {
            shape[i][7]=shape[i][3]-offset;
            shape[i][8]=shape[i][4]-offset;
        }
     break;
    }
}

void MainWindow::calibrationSLR()
{
    //déclaration variables

    int i;
    bool flag=true;
    double rms_mesure,dBV_mesure,dicho;

    //Set audio analyser
    Dlg.set_generator();
    Dlg.set_analyser();

    //Handling
    for(i=0;i<14;i++)
    {

        //Progress bar begins
        ui->Progress_bar_calibration->setValue(i+1);

        //set frequence
        Dlg.set_frequence(data_base[i][0]);
        //set filter
        Dlg.set_filter(data_base[i][0]);

        do
        {
            //valeur dichotomie
            dicho = pow(10,(((m_dBV_sup+m_dBV_inf)/2)/20));

            //Set amplitude
            Dlg.set_amplitude(dicho);

            //mesure RMS
            Dlg.get_measure();
            rms_mesure=Dlg.return_rms1();

            //conversion Volt ==> dBV
            dBV_mesure = 20 * log10(rms_mesure);
            dicho = 20 * log10(dicho);

            //dichotomie
            if((dBV_mesure > (m_MRP - m_precision)) && (dBV_mesure < (m_MRP + m_precision)))
            {
                flag=false;
                data_base[i][4] = dicho;
                // option: verification (data_base[i][] = dBV_mesure;)
            }
            if(dBV_mesure < (m_MRP - m_precision))
            {
                m_dBV_inf=dicho;
            }
            if(dBV_mesure > (m_MRP + m_precision))
            {
                m_dBV_sup=dicho;
            }
            if(fabs(m_dBV_sup-m_dBV_inf) <= 0.01)
            {
                m_dBV_sup=-10;
                m_dBV_inf=-20;
            }
        }
        while(flag);
        flag=true;
        m_dBV_inf=-20;
        m_dBV_sup=-10;
    }
    //stop Generator
    Dlg.stop();
    //calibration => Done
    ui->button_mesure->setEnabled(true);
    ui->calibration_check->setChecked(true);
}

void MainWindow::mesureSLR()
{
    //variables

    int i;
    double Somme=0;
    double rms_mesure[2];

    //config
    Dlg.set_generator();
    Dlg.set_analyser();

    //handling
    for(i=0;i<14;i++)
    {
        //Progress bar begins
        ui->Progress_bar_SLR->setValue(i+1);

        //dBV => RMS
        rms_mesure[1]=pow(10,(data_base[i][4]/20));

        //Set
        Dlg.set_frequence(data_base[i][0]);
        Dlg.set_filter(data_base[i][0]);
        Dlg.set_amplitude(rms_mesure[1]);

        //measure
        Dlg.get_measure();
        rms_mesure[0]=Dlg.return_rms1();
        rms_mesure[1]=Dlg.return_rms2();

        //save data
        data_base[i][5] = 20 * log10(rms_mesure[0]);
        data_base[i][6] = 20 * log10(rms_mesure[1]/sqrt(0.6));

        //Si
        data_base[i][7] = data_base[i][6]-data_base[i][5]-24;

        //calcul SLR
        data_base[i][8]=pow(10,(0.1*m_coeff_SLR*(data_base[i][7]-data_base[i][1])));
        Somme+=data_base[i][8];

    }
    //Stop generator
    Dlg.stop();

    //SLR
    m_SLR = (-10/m_coeff_SLR)*log10(Somme);
    data_graph(0,7);
    tab_write();

    //SLR => Done
    set_curve();
    ui->LCD_SLR->display(m_SLR);
}

void MainWindow::mesureRLR()
{
    //Declaration Variables
    int i;
    double somme=0,rms;

    //set generator
    Dlg.set_generator();
    Dlg.set_analyser();

    //dBV => RMS
    rms=pow(10,(m_RLR_ref/20))*sqrt(0.6);

    //Set Amplitude
    Dlg.set_amplitude(rms);

    //Handling
    for(i=0;i<14;i++)
    {
        //set frequence
        Dlg.set_frequence   (data_base[i][0]);
        Dlg.set_filter      (data_base[i][0]);

        //get measure
        Dlg.get_measure();

        //Progress bar change value
        ui->Progress_bar_RLR->setValue(i+1);

        //Sje
        data_base[i][9] = Dlg.return_rms1();
        data_base[i][9] = 20 * log10(data_base[i][9]);

        //data Handling
        //Si
        data_base[i][10]=data_base[i][9]-(data_base[i][3]*m_validation_RLR);

        //coeff pre-RLR
        data_base[i][11]=pow(10,(0.1*m_coeff_RLR*(data_base[i][10]-data_base[i][2])));

        //calcul pre-RLR
        somme+=data_base[i][11];
    }
    //Stop generator
    Dlg.stop();

    //RLR
    m_RLR = (-10/m_coeff_RLR)*log10(somme);
    data_graph(0,10);
    tab_write();

    //RLR => Done
    ui->LCD_RLR->display(m_RLR);
}

