#ifndef _burningship_H_
#define _burningship_H_

#include "MandelbrotSet.h"

class Burningship: public MandelbrotSet{
		
	public:	
		Burningship();
		Burningship(const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y);
		virtual ~Burningship();
		virtual void calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double& y1 ) const;

};

#endif /* _burningship_H_*/