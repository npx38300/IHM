#ifndef PLOT_H
#define PLOT_H
#include <qwt_plot.h>
#include <qwt_plot_curve.h>


class qwtplotcurve;

class Plot: public QwtPlot
{
    Q_OBJECT

    public:
       Plot( QWidget *parent );
       void set_data_curve( const double *frequency, const double *amplitude, int count );
       QwtPlotCurve *d_curve;
};

#endif // PLOT_H
