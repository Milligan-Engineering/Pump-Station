#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

class Gauge
{
public:
	double avgdata();
	// average data function
	void setgauge(int SampSize);
	void setArrayValue(int i,double data);
	double getDataArray();
	int getSampSize();
	double getAvgdata();


private:
	string name;
	double DataArray[1000], Avgdata;
	int SampSize;

};

