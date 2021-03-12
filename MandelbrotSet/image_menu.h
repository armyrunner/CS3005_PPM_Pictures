#ifndef _IMAGE_MENU_H_
#define _IMAGE_MENU_H_

#include <iostream>
#include <string>
#include <cmath>
#include "PPM.h"
#include "NumberGrid.h"
#include "JuliaSet.h"
#include "MandelbrotSet.h"


std::string getString( std::istream& is, std::ostream& os, const std::string& prompt );
int getInteger( std::istream& is, std::ostream& os, const std::string& prompt );
double getDouble( std::istream& is, std::ostream& os, const std::string& prompt );
int assignment1( std::istream& is, std::ostream& os );

// add to the file on 9/6/2019  to include the following new functions
void writeUserImage ( std::istream& is, std::ostream& os, const PPM& p);
int assignment2( std::istream& is, std::ostream& os);

// add the following on 9/9/2019 to include the following new functions
void showMenu(std::ostream& os);
std::string getChoice(std::istream& is, std::ostream& os);
void commentLine(std::istream& is);

// add the following on 9/12/2019 to include the following new fuctions
void setSize(std::istream& is, std::ostream& os, PPM& src);
void setMaxColorValue(std::istream& is, std::ostream& os, PPM& src);
void setChannel(std::istream& is, std::ostream& os, PPM& src);
void setPixel(std::istream& is, std::ostream& os, PPM& src);

void clearAll (PPM& src);
void drawDiamond(std::istream& is, std::ostream& os, PPM& src);
void drawCircle(std::istream& is, std::ostream& os, PPM& src);
void drawBox(std::istream& is, std::ostream& os, PPM& src);

// add the following on 9/13/2019 to include the following new functions
void takeAction( std::istream& is, std::ostream& os, const std::string& choice, PPM& input_image1, PPM& input_image2, PPM& output_image, NumberGrid& grid );
int imageMenu(std::istream& is, std::ostream& os);

// add the following on 9/19/2019 for new functionality
void readUserImage( std::istream& is, std::ostream& os, PPM& ppm );

// adding the following on 9/26/2019

void plusEquals( std::istream& is, std::ostream& os, PPM& src1, const PPM& src2 );
void minusEquals( std::istream& is, std::ostream& os, PPM& src1, const PPM& src2 );
void timesEquals( std::istream& is, std::ostream& os, PPM& src );
void divideEquals( std::istream& is, std::ostream& os, PPM& src );
void plus( std::istream& is, std::ostream& os, const PPM& src1, const PPM& src2, PPM& dst );
void minus( std::istream& is, std::ostream& os, const PPM& src1, const PPM& src2, PPM& dst );
void times( std::istream& is, std::ostream& os, const PPM& src, PPM& dst );
void divide( std::istream& is, std::ostream& os, const PPM& src, PPM& dst );

// new functionality on 10/04/2019
int runFile( std::istream& is, std::ostream& os, PPM& input_image1, PPM& input_image2, PPM& output_image );
int imageMenu( std::istream& is, std::ostream& os );

// new functionality on 10/11/209

void configureGrid( std::istream& is, std::ostream& os, NumberGrid& grid );
void setGrid( std::istream& is, std::ostream& os, NumberGrid& grid );
void applyGrid( std::istream& is, std::ostream& os, NumberGrid& grid, PPM& dst );

// new functionality on 10/30/19

void setFractalPlaneSize( std::istream& is, std::ostream& os, NumberGrid& grid );
void calculateFractal( std::istream& is, std::ostream& os, NumberGrid& grid );
void setJuliaParameters( std::istream& is, std::ostream& os, NumberGrid& grid );

// new functionality 11/5/19
void setJuliaFractal( std::istream& is, std::ostream& os, NumberGrid*& grid );
void setMandelbrotFractal( std::istream& is, std::ostream& os, NumberGrid*& grid );


#endif /*_IMAGE_MENU_H_*/