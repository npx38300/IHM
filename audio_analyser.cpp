#include "audio_analyser.h"
#include "Mesure_SLR.h"
#include "rssiup.h"
#include "fstream"
#include <iostream>
#include "string.h"

using namespace std;

Audio_analyser::Audio_analyser()
{
     session_anl=0;
	 session_gen=0;

}

void Audio_analyser::error_message(double status)
{
    ViChar message[256];
    if(!(status==0))
    {
        rssiup_error_message(session_anl,status,message);
        string const LOG("D:/Sujet de Stage/Final/Final/log.txt");
        ofstream monFlux(LOG.c_str());
        if(monFlux)
        {
               monFlux <<message<<endl;
        }
        else
        {
            monFlux << "ERREUR: Impossible d'ouvrir le fichier." << endl;
        }
    }
}

void Audio_analyser::set_generator()
{
    error_message(rssiup_init("USB::0x0AAD::0x0008::100084", VI_TRUE, VI_TRUE,&session_gen));
    error_message(rssiup_SetGeneratorDeviceSelector		(session_gen, RSSIUP_GEN_A49));
    error_message(rssiup_SetAnalogGeneratorFloatGround	(session_gen, RSSIUP_CHA, VI_FALSE));
    error_message(rssiup_SetAnalogGeneratorRangeValue	(session_gen, RSSIUP_CHA, RSSIUP_RANGE_MODE_AUTO, 0.0, RSSIUP_UNIT_V));
    error_message(rssiup_SetGeneratorFunctionState		(session_gen, RSSIUP_CHA, RSSIUP_GEN_FUNC_SINE,VI_TRUE));
    error_message(rssiup_SetAnalogGeneratorOutput		(session_gen, RSSIUP_CHA, VI_TRUE));
}

double Audio_analyser::return_rms1() const
{
    return m_rmsmesure1;
}

double Audio_analyser::return_rms2() const
{
    return m_rmsmesure2;
}

void Audio_analyser::set_frequence(double frequence)
{
	//frequence
    error_message(rssiup_SetGeneratorFunctionSineShape	(session_gen
                                            ,frequence, RSSIUP_UNIT_HZ			/*frequence 1*/
                                            ,0, RSSIUP_UNIT_DEG					/*phase 1*/
                                            ,frequence, RSSIUP_UNIT_HZ			/*frequence 2*/
                                            ,0, RSSIUP_UNIT_DEG));

}
void Audio_analyser::set_amplitude(double amplitude)
{
	//amplitude
    error_message(rssiup_SetGeneratorFunctionSineDimension(session_gen, RSSIUP_CHAB
                                            ,0, RSSIUP_UNIT_V				/*offset*/
											,amplitude, RSSIUP_UNIT_V		/*channel 1 amplitude*/
                                            ,0, RSSIUP_UNIT_V));             /*channel 2 amplitude*/
}

void Audio_analyser::set_filter(double frequence)
{
    /* /!\filtre bugué: changer la catégorie du filtre pour en changer sa frequence/!\ */
    error_message(rssiup_SetAnalyzerDigitalFilter            (session_anl,RSSIUP_CHAB,RSSIUP_DIGI_FILTER_SECTION_1,RSSIUP_DIGI_FILTER_TYPE_1P1_OCTAVE,frequence));
    error_message(rssiup_SetAnalyzerDigitalFilter            (session_anl,RSSIUP_CHAB,RSSIUP_DIGI_FILTER_SECTION_1,RSSIUP_DIGI_FILTER_TYPE_1P3_OCTAVE,frequence));

}


void Audio_analyser::set_analyser ()
{
	//set Analyser
    error_message(rssiup_init("USB::0x0AAD::0x0008::100084",VI_TRUE, VI_FALSE ,&session_anl));
    error_message(rssiup_SetAnalyzerDeviceSelector          (session_anl,RSSIUP_ANL_A49));
    error_message(rssiup_SetAnalyzerFunctionState           (session_anl,RSSIUP_CHAB ,RSSIUP_ANL_FUNC_RMSDC,VI_FALSE,VI_FALSE));
    error_message(rssiup_SetMeasurementMode                 (session_anl,RSSIUP_MEAS_MODE_CONTINUOUS));
    error_message(rssiup_AbortMeasurement                   (session_anl));
    error_message(rssiup_SetAnalogAnalyzerCoupling          (session_anl,RSSIUP_ANL_COUPLING_AC));
    error_message(rssiup_SetAnalogAnalyzerRangeValue		(session_anl,RSSIUP_CHAB ,RSSIUP_RANGE_MODE_AUTO,0.0));
    error_message(rssiup_SetAnalogAnalyzerInput             (session_anl,RSSIUP_CHAB ,RSSIUP_ANL_INPUT_ON));
    error_message(rssiup_SetAnalogAnalyzerFloatGround       (session_anl,RSSIUP_CHAB ,VI_TRUE));
    error_message(rssiup_SetAnalyzerFunctionRMSDCSettings   (session_anl,RSSIUP_CHAB,0.1,0.2,RSSIUP_SYNC_MODE_SYNC,RSSIUP_SYNC_SOURCE_SIN_GEN_A_RISE));
    error_message(rssiup_SetAnalyzerFunctionState           (session_anl,RSSIUP_CHAB ,RSSIUP_ANL_FUNC_RMSDC,VI_TRUE,VI_TRUE));
    error_message(rssiup_SetAnalyzerFunctionRMSDCAveraging  (session_anl,RSSIUP_CHAB,0,1,RSSIUP_AVERAGING_MODE_NORMAL,20,0,1));

}

void Audio_analyser::get_measure()
{
    double DC[2],freq[2],rms[2];
    long unit_rms,unit_DC,status[2],unit_freq,async[2];
    error_message(rssiup_StartMeasurement                   (session_anl));
    error_message(rssiup_AnalyzerRMSDCMeasurement           (session_anl,DC,&unit_DC,rms,&unit_rms,freq,&unit_freq,status,async));
    error_message(rssiup_AnalyzerRMSDCMeasurement           (session_anl,DC,&unit_DC,rms,&unit_rms,freq,&unit_freq,status,async));
    error_message(rssiup_AbortMeasurement                   (session_anl));
    /*/!\appel 2 fois de la fonction mesure car buffer non maj dans certaine mesure, besoin d'un second appel/!\*/
    m_rmsmesure1=rms[0];
    m_rmsmesure2=rms[1];
}

void Audio_analyser::reset()
{
    error_message(rssiup_init("USB::0x0AAD::0x0008::100084",VI_TRUE,VI_TRUE,&session_gen));
    error_message(rssiup_init("USB::0x0AAD::0x0008::100084",VI_TRUE,VI_TRUE,&session_anl));
}

void Audio_analyser::stop()
{
    error_message(rssiup_AbortMeasurement                   (session_anl));
    error_message(rssiup_init("USB::0x0AAD::0x0008::100084",VI_TRUE,VI_TRUE,&session_gen));
    error_message(rssiup_init("USB::0x0AAD::0x0008::100084",VI_TRUE,VI_TRUE,&session_anl));
    error_message(rssiup_close(session_gen));
    error_message(rssiup_close(session_anl));
}
