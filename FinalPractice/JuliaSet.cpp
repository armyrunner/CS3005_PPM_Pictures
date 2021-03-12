#include "ComplexFractal.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "JuliaSet.h"
#include "math.h"

JuliaSet::JuliaSet()
	:ComplexFractal(){

	mA = -0.650492;
	mB = -0.478235;
}

JuliaSet::JuliaSet(const int &height, const int &width, const double &min_x, const double &max_x, const double &min_y, const double &max_y, const double &a, const double &b)
	:ComplexFractal(height, width,min_x,max_x,min_y,max_y)
{

	 mA = a;
	 mB = b;
	}

JuliaSet::~JuliaSet() {}


double JuliaSet::getA() const
{
	return mA;
}

double JuliaSet::getB() const
{
	return mB;
}

void JuliaSet::setParameters(const double &a, const double &b)
{
	if (a <= 2.0 && a >= -2.0 && b >= -2.0 && b <= 2.0)
	{
		mA = a;
		mB = b;
	}
}

void JuliaSet::calculateNextPoint(const double x0, const double y0, double &x1, double &y1) const
{
	x1 = x0*x0 - y0*y0 +mA;
	y1 = 2*x0*y0 +mB;
}

int JuliaSet::calculatePlaneEscapeCount(const double &x0, const double &y0) const
{
	int escapeCount = 0;
	double x1;
	double y1;
	double xp = x0;
	double yp = y0;
	double d = std::sqrt(pow(xp,2) + pow(yp,2));
	while(d <= 2 && escapeCount <= NumberGrid::getMaxNumber()-1 ){

		calculateNextPoint(xp,yp,x1,y1);
		escapeCount += 1;
		xp = x1;
		yp = y1;

		d = std::sqrt(pow(xp,2) + pow(yp,2));
	}

	return escapeCount;
}

int JuliaSet::calculateNumber(const int &row, const int &column) const
{

	if ( row < 0 || row > ((NumberGrid::getHeight()) -1) || column < 0 || column > ((NumberGrid::getWidth()) -1))
	{
		return -1;
	}

	double x = calculatePlaneXFromPixelColumn(column);
	double y = calculatePlaneYFromPixelRow(row);
	int escapeCount = calculatePlaneEscapeCount(x,y);

	return escapeCount;
}
	
	

	
