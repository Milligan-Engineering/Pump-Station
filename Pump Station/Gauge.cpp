#include "Gauge.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


double Gauge::avgdata()
{
	double sum = 0;
	int i;

	for (i = 0; i < SampSize; i++)
	{
		sum += DataArray[i];
	}
	Avgdata = sum / SampSize;
	return(Avgdata);
}

int Gauge::getSampSize()
{
	return SampSize;
}

double Gauge::getAvgdata()
{
	return Avgdata;
}

void Gauge::setgauge(int SampleSize)
{
	SampSize = SampleSize;

	return;
}

void Gauge::setArrayValue(int i,double data)
{
	
		DataArray[i]=data;


	return;
}
