#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

class Gauge
{
public:
	double avgdata(double dataArray[], int arraysize);
	// average data function
	//void set(int SampSize, double DataArray[]);
	double getDataArray();
	int getSampSize();
	Gauge(int SampSize);


private:
	string name;
	double DataArray[MaxSampSize];
	int SampSize;

	
	~Gauge();
};

