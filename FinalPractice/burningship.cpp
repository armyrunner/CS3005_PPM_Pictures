#include "burningship.h"		
#include "math.h"

Burningship::Burningship():MandelbrotSet(){

}
Burningship::Burningship(const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y):MandelbrotSet(height,width,min_x,max_x,min_y,max_y){

}
Burningship::~Burningship(){

}
void Burningship::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double& y1 ) const{

    x1 = x0*x0 - y0*y0 - a;
	y1 = 2*std::abs(x0*y0 ) - b;

}

