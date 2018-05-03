// File name: Pump station
// Author: John Cole
// Email Address: jdcole@my.milligan.edu
// Project Milestone: Final
// Description: Control and measure pump flow station
// Last Changed: May 2, 2018

#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "Gauge.h"
#include "flow.h"
#include <time.h>   

using namespace std;

void StudentProgram();
void TeacherSettings();
// inputs default setitings
void StudentSetup();
// students name ,date ,class
void SystemControl(); 
// truns system on 
void DataOptions();
// User inputs general data
void genArray();
// generates array for gauge data
void FileExport();

const int maxUsers = 4;

void genData(double data[], double avgVal[], double rangeVal[], int numVal, double period);
//Preconditions: The high and low values of the generated data are given in highVal and lowVal
//				The number of random values generated is given in samples.
//				The properly sized array, data, should be declared.
//				The interval between samples is given in period in seconds.
//Postcondtions: Uniform random numbers are stored in data at an interval given by rate.
struct Student
{
	string date;
	string project;
	string Class;
	string user[maxUsers];
	int numUsers;
};

Student systemSetup;

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

int main()
{
	char opt;
	TeacherSettings();
	StudentProgram();
	FileExport();
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

void TeacherSettings() 
{
	char inFileName[16];

	ifstream inStream;
	
	cout << "Enter in the file you wish to import (maximum of 15 characters): \n";
	cin >> inFileName;
	strcat_s(inFileName, ".txt");

	inStream.open(inFileName);
	if (inStream.fail())
	{
		cout << "Input file opening failed. \n";
		char wait;
		cin >> wait;
		exit(1);
	}
	
	inStream >> systemAlarms.WaterLevel >> systemAlarms.WaterPressure >> systemAlarms.FlowRate;
	
	inStream.close();
	return;
}

void StudentSetup()
{
	do
	{
		cout << "enter number of users (between 1-4) " << endl << endl;
		cin >> systemSetup.numUsers;
		cout << endl;
	} while ((systemSetup.numUsers <= 0) || (systemSetup.numUsers >= 5));

	int i = 0;

	while (i < systemSetup.numUsers)
	{
		cout << "enter username (no spaces)" << endl << endl;
		cin >> systemSetup.user[i];
		cout << endl << "user " << i + 1 << " is " << systemSetup.user[i] << endl << endl;

		i++;

	}


	cout << "enter date" << endl << endl;
	cin >>systemSetup.date;
	cout << endl;

	cout << "enter project name(no spaces)" << endl << endl;
	cin >> systemSetup.project;
	cout << endl;

	cout << "enter class name(no spaces)" << endl << endl;
	cin >> systemSetup.Class;
	cout << endl;
	
	char j;
	
	do
	{	
		cout << "Would you like to use default alarm settings or enter in your own? \n"
			<< "Enter 1 for Default \n"
			<< "Enter 2 for Manual inputs \n";
		cin >> j;

		if (j == '1')
		{
			cout << "Alarms set to default \n";
		}
		else if(j == '2')
		{
			do
			{
				cout << "Enter Low Water Level Alarm \n";
				cin >> systemAlarms.WaterLevel;
			} while (systemAlarms.WaterLevel <= 9 && systemAlarms.WaterLevel >= 23);

			do
			{
				cout << endl << "Enter High Water Pressure Alarm \n";
				cin >> systemAlarms.WaterPressure;
			} while (systemAlarms.WaterPressure < 30);

			do
			{
				cout << endl << "Enter Low Flow Rate Alarm \n";
				cin >> systemAlarms.FlowRate;
			} while (systemAlarms.FlowRate > 0.5);
		}
	} while (j != '1' && j != '2');

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
		terminate();
	}
	
	genArray();
	

	return;

}

