// File name: Pump station
// Author: John Cole
// Email Address: jdcole@my.milligan.edu
// Project Milestone: 5
// Description: Control and measure pump flow station
// Last Changed: Febuary 26, 2018



#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>

using namespace std;

double avgdata(double dataArray[], int arraysize);
//precondition: array for the gauge passed through data array and sample size of the data array 
//postcondition: we should get the average data of the specified data array returned through avgdata
const int pgauge1=15, pgauge2=15, pgauge3=15, fgauge=15;// max array size
double pressure1[pgauge1] = { 3.6,6.8,5,2.4,9.4,5,8.5,4.5,7.2,9.5,22,4.5,2,15,6.5};
double pressure2[pgauge2] = {3.9,2.2,8.9,5.6,4.2,5,6,4,5,8,5,5.5,10,4.5,6.3};
double pressure3[pgauge3] = {1.5,6.5,4.3,8.6,7.6,5.4,8,2.5,2.7,6.5,10,2,5,8,9};
double flow[fgauge] = {1.2,7.5,8,6.5,9.4,7.6,8.5,4,5,7.6,8,15,16,2,6.5};
int time, sampleSize1, sampleSize2, sampleSize3, sampleSize4;
double sum,avgdata1;



int main()
{
	
	// Provide space for the following information 
	string date;
	string project;
	string Class;
	double density;
	double volumeOfcontainer;
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
		cout << endl << "user " << i+1 << " is " << user[i] << endl << endl;

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

	int option;
	double samples;

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
			int a;
			do
			{
				cout << "Enter how many samples you want per minute" << endl;
				cin >> sampleSize1;
				if (sampleSize1 > pgauge1)
				{
					cout << "Invalid sample size try agian" << endl;
				}
				else
				{
					cout << "Enter 1 to continue" << endl;
					cin >> a;
				}
			} while (a != 1);
			cout << endl << "the average presseure from gauge 1 is: \n" << endl << avgdata(pressure1,sampleSize1)<<endl<<endl;
			break;
		case 2:
			int b;
			do
			{
				cout << "Enter how many samples you want per minute" << endl;
				cin >> sampleSize2;
				if (sampleSize2 > pgauge2)
				{
					cout << "Invalid sample size try agian" << endl;
				}
				else
				{
					cout << "Enter 1 to continue" << endl;
					cin >> b;
				}
			} while (b != 1);
			cout << endl << "the average presseure from gauge 2 is: \n" << endl << avgdata(pressure2, sampleSize2) << endl << endl;
			break;
		case 3:
			int c;
			do
			{
				cout << "Enter how many samples you want per minute" << endl;
				cin >> sampleSize3;
				if (sampleSize3 > pgauge3)
				{
					cout << "Invalid sample size try agian" << endl;
				}
				else
				{
					cout << "Enter 1 to continue" << endl;
					cin >> c;
				}
			} while (c != 1);
			cout << endl << "the average presseure from gauge 3 is: \n" << endl << avgdata(pressure3, sampleSize3) << endl << endl;
			break;
		case 4:
			int d;
			do
			{
				cout << "Enter how many samples you want per minute" << endl;
				cin >> sampleSize4;
				if (sampleSize4 > fgauge)
				{
					cout << "Invalid sample size try agian" << endl;
				}
				else
				{
					cout << "Enter 1 to continue" << endl;
					cin >> d;
				}
			} while (d != 1);
			cout << endl << "the average flow rate is: \n" << endl << avgdata(flow, sampleSize4) << endl << endl;
			break;
		case 5:
			cout << "you have exited" << endl;
			break;
		default:
			cout << "invalid input, \n" << endl;
			
		}
	} while (option != 5);
	cout << endl;
	cout << "enter density of liquid" << endl << endl;
	cin >> density;  //pounds per cubic feet
	cout << " lb/ft^3" << endl << endl;

	cout << "enter volume of the container" << endl << endl;
	cin >> volumeOfcontainer;	//cubic feet
	cout << " ft^3" << endl << endl;


	double mass;	//pounds
	mass = density * volumeOfcontainer;
	cout << "The mass is : " << mass << " lbs" << endl <<endl; 

	int waterlevel,currentwaterlevel;  //measured in inches from the bottom of the tank
	waterlevel = 23;
	
	cout << "enter current water level " << endl << endl;
	cin >> currentwaterlevel; 
	cout << endl;

	if (currentwaterlevel < 23)
		cout << "WANRING LOW WATER LEVEL" << endl;

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

	return(0);

	

	


}

double avgdata(double dataArray[], int arraysize)
{
	int i;
	
	for (i = 0; i < arraysize; i++)
	{
		sum = pressure1[i] + pressure1[i + 1];
		pressure1[i + 1] = sum;
	}
	avgdata1 = sum / arraysize;
	return(avgdata1);
}
