
#ifndef _MandelbrotSet_H_
#define _MandelbrotSet_H_

#include "ComplexFractal.h"
#include "PPM.h"
#include "NumberGrid.h"

class MandelbrotSet: public ComplexFractal{
		
	public:	
		MandelbrotSet();
		MandelbrotSet(const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y);
		virtual ~MandelbrotSet();
		virtual void calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double& y1 ) const;
		int calculatePlaneEscapeCount( const double& a, const double& b)const;
		virtual int calculateNumber ( const int & row, const int& column) const;

};

class MandelbarSet: public MandelbrotSet{
		
	public:	
		MandelbarSet();
		MandelbarSet(const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y);
		virtual ~MandelbarSet();
		virtual void calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double& y1 ) const;
		

};


#endif /* _Mandelbrot_H_*/


