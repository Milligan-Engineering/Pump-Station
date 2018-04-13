#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Gauge.h"
using namespace std;

class flow : public Gauge 
{
public:
	double veloc(double avgpress, double density, double dia1, double dia2);
	double volflow(double area, double velocity);
	double massflow(double volflow, double density);
	//void set(double density, double dai1, double dai2);
	flow(double density, double Diameter1, double Diameter2);
	//this to initialize density ,the first diameter and second diameter
	double getDiameter1();
	double getDensity();
	double getDiameter2();

private:
	double D1, D2, density ,velocity,MassFlow,VolFlow;

};

