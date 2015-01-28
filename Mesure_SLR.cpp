// Mesure_SLR.cpp
//

//include
#include "Mesure_SLR.h"
#include "audio_analyser.h"
#include "rssiup.h"
#include "math.h"

//variables globales
//freq,CH1 OUT(dBV),CH1 IN(dBV),CH2 IN (dBm),Si,Wsi,pre_SLR
double	tab [14] [7] = {{200,0,0,0,0,76.9,0}
                        ,{250,0,0,0,0,62.6,0}
                        ,{315,0,0,0,0,62,0}
                        ,{400,0,0,0,0,44.7,0}
                        ,{500,0,0,0,0,53.1,0}
                        ,{630,0,0,0,0,48.5,0}
                        ,{800,0,0,0,0,47.6,0}
                        ,{1000,0,0,0,0,50.1,0}
                        ,{1250,0,0,0,0,59.1,0}
                        ,{1600,0,0,0,0,56.7,0}
                        ,{2000,0,0,0,0,72.2,0}
                        ,{2500,0,0,0,0,72.6,0}
                        ,{3150,0,0,0,0,89.2,0}
                        ,{4000,0,0,0,0,117,0}};

Mesure_SLR::Mesure_SLR()
{

	m_SLR=0;
	m_MRP=-4.7; 
	m_dBV_inf=-20;
	m_dBV_sup=0;
	m_dicho=0;
	m_dBV_mesure=0;
	m_Somme=0;
	m_flag=true;
	m_precision=0.05;
}

void Mesure_SLR::calibration()
{

    int i;
	double rms_mesure;
	//Set audio analyser
	Dlg.set_generator();
	Dlg.set_analyser();

    for(i=0;i<=13;i++)
    {

		//set frequence 
        Dlg.set_frequence(tab[i][0]);
        //set filter
        Dlg.set_filter(tab[i][0]);
        do
        {
            //valeur dichotomie
            m_dicho = pow(10,(((m_dBV_sup+m_dBV_inf)/2)/20));

            //Set amplitude
			Dlg.set_amplitude(m_dicho);
            //mesure RMS
			rms_mesure=Dlg.get_measure();
          
            //conversion Volt ==> dBV
            m_dBV_mesure = 20 * log10(rms_mesure);
            m_dicho = 20 * log10(m_dicho);

            //dichotomie
            if((m_dBV_mesure > (m_MRP - m_precision)) && (m_dBV_mesure < (m_MRP + m_precision)))
            {
                m_flag=false;
                tab[i][1] = m_dicho;
                tab[i][2] = m_dBV_mesure;
            }
            if(m_dBV_mesure < (m_MRP - m_precision))
            {
                m_dBV_inf=m_dicho;
            }
            if(m_dBV_mesure > (m_MRP + m_precision))
            {
                m_dBV_sup=m_dicho;
            }
            if(fabs(m_dBV_sup-m_dBV_inf) <= m_precision)
            {
                m_dBV_sup=0;
                m_dBV_inf=-20;
            }
            m_dicho = (m_dBV_sup+m_dBV_inf)/2;

        }
        while(m_flag);
        m_flag=true;
        m_dBV_inf=-20;
        m_dBV_sup=0;
    }
    m_SLR = ((-10/0.175)*(log10(m_Somme)));
	Dlg.stop();
}

void Mesure_SLR::mesure()
{
	int i;
	double rms_mesure;
	for(i=0;i<=13;i++)
	{
        rms_mesure=pow(10,tab[i][1]);

        Dlg.set_frequence(tab[i][0]);
        Dlg.set_filter(tab[i][0]);
		Dlg.set_amplitude(rms_mesure);

		rms_mesure=Dlg.get_measure();
        tab[i][3] = 20 * log10(rms_mesure/sqrt(0.6));

		//Si
        tab[i][4] = tab[i][3]-tab[i][2]-24;

		//calcul SLR
        tab[i][6]=pow(10,(0.1*0.175*(tab[i][4]-tab[i][5])));
        m_Somme+=tab[i][6];
	}
	Dlg.stop();
}
