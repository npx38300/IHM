#ifndef AUDIO_ANALYSER
#define AUDIO_ANALYSER
 
#include <rssitype.h>
 
class Audio_analyser
{
public:
	Audio_analyser();
	void set_generator();
	void set_analyser ();
    void get_measure();
	void set_filter(double frequence);
	void set_amplitude(double amplitude);
	void set_frequence(double frequence);
	void reset();
	void stop();
    double return_rms1() const;
    double return_rms2() const;
    void error_message(double status);
    
private:

    double m_rmsmesure1;
    double m_rmsmesure2;
	ViSession session_anl;
	ViSession session_gen;
};
 
#endif
