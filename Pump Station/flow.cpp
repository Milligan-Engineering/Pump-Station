#include "flow.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

double flow::veloc(double avgpress, double density, double dia1, double dia2)
{
	double numerator, denomenator, velocity;
	numerator = 2 * avgpress;
	denomenator = density * (1 - pow((dia1 / dia2),4));
	velocity = sqrt(numerator / denomenator);

	return(velocity);
}

double flow::volflow(double area, double velocity)
{
	double product,
		product = area * velocity;

	return(product);
}

double flow::massflow(double volflow, double density)
{
	double product;
	product = volflow * density;

	return(product);
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



flow::flow(double density,double Diameter1,double Diameter2)
{
}
