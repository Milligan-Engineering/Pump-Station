#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

class Guage
{
public:
	double avgdata(double dataArray[], int arraysize);
	// average data function
	//void set(int SampSize, double DataArray[]);
	double getDataArray();
	int getSampSize();
	Guage(int SampSize);


private:
	string name;
	double DataArray[];
	int SampSize;

	
	~Guage();
};

