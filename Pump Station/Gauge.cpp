#include "Gauge.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


double Gauge::avgdata(double dataArray[], int arraysize)
{
	double sum = 0;
	double avgdata1;
	int i;

	for (i = 0; i < arraysize; i++)
	{
		sum += dataArray[i];
	}
	avgdata1 = sum / arraysize;
	return(avgdata1);
}

//void Gauge::set(string Gaugename, double Gaugedata, int samplesize)
//{
	
//}

int Gauge::getSampSize()
{
	return SampSize;
}

double Gauge::getDataArray()
{
	return DataArray;
}


Gauge::Gauge(int SampSize)
{
}
