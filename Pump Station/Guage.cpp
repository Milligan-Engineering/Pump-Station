#include "Guage.h"
#include <isostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


double Guage::avgdata(double dataArray[], int arraysize)
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

//void Guage::set(string Gaugename, double Gaugedata, int samplesize)
//{
	
//}

int Guage::getSampSize()
{
	return SampSize;
}

double Guage::getDataArray()
{
	return DataArray;
}


Guage::Guage(int SampSize)
{
}
