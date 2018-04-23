// File name: Pump station
// Author: John Cole
// Email Address: jdcole@my.milligan.edu
// Project Milestone: 9
// Description: Control and measure pump flow station
// Last Changed: March 23, 2018

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "Gauge.h"
#include "flow.h"
#include <time.h>   // Added for random number generation

using namespace std;

double avgdata(double dataArray[], int arraysize);
//precondition: array for the gauge passed through data array and sample size of the data array 
//postcondition: we should get the average data of the specified data array returned through avgdata
void StudentProgram();
//void TeacherSettings();
void StudentSetup();
void SystemControl(); 
void DataOptions();
void genArray();
//void AvgDataSwitch();
void gentime();
void FileExport();

const int MaxSampSize = 1000;// max array size
/*double pressure1[MaxSampSize] = { 3.6,6.8,5,2.4,9.4,5,8.5,4.5,7.2,9.5,22,4.5,2,15,6.5 };
double pressure2[MaxSampSize] = { 3.9,2.2,8.9,5.6,4.2,5,6,4,5,8,5,5.5,10,4.5,6.3 };
double pressure3[MaxSampSize] = { 1.5,6.5,4.3,8.6,7.6,5.4,8,2.5,2.7,6.5,10,2,5,8,9 };
double flow[MaxSampSize] = { 1.2,7.5,8,6.5,9.4,7.6,8.5,4,5,7.6,8,15,16,2,6.5 };
int SampleTime[MaxSampSize] = { 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75 };
int sampleSize;*/
// Structure is technically Ok but does not seem very useful. Structures are more geared toward collecting data
// that is of different types/nature. Would  NumberofSamples, SamplingRate, and SampleDuration be a better candidate?

void genData(double data[], double avgVal[], double rangeVal[], int numVal, double period);
//Preconditions: The high and low values of the generated data are given in highVal and lowVal
//				The number of random values generated is given in samples.
//				The properly sized array, data, should be declared.
//				The interval between samples is given in period in seconds.
//Postcondtions: Uniform random numbers are stored in data at an interval given by rate.

struct Alarms
{
	int WaterLevel, WaterPressure;
	double FlowRate;
};

Alarms systemAlarms;

Gauge P1;
Gauge P2;
Gauge P3;
flow F1;

//No Guage objects declared.
//No Flow ojects declared.

int main()
{
	char opt;
	//TeacherSettings();
	StudentProgram();
	cout << "Enter any key to exit \n";
	cin >> opt;

	return(0);
}

void StudentProgram()
{
	StudentSetup();
	SystemControl();
	DataOptions();
}

/*void TeacherSettings() 
{
	char inFileName[16];

	ifstream inStream;
	
	cout << "Enter in the file you wish to import (maximum of 15 characters): \n";
	cin >> inFileName;

	inStream.open(inFileName);
	if (inStream.fail())
		cout << "Input file opening failed. \n";
		char wait;
		cin >> wait;
		exit(1);
	}
	
	inStream >> WaterLevel >> WaterPressure >> FlowRate;
	
	inStream.close();
	return;
}*/

void StudentSetup()
{
	string date;
	string project;
	string Class;
	const int maxUsers = 4;
	string user[maxUsers];
	int numUsers;

	do
	{
		cout << "enter number of users (between 1-4) " << endl << endl;
		cin >> numUsers;
		cout << endl;
	} while ((numUsers <= 0) || (numUsers >= 5));

	int i = 0;

	while (i < numUsers)
	{
		cout << "enter username no spaces" << endl << endl;
		cin >> user[i];
		cout << endl << "user " << i + 1 << " is " << user[i] << endl << endl;

		i++;

	}


	cout << "enter date" << endl << endl;
	cin >> date;
	cout << endl;

	cout << "enter project name" << endl << endl;
	cin >> project;
	cout << endl;

	cout << "enter class name" << endl << endl;
	cin >> Class;
	cout << endl;

	cout << "Enter Low Water Level Alarm \n";
	cin >> systemAlarms.WaterLevel;
	cout << endl<< "Enter High Water Pressure Alarm \n";
	cin >> systemAlarms.WaterPressure;
	cout << endl << "Enter Low Flow Rate Alarm \n";
	cin >> systemAlarms.FlowRate;


	return;
}

void SystemControl()
{
	

	int control;
	cout << "Do you want to turn on the system? \n"
		<< "Enter 1 for yes \n"
		<< "Enter anything else for no \n";
	cin >> control;

	switch (control)
	{
	case 1:
		cout << "All systems go \n" << endl;
		break;
	default:
		cout << "system shut off \n" << endl;	
	}
	
	genArray();
	

	return;

}

void DataOptions()
{
	double Density, Dia1, Dia2;
	int SampSize;

	cout << "Enter the outer Diameter \n";
	cin >> Dia1;
	cout << endl << "Enter the inner Diameter \n";
	cin >> Dia2;
	cout << endl << "Enter the liquid density \n";
	cin >> Density;
	Density = Density * (0.000578704);
	cout << endl << "Enter number of samples (<1000) \n";
	cin >> SampSize;

	P1.setgauge(SampSize);
	P2.setgauge(SampSize);
	P3.setgauge(SampSize);
	F1.setgauge(SampSize);
	F1.set(Density, Dia1, Dia2);

	P1.avgdata();
	P2.avgdata();
	P3.avgdata();
	F1.avgdata();

	cout << "Pressure Gage 1 average =" << P1.getAvgdata() << endl
		<< "Pressure Gage 2 average =" << P2.getAvgdata() << endl
		<< "Pressure Gage 3 average =" << P3.getAvgdata() << endl
		<< "Flow Meter 1 average =" << F1.getAvgdata() << endl;
	 
	F1.veloc();
	F1.Area();
	F1.volflow();
	F1.massflow();

	cout << "Liquid Velocity =" << F1.getVelocity() << endl
		<< "Volumetric Flow =" << F1.getVolflow() << endl
		<< "Mass Flow =" << F1.getMassflow() << endl;

	return;

}

