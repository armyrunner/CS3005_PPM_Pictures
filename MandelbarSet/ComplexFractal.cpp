
#include "PPM.h"
#include "ComplexFractal.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "math.h"


ComplexFractal::ComplexFractal( ):ThreadedGrid(){

	 mDeltaX = .01;
	 mDeltaY = .01;
	 mMaxX = 1.5;
	 mMinX = -1.5;
	 mMaxY = 1.0;
	 mMinY = -1.0;

}

ComplexFractal::ComplexFractal( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y ): ThreadedGrid(height, width){
	 mDeltaX = .01;
	 mDeltaY = .01;
	 mMaxX = max_x;
	 mMinX = min_x;
	 mMaxY = max_y;
	 mMinY = min_y;

}


ComplexFractal::~ComplexFractal( ){}


double ComplexFractal::getMinX( ) const{
	
		return mMinX;

}

double  ComplexFractal::getMaxX( ) const{

	return mMaxX;
}

double ComplexFractal::getMinY( ) const{
	
		return mMinY;

}

double ComplexFractal::getMaxY( ) const{
	
		return mMaxY;

}

void ComplexFractal::setGridSize( const int& height, const int& width ){

	if (height >= 2.0 && width >= 2.0){
	
		NumberGrid::setGridSize(height, width);
		double gap_x = calculateDeltaX();
		double gap_y = calculateDeltaY();
		setDeltas(gap_x,gap_y);
	}
}

void ComplexFractal::setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y ){

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

double ComplexFractal::getDeltaX( ) const{

		return mDeltaX;

}

double ComplexFractal::getDeltaY( ) const{

		return mDeltaY;
}

void ComplexFractal::setDeltas( const double& delta_x, const double& delta_y ){

 	if (delta_x > 0 && delta_y > 0){
		mDeltaX = delta_x;
		mDeltaY = delta_y;
	}

}

double ComplexFractal::calculateDeltaX( ) const{

	double gap_x = (mMaxX - mMinX) / (NumberGrid::getWidth() - 1);

	return gap_x;

}

double ComplexFractal::calculateDeltaY( ) const{

	double gap_y = (mMaxY - mMinY) / (NumberGrid::getHeight() - 1);

	return gap_y;


}

double ComplexFractal::calculatePlaneXFromPixelColumn( const int& column ) const{



	if(column < 0 || column > NumberGrid::getWidth()-1){
		return 0;
	}
	else{
		double x = mMinX + column * this->getDeltaX();
		return x;
	}
		
}

double ComplexFractal::calculatePlaneYFromPixelRow(const int &row) const{
	

	if (row < 0 || row > NumberGrid::getHeight()-1)
	{

		return 0;
	}else{

		double yPlane = mMaxY-row * this->getDeltaY();
		return yPlane;
	}

	
}

void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const{

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
