#include "flow.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

double flow::veloc()
{
	Gauge F1;
	double numerator, denomenator, velocity;
	numerator = 2 * F1.getAvgdata();
	denomenator = density * (1 - pow((D1 / D2),4));
	velocity = sqrt(numerator / denomenator);

	return(velocity);
}

double flow::Area()
{
	area = (3.14159265 * pow(D2, 2)) / 2;

	return(area);
}

double flow::volflow()
{
		VolFlow = area * velocity;

	return(VolFlow);
}

double flow::massflow()
{
	
	MassFlow = VolFlow * density;

	return(MassFlow);
}

double flow::getDiameter1()
{
	return D1;
}

double flow::getDiameter2()
{ 
	return D2;
}

double flow::getDensity()
{
	return density;
}



void flow::set(double Density,double Diameter1,double Diameter2)
{
	density = Density;
	D1 = Diameter1;
	D2 = Diameter2; 

	return;
}

double flow::getVelocity()
{
	return velocity;
}

double flow::getMassflow()
{
	return MassFlow;
}

double flow::getVolflow()
{
	return VolFlow;
}