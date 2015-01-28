#ifndef MESURE_SLR
#define MESURE_SLR
#include "audio_analyser.h"

 
class Mesure_SLR
{
public:
	Mesure_SLR();
    void calibration();
	void mesure();
	
private:
	double m_SLR;
	double m_MRP; 
	double m_dBV_inf;
	double m_dBV_sup;
	double m_dicho;
	double m_dBV_mesure;
	double m_Somme;
	bool m_flag;
	double m_precision;
	Audio_analyser Dlg;

};
 
#endif

