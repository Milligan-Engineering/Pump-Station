// Filename: genData.cpp 
// Author: JJ Giesey
//Email: jjgiesey@milligan.edu
//Project: PumpStaion
//Description: Generates simulated data 
//Last Modified: 04/11/18


#include <iostream>
#include <time.h>
#include <math.h>


using namespace std;

void genData(double data[], double avgVal[], double rangeVal[], int numVal, double period);
//Preconditions: The number of random values generated is given in numVal.
//				The average and range of each of the values is stored in arrays avgVal and rangeVal.
//				The properly sized arrays, data, avgVal, and rangeVal should be declared.
//				The interval between samples is given in period in seconds.
//Postcondtions: A set of numVal uniform random numbers are generated and stored in data.
//				After period seconds the fucntion returns.


int main()
{
	char opt;
	int numSamples;
	double samplePeriod;
	double randSamples[10], averages[10], ranges[10];
	long int currentTime = static_cast<long int>(time(0)); //Generate random seed
	srand(currentTime);

	cout << "Number of samples to generate (<= 10):";
	cin >> numSamples;
	for (int i = 0; i < numSamples; i++)
	{
		cout << "Average of value " << i << ": ";
		cin >> averages[i];
		cout << "Range of value " << i << ": ";
		cin >> ranges[i];
	}
	cout << "Sample period (in sec):";
	cin >> samplePeriod;
	cout << "Enter any key to start \n";
	cin >> opt;
	for (int i = 0; i < 100; i++)
	{
		cout << "\n" << i << ": ";
		genData(randSamples, averages, ranges, numSamples, samplePeriod);
		for (int j = 0; j < numSamples; j++)
		{
			cout << " " << randSamples[j] << ", ";
		}
	}
	return(0);
}



void genData(double data[], double avgVal[], double rangeVal[], int numVal, double period)
{

	clock_t goal, now;
	now = CLOCKS_PER_SEC;
	now = clock();
	goal = static_cast<clock_t>(1000*period) * CLOCKS_PER_SEC/1000;
	while (goal > clock() - now)
		;
	for (int i = 0; i < numVal; i++)
	{
		data[i] = avgVal[i] -rangeVal[i]/2 + (rand() % 1000)*rangeVal[i] / 1000; // assign random numbers
	}


}