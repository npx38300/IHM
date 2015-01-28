#include "math.h"
#include "string.h"
#include "QPainter"
#include "fstream"
#include <iostream>

using namespace std;

void data_graph(double data[14][12],double Gain)
{
    int i;
    //GUL;GLL;UL;LL
    double shape[6][4]={{0,0,0,0}
                        ,{0,-14,0,0}
                        ,{0,-8,0,0}
                        ,{4,-8,0,0}
                        ,{4,-8,0,0}
                        ,{4,-11,0,0}};
    double somme(0);
    double offset(0);
    for(i=1;i<=13;i++)
    {
        somme= somme + data[i][5];
    }
    offset=fabs(somme/12+Gain);
    for(i=0;i<=13;i++)
    {
        shape[i][2]=shape[i][0]-offset;
        shape[i][3]=shape[i][2]-offset;
    }

}

void data_write(double data[14][12],int mesure)
{
    int i,y,z;
    string const SLR("D:/Sujet de Stage/Final/Final/data.txt");
    ofstream monFlux(SLR.c_str());
    if(monFlux) //On teste si tout est OK
    {
        if(mesure == 1) z=9;
        else z=11;
        for(i=0;i<=13;i++)
        {

            for(y=0;y<=z;y++)
            {
                monFlux << data[i][y] <<";";
            }
            monFlux<<endl;
        }
    }
    else
    {
        monFlux << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}