void DataOptions()
{
	double Density, Dia1, Dia2;

	do
	{
		cout << "Enter the outer Diameter \n";
		cin >> Dia1;
	} while (Dia1 <= 0 && Dia1 > 3);

	do
	{
		cout << endl << "Enter the inner Diameter \n";
		cin >> Dia2;
	} while (Dia2 <= 0 && Dia2 >= Dia1);

	do
	{
		cout << endl << "Enter the liquid density \n";
		cin >> Density;
	} while (Density <= 0);

	Density = Density * (0.000578704);

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

void FileExport()
{
	char outFileName[16];
	ofstream outStream;
	cout << "Enter file to export to (maximun 15 characters): \n";
	cin >> outFileName;
	strcat_s(outFileName, ".csv");
	cout << endl << "Data will export to file " << outFileName << endl;

	outStream.open(outFileName);
	if (outStream.fail())
	{
		cout << "Output file opening failed.\n";
		char wait;
		cin >> wait;
		exit(1);
	}
	
	outStream << "Users ,";
	for (int i = 0; i < systemSetup.numUsers; i++)
	{
		outStream << systemSetup.user[i] << ",";
	}

	outStream <<endl<<"Date ," << systemSetup.date << endl << "Class Name ," << systemSetup.Class << endl<< "Project Name ," << systemSetup.project <<endl
		<< "P1 Average ," << P1.getAvgdata() << ", PSI"<< endl << "P2 Average," << P2.getAvgdata() << ", PSI" << endl << "P3 Average ," << P3.getAvgdata() << ", PSI" << endl
		<< "F1 Average," << F1.getAvgdata() << ", PSI" << endl << "Velocity ," << F1.getVelocity()<< ", ft/sec^2" << endl << "Volumetric Flow ," << F1.getVolflow() << ", ft^3/sec" << endl
		<<"Mass Flow ," << F1.getMassflow()<<", lbm/sec"<< endl<< endl<<"Sample Number ,"<<"P1 ,"<< "P2 ," << "P3 ," <<"F1"<<endl;

	for (int i = 0; i < P1.getSampSize() ; i++)
	{
		outStream << i+1 << "," << P1.getDataArray(i) << "," << P2.getDataArray(i) << "," << P3.getDataArray(i) << ","
			<< F1.getDataArray(i) << endl;
	}
	
	return;
}

void genArray()
{
	char opt;
	int SampSize,numSamples = 4;
	double runtime, samplePeriod;
	double randSamples[10], averages[10] = { 28, 28, 28, 2.0 }, ranges[10] = { 15,15,15,2.2 };

	/*cout << "Number of samples to generate (<= 10):";
	cin >> numSamples;
	for (int i = 0; i < numSamples; i++)
	{
		cout << "Average of value " << i << ": ";
		cin >> averages[i];
		cout << "Range of value " << i << ": ";
		cin >> ranges[i];
	}*/
	do
	{
		cout << "Sample period (in sec):";
		cin >> samplePeriod;
	} while (samplePeriod <= 0);

	do
	{
		cout << endl << "Enter run time (in sec):";
		cin >> runtime;
	} while (runtime <= 0);

	SampSize = runtime / samplePeriod;
	P1.setgauge(SampSize);
	P2.setgauge(SampSize);
	P3.setgauge(SampSize);
	F1.setgauge(SampSize);

	long int currentTime = static_cast<long int>(time(0)); //Generate random seed
	srand(currentTime);

	cout << "Enter any key to start \n";
	cin >> opt;
	for (int i = 0; i < SampSize; i++)
	{
		
		genData(randSamples, averages, ranges, numSamples, samplePeriod);

		P1.setArrayValue(i,randSamples[0]);
		P2.setArrayValue(i,randSamples[1]);
		P3.setArrayValue(i,randSamples[2]);
		F1.setArrayValue(i, randSamples[3]);

		
		
		if (randSamples[0] > systemAlarms.WaterPressure)
		{
			cout << i+1 << ":ALARM P1 HIGH WATER PRESSURE \n";
		}
		if(randSamples[1] > systemAlarms.WaterPressure)
		{
			cout << i + 1 << ":ALARM P2 HIGH WATER PRESSURE \n";
		}
		if(randSamples[2] > systemAlarms.WaterPressure)
		{
			cout << i + 1 << ":ALARM P3 HIGH WATER PRESSURE \n";
		}
		if(randSamples[3] < systemAlarms.FlowRate)
		{
			cout << i+1 << ":ALARM F1 LOW FLOW RATE \n";
		}
		
		else
		{
			cout << i + 1 << "\r";
		}


	}

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



