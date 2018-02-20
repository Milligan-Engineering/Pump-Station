// File name: Pump station
// Author: John Cole
// Email Address: jdcole@my.milligan.edu
// Project Milestone: 3
// Description: Control and measure pump flow station
// Last Changed: January 31, 2018



#include <iostream>
#include <string>
using namespace std;


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
	do {
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

// Indicate that date, project name and class name can not have spaces
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

	cout << "Pick one of the following option for more Data, \n"
		<< "1 - Pressure gauge 1, \n"
		<< "2 - Pressure gauge 2, \n"
		<< "3 - Pressure gauge 3, \n"
		<< "4 - Flow rate gauge, \n"
		<< "Enter which data you want, \n";
	cin >> option;
	cout << endl;
	switch (option)
	{
	case 1:
		cout << "data for pressure gauge 1, \n";
		break;
	case 2:
		cout << "data for pressure gauge 2, \n";
		break;
	case 3: 
		cout << "data for pressure gauge 3, \n";
		break;
	case 4:
		cout << "data for flow rate gauge, \n";
		break;
	default:
		cout << "you sure you do not want any data, \n";
	}
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

	return(0);

	

	


}