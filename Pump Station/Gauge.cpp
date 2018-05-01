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


double Gauge::getDataArray(int i)
{
	return(DataArray[i]);
}

Gauge::Gauge()
{
	value = new double[SampSize];

}

void Gauge::setArrayValue(int i, double data)
{

	value[i] = data;


	return;
}


Gauge ::~Gauge()
{
	delete[] value;
}
