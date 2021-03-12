#include "NumberGrid.h"
#include "PPM.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "JuliaSet.h"
#include "math.h"

JuliaSet::JuliaSet()
	: NumberGrid(200, 300)
{

	 mA = -0.650492;
	 mB = -0.478235;
	 mDeltaX = .01;
	 mDeltaY = .01;
	 mMaxX = 1.5;
	 mMinX = -1.5;
	 mMaxY = 1.0;
	 mMinY = -1.0;
}

JuliaSet::JuliaSet(const int &height, const int &width, const double &min_x, const double &max_x, const double &min_y, const double &max_y, const double &a, const double &b)
	: NumberGrid(height, width)
{

	 mA = a;
	 mB = b;
	 mDeltaX = .01;
	 mDeltaY = .01;
	 mMaxX = max_x;
	 mMinX = min_x;
	 mMaxY = max_y;
	 mMinY = min_y;
}

JuliaSet::~JuliaSet() {}

double JuliaSet::getMinX() const
{
	return mMinX;
}

double JuliaSet::getMaxX() const
{
	return mMaxX;
}

double JuliaSet::getMinY() const
{
	return mMinY;
}

double JuliaSet::getMaxY() const
{
	return mMaxY;
}

double JuliaSet::getA() const
{
	return mA;
}

double JuliaSet::getB() const
{
	return mB;
}

void JuliaSet::setGridSize(const int &height, const int &width)
{
	if (height >= 2.0 && width >= 2.0)
	{
	
		NumberGrid::setGridSize(height, width);
		double gap_x = calculateDeltaX();
		double gap_y = calculateDeltaY();
		setDeltas(gap_x,gap_y);
	}
}

void JuliaSet::setPlaneSize(const double &min_x, const double &max_x, const double &min_y, const double &max_y)
{
	if (min_x >= -2.0 && min_x <= 2.0 && min_y >= -2.0 && min_y <= 2.0 && max_x >= -2.0 && max_x <= 2.0 && max_y >= -2.0 && max_y <= 2.0 && min_x != max_x && min_y != max_y)
	{
		
		if (min_x > max_x)
		{

			mMaxX = min_x;
			mMinX = max_x;
		}
		else
		{

			mMaxX = max_x;
			mMinX = min_x;
		}
		if (min_y > max_y)
		{

			mMaxY = min_y;
			mMinY = max_y;
		}
		else
		{

			mMaxY = max_y;
			mMinY = min_y;
		}

		double gap_x = calculateDeltaX();
		double gap_y = calculateDeltaY();
		setDeltas(gap_x,gap_y);
	
	}
}

void JuliaSet::setParameters(const double &a, const double &b)
{
	if (a <= 2.0 && a >= -2.0 && b >= -2.0 && b <= 2.0)
	{
		mA = a;
		mB = b;
	}
}

double JuliaSet::getDeltaX() const
{

	return mDeltaX;
}

double JuliaSet::getDeltaY() const
{
	return mDeltaY;
}

void JuliaSet::setDeltas(const double &delta_x, const double &delta_y)
{

	if (delta_x > 0 && delta_y > 0)
	{
		mDeltaX = delta_x;
		mDeltaY = delta_y;
	}
}

double JuliaSet::calculateDeltaX() const
{

	double gap_x = (mMaxX - mMinX) / (NumberGrid::getWidth() - 1);

	return gap_x;
}

double JuliaSet::calculateDeltaY() const
{
	double gap_y = (mMaxY - mMinY) / (NumberGrid::getHeight() - 1);

	return gap_y;
}

double JuliaSet::calculatePlaneYFromPixelRow(const int &row) const
{
	

	if (row < 0 || row > NumberGrid::getHeight()-1)
	{

		return 0;
	}else{

		double yPlane = mMaxY-row * this->getDeltaY();
		return yPlane;
	}

	
}

double JuliaSet::calculatePlaneXFromPixelColumn(const int &column) const
{

	if(column < 0 || column > NumberGrid::getWidth()-1){
		return 0;
	}
	else{
		double x = mMinX + column * this->getDeltaX();
		return x;
	}

	
}

void JuliaSet::calculatePlaneCoordinatesFromPixelCoordinates(const int &row, const int &column, double &x, double &y) const
{

	if ( row < 0 || row >= NumberGrid::getHeight() || column < 0 || column >= NumberGrid::getWidth())
	{
		
		x = 0;
		y = 0;
	
	}

	else{

		x = calculatePlaneXFromPixelColumn(column);
		y = calculatePlaneYFromPixelRow(row);
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
	
	

	
