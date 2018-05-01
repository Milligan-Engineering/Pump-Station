#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef double* DataArrayPtr;
class Gauge
{
public:
	Gauge();
	double avgdata();
	// average data function
	void setgauge(int SampSize);
	void setArrayValue(int i,double data);
	double getDataArray(int i);
	int getSampSize();
	double getAvgdata();
	~Gauge();
protected:
	double Avgdata;
	int SampSize;
private:
	double DataArray[1000];
	DataArrayPtr value;
};