/*void AvgDataSwitch()
{
	int a;
	int option;

	do
	{
	// NOT USING OBJECTS
		
		cout << "Enter how many samples you want per minute" << endl;
		cin >> sampleSize;
		if (sampleSize > MaxSampSize)
		{
			cout << "Invalid sample size try agian" << endl;
		}
		else
		{
			cout << "Enter 1 to continue" << endl;
			cin >> a;
		}
	} while (a != 1);

	do
	{
		cout << "Pick one of the following option for more Data, \n"
			<< "1 - Pressure gauge 1, \n"
			<< "2 - Pressure gauge 2, \n"
			<< "3 - Pressure gauge 3, \n"
			<< "4 - Flow rate gauge, \n"
			<< "5 - If you want to exit, \n"
			<< "Enter which data you want, \n";

		cin >> option;
		cout << endl;

		switch (option)
		{
		case 1:
// NOT USING MEMBER FUNCTIONS
			cout << endl << "the average presseure from gauge 1 is: \n" << endl << avgdata(pressure1, sampleSize) << endl << endl;
			break;
		case 2:
			cout << endl << "the average presseure from gauge 2 is: \n" << endl << avgdata(pressure2, sampleSize) << endl << endl;
			break;
		case 3:
			cout << endl << "the average presseure from gauge 3 is: \n" << endl << avgdata(pressure3, sampleSize) << endl << endl;
			break;
		case 4:
			cout << endl << "the average flow rate is: \n" << endl << avgdata(flow, sampleSize) << endl << endl;
			break;
		case 5:
			cout << "you have exited" << endl;
			break;
		default:
			cout << "invalid input, \n" << endl;

		}
	} while (option != 5);

	return;

}*/

/*void FileExport()
{
	char outFileName[16];
	ofstream outStream;
	cout << "Enter file to export to (maximun 15 characters): \n";
	cin >> outFileName;
	cout << endl << "Data will export to file " << outFileName << endl;

	outStream.open(outFileName);
	if (outStream.fail())
	{
		cout << "Output file opening failed.\n";
		char wait;
		cin >> wait;
		exit(1);
	}

	outStream << "Gauge ," << "P1 ," << "P2 ," << "P3 ," << "F1 ," << endl
		<< "Average ," << avgdata(pressure1, sampleSize) << "," << avgdata(pressure2, sampleSize) << ","
		<< avgdata(pressure3, sampleSize) << "," << avgdata(flow, sampleSize) << endl;
	for (int i = 0; i < sampleSize; i++)
	{
		outStream << SampleTime[i] << "," << pressure1[i] << "," << pressure2[i] << "," << pressure3[i] << ","
			<< flow[i] << endl;
	}
	
	return;
}*/

void genArray()
{
	char opt;
	int numSamples = 4;
	double samplePeriod = .0025;
	double randSamples[10], averages[10] = { 20, 20, 20, 2.5 }, ranges[10] = { 15,15,15,1.5 };

	/*cout << "Number of samples to generate (<= 10):";
	cin >> numSamples;
	for (int i = 0; i < numSamples; i++)
	{
		cout << "Average of value " << i << ": ";
		cin >> averages[i];
		cout << "Range of value " << i << ": ";
		cin >> ranges[i];
	}
	cout << "Sample period (in sec):";
	cin >> samplePeriod;*/
	long int currentTime = static_cast<long int>(time(0)); //Generate random seed
	srand(currentTime);


	cout << "Enter any key to start \n";
	cin >> opt;
	for (int i = 0; i < MaxSampSize; i++)
	{
		
		genData(randSamples, averages, ranges, numSamples, samplePeriod);

		P1.setArrayValue(i,randSamples[0]);
		P2.setArrayValue(i,randSamples[1]);
		P3.setArrayValue(i,randSamples[2]);
		F1.setArrayValue(i, randSamples[3]);

		/*double CurrentWL, CurrentWP, CurrentFR;

		if (CurrentWL < systemAlarms.WaterLevel)
		{
			cout << "ALARM LOW WATER LEVEL \n";
		}

		if (CurrentWP > systemAlarms.WaterPressure)
		{
			cout << "ALARM HIGH WATER PRESSURE \n";
		}

		if (CurrentFR < systemAlarms.FlowRate)
		{
			cout << "ALARM LOW FLOW RATE \n";
		}*/

	}

}

void gentime()
{
	
	
	
	
	return;
}

void genData(double data[], double avgVal[], double rangeVal[], int numVal, double period)
{

	clock_t goal, now;
	now = CLOCKS_PER_SEC;
	now = clock();
	goal = static_cast<clock_t>(1000 * period) * CLOCKS_PER_SEC / 1000;
	while (goal > clock() - now)
		;
	for (int i = 0; i < numVal; i++)
	{
		data[i] = avgVal[i] - rangeVal[i] / 2 + (rand() % 1000)*rangeVal[i] / 1000; // assign random numbers
	}


}



