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
	void set(double density, double Diameter1, double Diameter2);
	double veloc();
	double Area();
	double volflow();
	double massflow();
	//void setDen()
	//this to initialize density ,the first diameter and second diameter
	double getDiameter1();
	double getDensity();
	double getDiameter2();
	double getVelocity();
	double getMassflow();
	double getVolflow();
// Need mutator functions
private:
	double D1, D2, density ,velocity,MassFlow,VolFlow, area;

};

