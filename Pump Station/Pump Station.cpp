// File name: Pump station
// Author: John Cole
// Email Address: jdcole@my.milligan.edu
// Project Milestone: 7
// Description: Control and measure pump flow station
// Last Changed: March 14, 2018



#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

double avgdata(double dataArray[], int arraysize);
//precondition: array for the gauge passed through data array and sample size of the data array 
//postcondition: we should get the average data of the specified data array returned through avgdata
void StudentProgram();
void TeacherSettings();
void StudentSetup();
void SystemControl(); 
void DataOptions();
void AvgDataSwitch();
void FileExport();

const int MaxSampSize = 15;// max array size
double pressure1[MaxSampSize] = { 3.6,6.8,5,2.4,9.4,5,8.5,4.5,7.2,9.5,22,4.5,2,15,6.5 };
double pressure2[MaxSampSize] = { 3.9,2.2,8.9,5.6,4.2,5,6,4,5,8,5,5.5,10,4.5,6.3 };
double pressure3[MaxSampSize] = { 1.5,6.5,4.3,8.6,7.6,5.4,8,2.5,2.7,6.5,10,2,5,8,9 };
double flow[MaxSampSize] = { 1.2,7.5,8,6.5,9.4,7.6,8.5,4,5,7.6,8,15,16,2,6.5 };
int SampleTime[MaxSampSize] = { 5,10,15,20,25,30,35,40,45,50,55,60,65,70,75 };
int sampleSize, WaterLevel, WaterPressure, FlowRate;

int main()
{

	TeacherSettings();
	StudentProgram();

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

	inStream.open(inFileName);
	if (inStream.fail())
	{
		cout << "Input file opening failed. \n";
		char wait;
		cin >> wait;
		exit(1);
	}
	
	inStream >> WaterLevel >> WaterPressure >> FlowRate;
	
	inStream.close();
	return;
}

double avgdata(double dataArray[], int arraysize)
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

	double CurrentWL =27, CurrentWP =4, CurrentFR =2;
	
	if (CurrentWL < WaterLevel)
	{
		cout << "ALARM LOW WATER LEVEL ALL SYSTEMS SHUT OFF \n";
	}

	if (CurrentWP > WaterPressure)
	{
		cout << "ALARM HIGH WATER PRESSURE ALL SYSTEMS SHUT OFF \n";
	}

	if (CurrentFR < FlowRate)
	{
		cout << "ALARM LOW FLOW RATE ALL SYSTEMS SHUT OFF \n";
	}

	return;

}

void DataOptions()
{
	int option;

	do
	{
		cout << "What do you want to do with the data? \n"
			<< "Enter 1 for data analysis \n"
			<< "Enter 2 for data vizualization \n"
			<< "Enter 3 to exit program \n";
		cin >> option;

		switch (option)
		{
		case 1:
			AvgDataSwitch();
			cout << "Data Aalysis \n";
			break;
		case 2:
			cout << "Data Visualization \n";
			break;
		case 3:
			FileExport();
			cout << "program exited \n";
			break;
		default:
			cout << "invalid input \n";

		}
	} while (option != 3);

	return;

}

void AvgDataSwitch()
{
	int a;
	int option;

	do
	{
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

}

void FileExport()
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
}


