#include "ComplexFractal.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "MandelbrotSet.h"
#include "math.h"

MandelbrotSet::MandelbrotSet()
 :ComplexFractal(){
}

MandelbrotSet::MandelbrotSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y )
 :ComplexFractal(height,width,min_x,max_x,min_y,max_y){

}

MandelbrotSet::~MandelbrotSet( ){}

void MandelbrotSet::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const{

	x1 = x0*x0 - y0*y0 + a;
	y1 = 2*x0*y0 + b;
}


int MandelbrotSet::calculatePlaneEscapeCount(const double& a, const double& b  ) const{

	int escapeCount = 0;
	double x1;
	double y1;
	double xp = 0;
	double yp = 0;

	double d = std::sqrt(pow(xp,2) + pow(yp,2));

	while(d <= 2 && escapeCount <= NumberGrid::getMaxNumber()-1){


		calculateNextPoint(xp,yp,a,b,x1,y1);

		xp = x1;
		yp = y1;

		d = std::sqrt(pow(xp,2) + pow(yp,2));

		if (d <= 2){
			escapeCount += 1;

		}
	}

	return escapeCount;
}

int MandelbrotSet::calculateNumber( const int& row, const int& column ) const{

	if ( row < 0 || row > ((NumberGrid::getHeight()) -1) || column < 0 || column > ((NumberGrid::getWidth()) -1))
	{
		return -1;
	}

	double x = ComplexFractal::calculatePlaneXFromPixelColumn(column);
	double y = ComplexFractal::calculatePlaneYFromPixelRow(row);
	int escapeCount = calculatePlaneEscapeCount(x,y);

	return escapeCount;

}









