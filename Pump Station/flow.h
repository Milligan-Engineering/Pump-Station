#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Guage.h"
using namespace std;

class flow : public Guage 
{
public:
	flow(double density, double Diameter1, double Diameter2);
	double veloc(double avgpress, double density, double dia1, double dia2);
	double volflow(double area, double velocity);
	double massflow(double volflow, double density);
	//void set(double density, double dai1, double dai2);
	//this to initialize density ,the first diameter and second diameter
	double getDiameter1();
	double getDensity();
	double getDiameter2();
// Need mutator functions
private:
	double D1, D2, density ,velocity,MassFlow,VolFlow;

};
