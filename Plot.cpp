#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_legend.h>
#include <qwt_scale_engine.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include "Plot.h"




Plot::Plot( QWidget *parent ):
    QwtPlot( parent )
{
    setAutoReplot(false);
    setTitle( "Efficacité à l'émission:" );

    //set Canvas
    QwtPlotCanvas *canvas = new QwtPlotCanvas();
    canvas->setBorderRadius( 10 );
    setCanvas( canvas );
    setCanvasBackground( QColor(0,0,0,255) );

    //legend
    QwtLegend *legend = new QwtLegend;
    insertLegend( legend, QwtPlot::BottomLegend );

    // grid
    QwtPlotGrid *grid = new QwtPlotGrid;
    grid->enableXMin( true );
    grid->setMajorPen( Qt::white, 0, Qt::DotLine );
    grid->setMinorPen( Qt::gray, 0 , Qt::DotLine );
    grid->attach( this );

    // axes
    enableAxis( QwtPlot::yRight );
    setAxisTitle( QwtPlot::xBottom, "Frequence (Hz)" );
    setAxisTitle( QwtPlot::yLeft, "Gain (dBV" );

    setAxisMaxMajor( QwtPlot::xBottom, 6 );
    setAxisMaxMinor( QwtPlot::xBottom, 9 );
    setAxisScaleEngine( QwtPlot::xBottom, new QwtLogScaleEngine );

    // curves
    d_curve = new QwtPlotCurve( "SLR" );
    d_curve->setRenderHint( QwtPlotItem::RenderAntialiased );
    d_curve->setPen( Qt::red );
    d_curve->setLegendAttribute( QwtPlotCurve::LegendShowLine );
    d_curve->setYAxis( QwtPlot::yLeft );
    d_curve->attach( this );

    //set_data_curve(freq,gain,14);
    //setAutoReplot( true );
}

void Plot::set_data_curve(const double *frequence, const double *amplitude,int count)
{
    d_curve->setSamples(frequence, amplitude, count);
    setAutoReplot( true );
}

